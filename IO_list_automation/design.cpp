#include <stdio.h>
#include <stdlib.h>

#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>
#include <string>

#include "libxl.h"
#include "design.h"
#include "config.h"
#include "MainWindow.h"
#include "Global_Functions.h"


using namespace libxl;
using namespace std;
using namespace IOlistautomation;

struct project_str project;


std::wstring Project_get_data_switch(int iCol, int index)
{
	wstring cell_text = L"";

	switch (iCol)
	{
	case 0:	cell_text = project.data[index].number;
		break;
	case 1:	cell_text = project.data[index].Cabinet;
		break;
	case 2:	cell_text = project.data[index].Module;
		break;
	case 3:	cell_text = project.data[index].Pin;
		break;
	case 4:	cell_text = project.data[index].Channel;
		break;
	case 5:	cell_text = project.data[index].IO_text;
		break;
	case 6:	cell_text = project.data[index].Page;
		break;
	default:cell_text = LPWSTR(L"");
		break;
	}
	return cell_text;
}
void Project_put_data_switch(int iCol, int index, std::wstring cell_text)
{
	switch (iCol)
	{
	case 0:	project.data[index].number = cell_text;
		break;
	case 1:	project.data[index].Cabinet = cell_text;
		break;
	case 2:	project.data[index].Module = cell_text;
		break;
	case 3:	project.data[index].Pin = cell_text;
		break;
	case 4:	project.data[index].Channel = cell_text;
		break;
	case 5:	project.data[index].IO_text = cell_text;
		break;
	case 6:	project.data[index].Page = cell_text;
		break;
	}
}

//check if there is data in any variable
int Project_valid_row_check(int row)
{
	if (project.data[row].number.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].Cabinet.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].IO_text.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].Module.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].Channel.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].Pin.empty() == 0)
	{
		return 1;
	}
	if (project.data[row].Page.empty() == 0)
	{
		return 1;
	}
	return 0;
}
//resize data



int Project_read_data()
{
	GlobalForm::forma->tabControl1->SelectedIndex = Design_grid_index;
	if (project.valid_entries > 1)
	{
		if (show_confirm_window(conf_design_overwrite[lang]) == IDOK)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, design_txt[lang]);			
			project.data = {};
			Global_get_width_list(Design_grid_index,project.number_collums, project.collumn_with);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write_show(err_txt);
			return 1;
		}
	}
	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = "Excel Worksheets|*.xls" +
		"|All Files|*.*";
	//importfile.FileName = "Inventory_Adjustment_Export.xls";
	if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Book* book = xlCreateBook();
		strcpy_s(info_txt, sizeof info_txt, info_excel_read_data[lang]);
		info_write(info_txt);
		const char* error_lic = "can't read more cells in trial version";
		bool fStringMatch = FALSE;

		wstring asd = system_string_to_wstring(importfile->FileName);
		const wchar_t* file_name = asd.c_str();

		if (book->load(file_name))
		{
			Sheet* sheet = book->getSheet(0);
			if (sheet)
			{
				int max_rows = sheet->lastRow();
				int max_col = sheet->lastCol();
				const wchar_t* s = L" ";
				wstring texts = L" ";
				const char* error_message = " ";

				Show_progress(prog_read_data[lang], max_rows);

				project.valid_entries = max_rows - 1;

				Global_resize_data(Design_grid_index, max_rows);

				for (int row = sheet->firstRow(); row < max_rows; ++row)
				{
					project.data[row].number = row;
					for (int col = sheet->firstCol(); col < max_col; ++col)
					{
						s = sheet->readStr(row, col);
						if (s == NULL)
						{
							texts = L"";
							error_message = book->errorMessage();
							fStringMatch = (strcmp(error_message, error_lic) == 0);
							if (fStringMatch)	// trial version walkthrough for reading					
							{
								book->release();
								book = xlCreateBook();
								book->load(file_name);
								sheet = book->getSheet(0);
								s = sheet->readStr(row, col);
								if (s == NULL)
								{
									texts = L"";
								}
								else
								{
									wstring ws(s);
									texts = ws;
								}
								if (parameters.debug)
								{
									//	strcpy_s(info_txt, sizeof info_txt, "Per nauja atidarytas excel failas kad apeiti bibliotekos licenzijavima");
									//	info_write(info_txt);
								}
							}
						}
						else
						{
							wstring ws(s);
							texts = ws;
						}
						Project_put_data_switch(col, row, texts);						
					}
					set_progress_value(row);
				}

				/*
				project.column_name.resize(max_col);
				for (int col = sheet->firstCol(); col < max_col; ++col)
				{
					switch (col)
					{
					case 0:	project.column_name[col] = LPWSTR(L"Nr.");
						break;
					case 1:	project.column_name[col] = &project.data[index].Cabinet[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 2:	project.column_name[col] = &project.data[index].Module[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 3:	project.column_name[col] = &project.data[index].Pin[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 4:	project.column_name[col] = &project.data[index].Channel[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 5:	project.column_name[col] = &project.data[index].IO_text[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 6:	project.column_name[col] = &project.data[index].Page[parameters.excel_row_nr_with_name - 1][0];
						break;
					default:project.column_name[col] = LPWSTR(L"");
						break;
					}
				}
				*/
				book->release();
			}
			else
			{
				strcpy_s(err_txt, sizeof err_txt, err_excel_no_sheet[lang]);
				err_write_show(err_txt);
				return 1;
			}
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_excel_cant_open[lang]);
			err_write_show(err_txt);
			return 1;
		}
	}
	else
	{
		strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
		err_write(err_txt);
		return 1;
	}

	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_excel_read_data[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Project_data_extract_useful_data();
	Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
	return 0;
}

void Project_data_extract_useful_data()
{
	int a = 0;
	Show_progress(prog_process_data[lang], 100);

	strcpy_s(info_txt, sizeof info_txt, info_extract_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	info_write(info_txt);

	for (int row = 0; row < parameters.excel_row_nr_with_name; ++row)
	{
		Global_delete_data_row(Design_grid_index, 0);
	}
	project.valid_entries = project.valid_entries - parameters.excel_row_nr_with_name;
	int row = project.valid_entries;

	while (row >= 0)
	{
		if (project.data[row].Module.empty() == 1 || project.data[row].Channel.empty() == 1)
		{
			Global_delete_data_row(Design_grid_index, row);
			project.valid_entries = project.valid_entries - 1;
		}
		else
		{
			if (project.data[row].Channel.size() > 1)
			{
				if ((project.data[row].Channel.substr(project.data[row].Channel.size() - 2, 1).find_first_of(L"0123456789") == -1))
				{
					project.data[row].Channel.insert(project.data[row].Channel.size() - 1, L"0");
				}
			}
			a = (project.valid_entries - row) * 100 / project.valid_entries;
			set_progress_value(a);
		}
		row--;
	}
	Global_resize_data(Design_grid_index, project.valid_entries + 1);

	int max_digits = GetNumberOfDigits(project.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < project.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	for (int row = 0; row <= project.valid_entries; row++)
	{
		project.data[row].number = int_to_wstring(row, max_digits);
	}

	Hide_progress();
	strcpy_s(info_txt, sizeof info_txt, info_extract_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
}


