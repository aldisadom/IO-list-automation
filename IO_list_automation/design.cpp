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

using namespace libxl;
using namespace std;
using namespace IOlistautomation;

struct project_str project;


void Project_put_with_list()
{
	int a = project.collumn_with.size();
	if (a > 0 && parameters.auto_column_with == 0)
	{
		GlobalForm::forma->Design_grid->AutoResizeColumns();
		for (int i = 0; i < a; i++)
		{
			GlobalForm::forma->Design_grid->Columns[i]->Width = project.collumn_with[i];
		}
	}
	else
	{
		GlobalForm::forma->Design_grid->AutoResizeColumns();
	}
}

void Project_get_with_list()
{
	int a = GlobalForm::forma->Design_grid->ColumnCount;
	project.collumn_with.resize(a);

	for (int i = 0; i < a; i++)
	{
		project.collumn_with[i] = GlobalForm::forma->Design_grid->Columns[i]->Width;
	}
}

void Project_resize_data(int size)
{
	project.number.resize(size);
	project.Cabinet.resize(size);
	project.Module.resize(size);
	project.Pin.resize(size);
	project.Channel.resize(size);
	project.IO_text.resize(size);
	project.Page.resize(size);
}

void Project_delete_row(int row)
{
	project.Cabinet.erase(project.Cabinet.begin() + row);
	project.Module.erase(project.Module.begin() + row);
	project.Pin.erase(project.Pin.begin() + row);
	project.Channel.erase(project.Channel.begin() + row);
	project.IO_text.erase(project.IO_text.begin() + row);
	project.Page.erase(project.Page.begin() + row);
	project.number.erase(project.number.begin() + row);
}



