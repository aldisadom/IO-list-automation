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
#include "IO_declare.h"



using namespace libxl;
using namespace std;
using namespace IOlistautomation;

struct project_str project;

// get data from memory to wstring
std::wstring Project_get_data_switch(int iCol, int index)
{
	switch (iCol)
	{
	case 0:	return project.data[index].number;
		break;
	case 1:	return project.data[index].Cabinet;
		break;
	case 2:	return project.data[index].Module_name;
		break;
	case 3:	return project.data[index].Pin;
		break;
	case 4:	return project.data[index].Channel;
		break;
	case 5:	return project.data[index].IO_text;
		break;
	case 6:	return project.data[index].Page;
		break;
	default:return LPWSTR(L"");
		break;
	}
}
// put data from wstring to memory
void Project_put_data_switch(int iCol, int index, project_str &project_data, std::wstring cell_text)
{
	switch (iCol)
	{
	case 0:	project_data.data[index].number = cell_text;
		break;
	case 1:	project_data.data[index].Cabinet = cell_text;
		break;
	case 2:	project_data.data[index].Module_name = cell_text;
		break;
	case 3:	project_data.data[index].Pin = cell_text;
		break;
	case 4:	project_data.data[index].Channel = cell_text;
		break;
	case 5:	project_data.data[index].IO_text = cell_text;
		break;
	case 6:	project_data.data[index].Page = cell_text;
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
	if (project.data[row].Module_name.empty() == 0)
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


// extract useful data from design file
void Project_data_extract_useful_data( project_str &project_data)
{
	int a = 0;
	Show_progress(prog_process_data[lang], 100);

	strcpy_s(info_txt, sizeof info_txt, info_extract_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	info_write(info_txt);

	//clearing rows thant dont have data
	for (int row = 0; row < parameters.excel_row_nr_with_name; ++row)
	{
		project_data.data.erase(project_data.data.begin());
	}
	project_data.valid_entries = project_data.valid_entries - parameters.excel_row_nr_with_name;
	int row = project_data.valid_entries;

	// going through all data
	while (row >= 0) // its quicker to delete from vectors end than begining
	{
		if (project_data.data[row].Module_name.empty() == 1 || project_data.data[row].Channel.empty() == 1)   // if no data in module or channel, that line of data is not useful and delete it
		{
			project_data.data.erase(project_data.data.begin()+row);			
			project_data.valid_entries = project_data.valid_entries - 1;
		}
		else
		{
			// if there is more than two simbols, search if last-1 character is not number, than add "0" before last symbol 
			if (project_data.data[row].Channel.size() > 1)
			{
				if ((project_data.data[row].Channel.substr(project_data.data[row].Channel.size() - 2, 1).find_first_of(L"0123456789") == -1))
				{
					project_data.data[row].Channel.insert(project_data.data[row].Channel.size() - 1, L"0");
				}
			}
			else // if size is 1 than add "0" to beggining
			{
				project_data.data[row].Channel.insert(0, L"0");
			}
			a = (project_data.valid_entries - row) * 100 / project_data.valid_entries;
			set_progress_value(a);
		}
		row--;
	}
	project_data.data.resize(project_data.valid_entries + 1);


	int max_digits = GetNumberOfDigits(project_data.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < project_data.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	// numerise all entries, and add zeros for better sorting
	for (int row = 0; row <= project_data.valid_entries; row++)
	{
		project_data.data[row].number = int_to_wstring(row, max_digits);
	}

	Hide_progress();
	strcpy_s(info_txt, sizeof info_txt, info_extract_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
}
//read data from design file
int Project_read_data(bool compare_data, project_str &project_data)
{
	GlobalForm::forma->tabControl1->SelectedIndex = Design_grid_index; // select working cell
	if (project_data.valid_entries > 1 && compare_data ==FALSE)
	{
		int result = show_confirm_window(conf_design_overwrite[lang]);
		if (result == IDYES)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, design_txt[lang]);			
			project_data.data = {};
			Global_get_width_list(Design_grid_index, project_data.number_collums, project_data.collumn_with);
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

				project_data.valid_entries = max_rows - 1;

				project_data.data.resize(max_rows);

				for (int row = sheet->firstRow(); row < max_rows; ++row)
				{
					project_data.data[row].number = row;
					for (int col = sheet->firstCol(); col < max_col; ++col)
					{
						s = sheet->readStr(row, col);
						if (s == NULL)
						{
							texts = L"";
							error_message = book->errorMessage();
							fStringMatch = (strcmp(error_message, error_lic) == 0);
							if (fStringMatch)	// trial version walkaround for reading					
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
						Project_put_data_switch(col, row, project_data, texts);
					}
					set_progress_value(row);
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

	Project_data_extract_useful_data(project_data);
	if (compare_data == FALSE)
	{
		Global_put_data_listview(Design_grid_index, project_data.valid_entries, project_data.number_collums, project_data.column_name, project_data.collumn_with);
	}
	return 0;
}


struct test_result_str
{
	int nr_change = -1;
	bool delete_row = TRUE;
};

// compares current data with new data
int Project_compare_data()
{
	strcpy_s(info_txt, sizeof info_txt, info_compare_project[lang]);
	info_write(info_txt);

	project_str project_data_test;
	if (Project_read_data(TRUE, project_data_test) != 0)
	{
		return 1;
	}

	Global_get_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);

	if (project.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}
	
	

	wstring test_IO = L"";
	wstring IO = L"";

	vector <int> test_res;
	vector <test_result_str> proj_res ;

	proj_res.resize(project.valid_entries+1);

	int row=0;
	int result = 0;
	int test_nr = 0;
	int ok_count = 0;

	Show_progress(prog_search_diference[lang], project_data_test.valid_entries);

	//going through all data and testing if there is diserences
	for (int index = 0; index <= project_data_test.valid_entries; index++)
	{
		if (IO_generate_signal(project_data_test.data[index].Cabinet, project_data_test.data[index].Module_name, project_data_test.data[index].Channel, test_IO) != 0)
		{
			continue;
		}
		for (row = 0; row <= project.valid_entries; row++)
		{
			if (IO_generate_signal(project.data[row].Cabinet, project.data[row].Module_name, project.data[row].Channel, IO) != 0)
			{
				continue;
			}
			
			result = test_IO.compare(IO);
			// found signal
			if (result==0)
			{	
				result = project_data_test.data[index].IO_text.compare(project.data[row].IO_text);
				if (result == 0)
				{
					proj_res[row].delete_row = FALSE;
					ok_count++;
				}
				else
				{
					proj_res[row].delete_row = FALSE;
					proj_res[row].nr_change = index;
				}	
				break;
			}
		}

		//didnt found data then add 
		if (row > project.valid_entries)
		{
			test_res.resize(test_nr + 1);
			test_res[test_nr] = index;
			test_nr++;
		}
		set_progress_value(index);
	}

	int size = test_res.size();
	wstring text_confirm = L"";

	int modification_count = size + (project.valid_entries - ok_count);
	if (modification_count <= 0)
	{
		return 0;
	}

	Show_progress(prog_search_diference[lang], size);
	row = project.valid_entries;

	project.valid_entries = project.valid_entries + size;
	project.data.resize(project.valid_entries + 1);

	//adding new data
	for (int index = 0; index < size; index++)
	{
		row++;

		text_confirm = conf_objects_type_overwrite[lang];
		text_confirm.append(L" --- ");
		text_confirm.append(project_data_test.data[index].IO_text);

		result = show_confirm_window(text_confirm.c_str());
		if (result == IDYES)
		{
			project.data[row].IO_text = project_data_test.data[index].IO_text;
			project.data[row].Cabinet = project_data_test.data[index].Cabinet;
			project.data[row].Channel = project_data_test.data[index].Channel;
			project.data[row].Module_name = project_data_test.data[index].Module_name;
			project.data[row].number = project_data_test.data[index].number;
			project.data[row].Page = project_data_test.data[index].Page;
			project.data[row].Pin = project_data_test.data[index].Pin;
		}
		else if (result == IDCANCEL)
		{
			return 0;
		}
		set_progress_value(index);
	}
//	Global_put_data_listview(Design_grid_index, project_data_test.valid_entries, project_data_test.number_collums, project_data_test.column_name, project_data_test.collumn_with);


	strcpy_s(info_txt, sizeof info_txt, info_compare_project[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Hide_progress();

	return 0;
}