int Project_read_data()
{
	GlobalForm::forma->tabControl1->SelectedIndex = 0;
	if (project.valid_entries > 1)
	{
		if (show_confirm_window(conf_design_overwrite[lang]) == IDOK)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
			project = {};
			Project_delete_list();
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

				project.number_collums = max_col - 1;
				project.valid_entries = max_rows - 1;

				Project_resize_data(max_rows);

				for (int row = sheet->firstRow(); row < max_rows; ++row)
				{
					project.number[row] = row;
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
						switch (col)
						{
						case 1:	project.Cabinet[row] = texts;
							break;
						case 2:	project.Module[row] = texts;
							break;
						case 3:	project.Pin[row] = texts;
							break;
						case 4:	project.Channel[row] = texts;
							break;
						case 5:	project.IO_text[row] = texts;
							break;
						case 6:	project.Page[row] = texts;
							break;
						}
					}
					set_progress_value(row);
				}

				project.column_name.resize(max_col);
				for (int col = sheet->firstCol(); col < max_col; ++col)
				{
					switch (col)
					{
					case 0:	project.column_name[col] = LPWSTR(L"Nr.");
						break;
					case 1:	project.column_name[col] = &project.Cabinet[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 2:	project.column_name[col] = &project.Module[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 3:	project.column_name[col] = &project.Pin[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 4:	project.column_name[col] = &project.Channel[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 5:	project.column_name[col] = &project.IO_text[parameters.excel_row_nr_with_name - 1][0];
						break;
					case 6:	project.column_name[col] = &project.Page[parameters.excel_row_nr_with_name - 1][0];
						break;
					default:project.column_name[col] = LPWSTR(L"");
						break;
					}
				}
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
		Project_delete_row(0);
	}
	project.valid_entries = project.valid_entries - parameters.excel_row_nr_with_name;
	int row = project.valid_entries;

	while (row >= 0)
	{
		if (project.Module[row].empty() == 1 || project.Channel[row].empty() == 1)
		{
			Project_delete_row(row);
			project.valid_entries = project.valid_entries - 1;
		}
		else
		{
			if (project.Channel[row].size() > 1)
			{
				if ((project.Channel[row].substr(project.Channel[row].size() - 2, 1).find_first_of(L"0123456789") == -1))
				{
					project.Channel[row].insert(project.Channel[row].size() - 1, L"0");
				}
			}
			a = (project.valid_entries - row) * 100 / project.valid_entries;
			set_progress_value(a);
		}
		row--;
	}
	Project_resize_data(project.valid_entries + 1);
	Hide_progress();
	strcpy_s(info_txt, sizeof info_txt, info_extract_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
}



void Project_put_data_listview()
{	
	Project_delete_list();
	GlobalForm::forma->Update();

	int iCol;

	int max_digits = GetNumberOfDigits(project.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < project.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	Show_progress(prog_grid_put[lang], project.valid_entries);

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	info_write(info_txt);


	// Add the columns.
	GlobalForm::forma->Design_grid->ColumnCount = project.number_collums + 1;

	for (iCol = 0; iCol <= project.number_collums; iCol++)
	{
		// Load the names of the column headings from the string resources.
		GlobalForm::forma->Design_grid->Columns[iCol]->Name = wstring_to_system_string(project.column_name[iCol]);
	}

	wstring cell_text = L"";


	for (int index = 0; index <= project.valid_entries; index++)
	{

		GlobalForm::forma->Design_grid->Rows->Add();

		// fill all cells with data
		for (iCol = 0; iCol <= project.number_collums; iCol++)
		{
			switch (iCol)
			{
			case 0:	cell_text = int_to_wstring(index, max_digits);
				project.number[index] = cell_text;
				break;
			case 1:	cell_text = project.Cabinet[index];
				break;
			case 2:	cell_text = project.Module[index];
				break;
			case 3:	cell_text = project.Pin[index];
				break;
			case 4:	cell_text = project.Channel[index];
				break;
			case 5:	cell_text = project.IO_text[index];
				break;
			case 6:	cell_text = project.Page[index];
				break;
			default:cell_text = LPWSTR(L"");
				break;
			}
			String^ textas = wstring_to_system_string(cell_text);

			// Insert items into the list.
			GlobalForm::forma->Design_grid->Rows[index]->Cells[iCol]->Value = textas;

		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	GlobalForm::forma->tabControl1->SelectedIndex = 0;

	Project_put_with_list();
	GlobalForm::forma->Update();
}


void Project_get_data_listview()
{
	if (GlobalForm::forma->Design_grid->RowCount > 0)
	{
		project.valid_entries = GlobalForm::forma->Design_grid->RowCount-1;
		Project_resize_data(project.valid_entries+1);

		project.number_collums = GlobalForm::forma->Design_grid->ColumnCount - 1;

		Show_progress(prog_grid_take[lang], project.valid_entries);

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
		info_write(info_txt);

		wstring cell_text = L"";

		int iCol;
		for (iCol = 0; iCol <= project.number_collums; iCol++)
		{
			project.column_name[iCol] = system_string_to_wstring(GlobalForm::forma->Design_grid->Columns[iCol]->Name);
		}


		for (int index = 0; index <= project.valid_entries; index++)
		{

			// fill all cells with data
			for (iCol = 0; iCol <= project.number_collums; iCol++)
			{
				cell_text = system_string_to_wstring(GlobalForm::forma->Design_grid->Rows[index]->Cells[iCol]->FormattedValue->ToString());

				switch (iCol)
				{
				case 0:	project.number[index] = cell_text;
					break;
				case 1:	project.Cabinet[index] = cell_text;
					break;
				case 2:	project.Module[index] = cell_text;
					break;
				case 3:	project.Pin[index] = cell_text;
					break;
				case 4:	project.Channel[index] = cell_text;
					break;
				case 5:	project.IO_text[index] = cell_text;
					break;
				case 6:	project.Page[index] = cell_text;
					break;
				}
			}
			set_progress_value(index);
		}
		Hide_progress();

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
		info_write(info_txt);

		if (unstable_release == 1)
		{
			Project_save_data(true, " ");
		}
		Project_get_with_list();
	}
	else
	{
		project = {};
	}
}

void Project_delete_list()
{
	GlobalForm::forma->Design_grid->Rows->Clear();
	GlobalForm::forma->Design_grid->Columns->Clear();
}


int Project_save_data(bool auto_save, std::string file_name_global)
{
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = "Save document |*.psave" +
		"|All Files|*.*";
	sfd->FileName = "Project";

	wstring cell_text = L"Design";
	string extension = ".psave";
	std::string file_name = "_autosave";
	file_name.append(extension);


	if (project.valid_entries <= 0)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	FILE* outFile;

	int iCol;
	if (auto_save == 0)
	{
		if (file_name_global.compare(" ") == 0)
		{
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				file_name = system_string_to_string(sfd->FileName);
			}
			else
			{
				strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
				err_write(err_txt);
				return 1;
			}
		}
		else
		{
			file_name = file_name_global;
			file_name.append(extension);
		}
		Show_progress(prog_save[lang], project.valid_entries);
	}
	fopen_s(&outFile, file_name.c_str(), "w+,ccs=UTF-8");

	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	info_write(info_txt);

	if (outFile == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_file_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	cell_text.append(L"\n");
	const wchar_t* x = cell_text.c_str();


	for (iCol = 0; iCol <= project.number_collums; iCol++)
	{
		cell_text.append(project.column_name[iCol]);
		cell_text.append(separator);
	}

	cell_text.append(L"\n");
	x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);

	wstring cell_text_write;
	for (int index = 0; index <= project.valid_entries; index++)
	{
		cell_text_write = L"";
		// fill all cells with data
		for (iCol = 0; iCol <= project.number_collums; iCol++)
		{
			switch (iCol)
			{
			case 0:	cell_text = project.number[index];
				break;
			case 1:	cell_text = project.Cabinet[index];
				break;
			case 2:	cell_text = project.Module[index];
				break;
			case 3:	cell_text = project.Pin[index];
				break;
			case 4:	cell_text = project.Channel[index];
				break;
			case 5:	cell_text = project.IO_text[index];
				break;
			case 6:	cell_text = project.Page[index];
				break;
			default:cell_text = LPWSTR(L"");
				break;
			}
			if (cell_text.empty() == 1)
			{
				cell_text = LPWSTR(L" ");
			}
			cell_text_write.append(cell_text);
			cell_text_write.append(separator);
			
		}
		cell_text_write.append(L"\n");
		x = cell_text_write.c_str();
		fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);
		
		set_progress_value(index);		
	}
	fclose(outFile);

	Hide_progress();
	
	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}

int Project_Load_data(std::string file_name_global)
{
	wchar_t cmp_text[255] = L"Design";

	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = "Load document |*.psave" +
		"|All Files|*.*";
	string extension = ".psave";

	if (project.valid_entries > 0)
	{
		if (show_confirm_window(conf_design_overwrite[lang]) == IDOK)
		{
			project = {};
			Project_delete_list();

			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	Show_progress(prog_load[lang], 1000);

	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	info_write(info_txt);

	FILE* inFile;
	string file_name;

	if (file_name_global.compare(" ") == 0)
	{
		if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			file_name = system_string_to_string(importfile->FileName);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	else
	{
		file_name = file_name_global;
		file_name.append(extension);
	}		

		
		fopen_s(&inFile, file_name.c_str(), "r+,ccs=UTF-8");
		if (inFile == NULL)
		{
			strcpy_s(err_txt, sizeof err_txt, err_cant_open[lang]);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
			err_write_show(err_txt);
			return 1;
		}

		wchar_t x[1024];
		wchar_t * cell_text;
		wchar_t *next_token1 = NULL;
		int iCol = 0;
		int index = 0;

		fgetws(x, sizeof x, inFile);

		if (wcsstr(x, cmp_text) == NULL)
		{
			fclose(inFile);

			strcpy_s(err_txt, sizeof err_txt, err_wrong_file[lang]);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
			err_write_show(err_txt);
			return 1;
		}
		fgetws(x, sizeof x, inFile);

		cell_text = wcstok_s(x, separator, &next_token1);
		if (cell_text == NULL)
		{
			fclose(inFile);

			strcpy_s(err_txt, sizeof err_txt, err_corrupted_file[lang]);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
			err_write_show(err_txt);
			return 1;
		}
		while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
		{
			project.number_collums = iCol;
			project.column_name.resize(project.number_collums + 1);
			project.column_name[iCol] = cell_text;
			iCol++;
			cell_text = wcstok_s(NULL, separator, &next_token1);
		}

		int a = 0;
		while (fgetws(x, sizeof x, inFile) != NULL)
		{
			project.valid_entries = index;
			Project_resize_data(index + 1);
			iCol = 0;

			cell_text = wcstok_s(x, separator, &next_token1);
			while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL )
			{
				if (wcscmp(cell_text, L" ") != 0)
				{
					switch (iCol)
					{
					case 0:	project.number[index] = cell_text;
						break;
					case 1:	project.Cabinet[index] = cell_text;
						break;
					case 2:	project.Module[index] = cell_text;
						break;
					case 3:	project.Pin[index] = cell_text;
						break;
					case 4:	project.Channel[index] = cell_text;
						break;
					case 5:	project.IO_text[index] = cell_text;
						break;
					case 6:	project.Page[index] = cell_text;
						break;
					}
				}
				iCol++;
				cell_text = wcstok_s(NULL, separator, &next_token1);
			}
			a++;
			index++;
			if (a > 1000)
			{
				a = a - 1000;
			}
			set_progress_value(a);
		}
		fclose(inFile);

		Hide_progress();



	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Project_put_data_listview();

	return 0;

}