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
#include "Compare_result.h"



using namespace libxl;
using namespace std;
using namespace IOlistautomation;

struct project_str project;



std::wstring Project_get_cell_data(int row, int col, Sheet* sheet)
{
	wstring ws;
	const wchar_t* s;
	CellType cellType = sheet->cellType(row, col);
	switch (cellType)
	{
		case CELLTYPE_EMPTY: 
			return L"";
			break;
		case CELLTYPE_NUMBER:
			return ws = String_remove_trailing_zero(to_wstring(sheet->readNum(row, col)));
			break;
		case CELLTYPE_STRING:
			s = sheet->readStr(row, col);
			if (s == NULL)
				return L"";
			else
			{
				ws = wstring(s);				
				return ws;
			}			
			break;
		case CELLTYPE_BOOLEAN:
			return L"";
			break;
		case CELLTYPE_BLANK:
			return L"";
			break;
		case CELLTYPE_ERROR:
			return L"";
			break;
	}
	return L"";
}


std::wstring Project_data_switch(project_data_str data, int iCol)
{
	switch (iCol)
	{
	case design_column_number:	return data.number;
		break;
	case design_column_CPU:	return data.CPU;
		break;
	case design_column_KKS:	return data.KKS;
		break;
	case design_column_Section:	return data.Section;
		break;
	case design_column_Range_min:	return data.Range_min;
		break;
	case design_column_Range_max:	return data.Range_max;
		break;
	case design_column_Units:	return data.Units;
		break;
	case design_column_False_text:	return data.False_text;
		break;
	case design_column_True_text:	return data.True_text;
		break;
	case design_column_Revision:	return data.Revision;
		break;
	case design_column_Cable:	return data.Cable;
		break;
	case design_column_Cabinet:	return data.Cabinet;
		break;
	case design_column_Module_name:	return data.Module_name;
		break;
	case design_column_Pin:	return data.Pin;
		break;
	case design_column_Channel:	return data.Channel;
		break;
	case design_column_IO_text:	return data.IO_text;
		break;
	case design_column_Page:	return data.Page;
		break;
	case design_column_Changed:	return data.Changed;
		break;
	default:return LPWSTR(L"");
		break;
	}
}

// get data from memory to wstring
std::wstring Project_get_data_switch(int iCol, int index)
{
	return Project_data_switch(project.data[index], iCol);
}


// put data from wstring to memory
void Project_put_data_switch(int iCol, int index, project_str &project_data, std::wstring cell_text)
{
	switch (iCol)
	{
	case design_column_number:	project_data.data[index].number = cell_text;
		break;
	case design_column_CPU:	project_data.data[index].CPU = cell_text;
		break;
	case design_column_KKS:	project_data.data[index].KKS = cell_text;
		break;
	case design_column_Section:	project_data.data[index].Section = cell_text;
		break;
	case design_column_Range_min:	project_data.data[index].Range_min = cell_text;
		break;
	case design_column_Range_max:	project_data.data[index].Range_max = cell_text;
		break;
	case design_column_Units:	project_data.data[index].Units = cell_text;
		break;
	case design_column_False_text:	project_data.data[index].False_text = cell_text;
		break;
	case design_column_True_text:	project_data.data[index].True_text = cell_text;
		break;
	case design_column_Revision:	project_data.data[index].Revision = cell_text;
		break;
	case design_column_Cable:	project_data.data[index].Cable = cell_text;
		break;
	case design_column_Cabinet:	project_data.data[index].Cabinet = cell_text;
		break;
	case design_column_Module_name:	project_data.data[index].Module_name = cell_text;
		break;
	case design_column_Pin:	project_data.data[index].Pin = cell_text;
		break;
	case design_column_Channel:	project_data.data[index].Channel = cell_text;
		break;
	case design_column_IO_text:	project_data.data[index].IO_text = cell_text;
		break;
	case design_column_Page:	project_data.data[index].Page = cell_text;
		break;
	case design_column_Changed:	project_data.data[index].Changed = cell_text;
		break;
	}
}


//check if there is data in any variable
int Project_valid_row_check(int row)
{
	if (project.data[row].number.empty() == 0)
		return 1;
	if (project.data[row].CPU.empty() == 0)
		return 1;
	if (project.data[row].KKS.empty() == 0)
		return 1;
	if (project.data[row].Section.empty() == 0)
		return 1;
	if (project.data[row].Range_min.empty() == 0)
		return 1;
	if (project.data[row].Range_max.empty() == 0)
		return 1;
	if (project.data[row].Units.empty() == 0)
		return 1;
	if (project.data[row].False_text.empty() == 0)
		return 1;
	if (project.data[row].True_text.empty() == 0)
		return 1;
	if (project.data[row].Revision.empty() == 0)
		return 1;
	if (project.data[row].Cable.empty() == 0)
		return 1;
	if (project.data[row].Cabinet.empty() == 0)
		return 1;
	if (project.data[row].Module_name.empty() == 0)
		return 1;
	if (project.data[row].Pin.empty() == 0)
		return 1;
	if (project.data[row].Channel.empty() == 0)
		return 1;
	if (project.data[row].IO_text.empty() == 0)
		return 1;
	if (project.data[row].Page.empty() == 0)
		return 1;
	return 0;
}


// extract useful data from design file
void Project_data_extract_useful_data( project_str &project_data)
{
	int a = 0;
	Show_progress(str.Progress.process_data.s[lang], 100);

	wstring texts = str.Info.extract_data.s[lang];
	texts.append(info_separator);
	texts.append(str.General.design_txt.s[lang]);
	info_write(texts);

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
		if ((project_data.data[row].Module_name.empty() == 1 || project_data.data[row].Channel.empty() == 1) && parameters.Delete_if_no_module == 1)   // if no data in module or channel, that line of data is not useful and delete it
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
	int max_digits = 0;

	if (parameters.column_in_import.Number >= 0) 
	{
		int max_number = 0;
		for (int row = 0; row <= project_data.valid_entries; row++)
		{
			max_number = max(stoi(project_data.data[row].number, nullptr, 0),max_number);
		}	
		max_digits = GetNumberOfDigits(max_number);
	}
	else
	{
		max_digits = GetNumberOfDigits(project_data.valid_entries);		
	}

	if ((pow(10, max_digits - 1) * 9) < project_data.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	// numerise all entries, and add zeros for better sorting
	for (int row = 0; row <= project_data.valid_entries; row++)
	{
		
		if (parameters.column_in_import.Number >= 0)
			project_data.data[row].number = int_to_wstring(stoi(project_data.data[row].number, nullptr, 0), max_digits);
		else
			project_data.data[row].number = int_to_wstring(row, max_digits);
	}

	Hide_progress();
	texts = str.Info.extract_data.s[lang];
	texts.append(info_separator);
	texts.append(str.General.design_txt.s[lang]);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);
}
//read data from design file
int Project_read_data(bool compare_data,wstring test_mode, project_str &project_data)
{
	wstring texts;
	wstring test_mode_str = test_mode;
	GlobalForm::forma->tabControl1->SelectedIndex = Design_grid_index; // select working cell
	OpenFileDialog^ importfile;
	if (test_mode_str.compare(L" ")== 0)
	{
		if (project_data.valid_entries > 1 && compare_data == FALSE)
		{
			int result = show_confirm_window(str.Confirm.design_overwrite.s[lang]);
			if (result == IDYES)
			{
				texts = str.Info.erase_data.s[lang];
				texts.append(info_separator);
				texts.append(str.General.design_txt.s[lang]);
				info_write(texts);

				project_data.data = {};
				Global_get_width_list(Design_grid_index, project_data.number_collums, project_data.collumn_with);
			}
			else
			{
				texts = str.Error.canceled_selection.s[lang];
				err_write_show(texts);
				return 1;
			}
		}
		importfile = gcnew OpenFileDialog();
		importfile->Filter = "Excel Worksheets|*.xls" +
			"|All Files|*.*";
	}
	bool pass = false;
	if (test_mode_str.compare(L" ") != 0)
	{
		pass = true;
	}
	else if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		pass = true;
	}

	if (pass == true)
	{
		Book* book = xlCreateBook();
		texts = str.Info.excel_read_data.s[lang];
		info_write(texts);
		const char* error_lic = "can't read more cells in trial version";
		bool fStringMatch = FALSE;

		wstring asd;
		if (test_mode_str.compare(L" ") == 0)
		{
			asd = system_string_to_wstring(importfile->FileName);
		}
		else
		{
			asd = L".\\Test data\\IO\\";
			asd.append(test_mode);
			asd.append(L".xls");
		}

		const wchar_t* file_name = asd.c_str();

		if (book->load(file_name))
		{
			Sheet* sheet = book->getSheet(0);
			if (sheet)
			{
				int max_rows = sheet->lastRow();
				int max_col = sheet->lastCol();
				int nr = 0;
				const wchar_t* s = L" ";
				wstring text = L" ";
				const char* error_message = " ";

				Show_progress(str.Progress.read_data.s[lang], max_rows);

				project_data.valid_entries = max_rows - 1;

				project_data.data.resize(max_rows);

				for (int row = sheet->firstRow(); row < max_rows; ++row)
				{

					for (int col = sheet->firstCol(); col < max_col; ++col)
					{
						
						text = Project_get_cell_data(row, col, sheet);
						
						if (text.empty()==true)
						{
							error_message = book->errorMessage();
							fStringMatch = (strcmp(error_message, error_lic) == 0);
							if (fStringMatch)	// trial version walkaround for reading					
							{
								book->release();
								book = xlCreateBook();
								book->load(file_name);
								sheet = book->getSheet(0);
								
								text = Project_get_cell_data(row, col,sheet);
								if (text.empty() == true)
									text = L"";

								if (parameters.debug)
								{
									texts = L"Excel file licesing bypass";
									info_write(texts);
								}
							}
							else
							{
								text = L"";
							}
						}

						int a = 0;
						while (a != -1)
						{						
							a= text.find(L"\n", sizeof L"\n");
							if (a > 0)
							{
								text.replace(a, 1, L" ");
							}
						}

						int Column_write = -1;
						if (parameters.column_in_import.Number == col + 1)
							Column_write = design_column_number;
						else if (parameters.column_in_import.CPU == col + 1)
							Column_write = design_column_CPU;
						else if (parameters.column_in_import.KKS == col + 1)
							Column_write = design_column_KKS;
						else if (parameters.column_in_import.Section == col + 1)
							Column_write = design_column_Section;
						else if (parameters.column_in_import.Range_min == col + 1)
							Column_write = design_column_Range_min;
						else if (parameters.column_in_import.Range_max == col + 1)
							Column_write = design_column_Range_max;
						else if (parameters.column_in_import.Units == col + 1)
							Column_write = design_column_Units;
						else if (parameters.column_in_import.False_text == col + 1)
							Column_write = design_column_False_text;
						else if (parameters.column_in_import.True_text == col + 1)
							Column_write = design_column_True_text;
						else if (parameters.column_in_import.Revision == col + 1)
							Column_write = design_column_Revision;
						else if (parameters.column_in_import.Cable == col + 1)
							Column_write = design_column_Cable;
						else if (parameters.column_in_import.Cabinet == col + 1)
							Column_write = design_column_Cabinet;
						else if (parameters.column_in_import.Module_name == col + 1)
							Column_write = design_column_Module_name;
						else if (parameters.column_in_import.Pin == col + 1)
							Column_write = design_column_Pin;
						else if (parameters.column_in_import.Channel == col + 1)
							Column_write = design_column_Channel;
						else if (parameters.column_in_import.IO_text == col + 1)
							Column_write = design_column_IO_text;
						else if (parameters.column_in_import.Page == col + 1)
							Column_write = design_column_Page;
						else if (parameters.column_in_import.Changed == col + 1)
							Column_write = design_column_Changed;

						if (Column_write >= 0)
							Project_put_data_switch(Column_write, row, project_data, text);
					}
					set_progress_value(row);
				}
				book->release();
			}
			else
			{
				texts = str.Error.excel_no_sheet.s[lang];
				err_write_show(texts);
				return 1;
			}
		}
		else
		{
			texts = str.Error.excel_cant_open.s[lang];
			err_write_show(texts);
			return 1;
		}
	}
	else
	{
		texts = str.Error.canceled_selection.s[lang];
		err_write(texts);
		return 1;
	}

	Hide_progress();
	texts = str.Info.excel_read_data.s[lang];
	texts.append(info_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	Project_data_extract_useful_data(project_data);
	if (compare_data == FALSE)
	{
		Global_put_data_listview(Design_grid_index, project_data.valid_entries, project_data.number_collums, project_data.column_name_EN, project_data.column_name_LT, project_data.collumn_with);
	}
	return 0;
}


struct test_result_str
{
	int nr_change = -1;
	bool delete_row = TRUE;	
};



void Project_compare_line(project_data_str data, project_data_str test, test_result_str &project_data_result,color_change_array_str &change_array, int &nr_ok, int test_index)
{
	bool skip = false;
	bool found = false;
	int number = 0;
	int result = 0;
	wstring text1 = L"";
	wstring text2= L"";
	int i = 0;
	for (i = 0; i <= project.number_collums; i++) 
	{		
		switch (i)
		{
		case 0:	
			if (parameters.column_in_import.Number >= 0)
			{
				text1=data.number;
				text2 = test.number;
			}
			else
				skip = true;
			break;
		case 1:
			if (parameters.column_in_import.KKS >= 0)
			{
				text1 = data.KKS;
				text2 = test.KKS;
			}
			else
				skip = true;
			break;
		case 2:
			if (parameters.column_in_import.Section >= 0)
			{
				text1 = data.Section;
				text2 = test.Section;
			}
			else
				skip = true;
			break;
		case 3:
			if (parameters.column_in_import.Range_min >= 0)
			{
				text1 = data.Range_min;
				text2 = test.Range_min;
			}
			else
				skip = true;
			break;
		case 4:	
			if (parameters.column_in_import.Range_max >= 0)
			{
				text1 = data.Range_max;
				text2 = test.Range_max;
			}
			else
				skip = true;
			break;
		case 5:
			if (parameters.column_in_import.Units >= 0)
			{
				text1 = data.Units;
				text2 = test.Units;
			}
			else
				skip = true;
			break;
		case 6:	
			if (parameters.column_in_import.False_text >= 0)
			{
				text1 = data.False_text;
				text2 = test.False_text;
			}
			else
				skip = true;
			break;
		case 7:	
			if (parameters.column_in_import.True_text >= 0)
			{
				text1 = data.True_text;
				text2 = test.True_text;
			}
			else
				skip = true;
			break;
		case 8:	
			if (parameters.column_in_import.Revision >= 0)
			{
				text1 = data.Revision;
				text2 = test.Revision;
			}
			else
				skip = true;
			break;
		case 9:	
			if (parameters.column_in_import.Cable >= 0)
			{
				text1 = data.Cable;
				text2 = test.Cable;
			}
			else
				skip = true;
			break;
		case 10:	
			if (parameters.column_in_import.Cabinet >= 0)
			{
				text1 = data.Cabinet;
				text2 = test.Cabinet;
			}
			else
				skip = true;
			break;
		case 11:	
			if (parameters.column_in_import.Module_name >= 0)
			{
				text1 = data.Module_name;
				text2 = test.Module_name;
			}
			else
				skip = true;
			break;
		case 12:	
			if (parameters.column_in_import.Pin >= 0)
			{
				text1 = data.Pin;
				text2 = test.Pin;
			}
			else
				skip = true;
			break;
		case 13:	
			if (parameters.column_in_import.Channel >= 0)
			{
				text1 = data.Channel;
				text2 = test.Channel;
			}
			else
				skip = true;
			break;
		case 14:	
			if (parameters.column_in_import.IO_text >= 0)
			{
				text1 = data.IO_text;
				text2 = test.IO_text;
			}
			else
				skip = true;
			break;
		case 15:
			if (parameters.column_in_import.Page >= 0)
			{
				text1 = data.Page;
				text2 = test.Page;
			}
			else
				skip = true;
			break;
		case 16:	
			if (parameters.column_in_import.Changed >= 0)
			{
				text1 = data.Changed;
				text2 = test.Changed;
			}
			else
				skip = true;
			break;
		}
		if (skip == true)
		{
			skip = false;
			continue;
		}
		result = text1.compare(text2);
		found = (result != 0);
		change_array.column_changed[i] = found;
		if (found == true)
		{
			number++;
		}
	}

	if (number == 0)
	{
		project_data_result.delete_row = FALSE;
		nr_ok++;
	}
	else
	{
		project_data_result.delete_row = FALSE;
		project_data_result.nr_change = test_index;
		change_array.changed = true;
	}
}




// compares current data with new data
int Project_compare_data(wstring test_mode)
{
	wstring test_mode_str = test_mode;

	wstring texts = str.Info.compare_project.s[lang];
	info_write(texts);

	Global_get_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.collumn_with, false);
	if (project.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.design_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	project_str project_data_test;
	if (Project_read_data(TRUE, test_mode, project_data_test) != 0)
	{
		return 1;
	}



	wstring test_IO = L"";
	wstring IO = L"";

	vector <int> test_res;
	vector <test_result_str> proj_res ;
	vector <color_change_array_str> change_array;

	proj_res.resize(project.valid_entries+1);
	change_array.resize(project.valid_entries + 1);

	int row=0;
	int result = 0;
	int test_nr = 0;
	int ok_count = 0;

	Show_progress(str.Progress.search_diference.s[lang], project_data_test.valid_entries);

	bool skip1_test, skip2_test;
	bool skip1, skip2;
	wstring kks, kks_test;
	//going through all data and testing if there is diferences
	for (int index = 0; index <= project_data_test.valid_entries; index++)
	{
		
		skip1_test = (IO_generate_signal(project_data_test.data[index].Cabinet, project_data_test.data[index].Module_name, project_data_test.data[index].Channel, test_IO) != 0) ||
			(parameters.column_in_import.Module_name < 0) || (parameters.column_in_import.Channel < 0);
		skip2_test = (project_data_test.data[index].KKS.empty() == 1) || (parameters.column_in_import.KKS < 0);
		kks_test = project_data_test.data[index].KKS;

		if ((skip1_test && skip2_test) == true)
			continue;

		for (row = 0; row <= project.valid_entries; row++)
		{
			skip1 = IO_generate_signal(project.data[row].Cabinet, project.data[row].Module_name, project.data[row].Channel, IO) != 0;
			skip2 = (project.data[row].KKS.empty() == 1) || (parameters.column_in_import.KKS < 0);
			kks = project.data[row].KKS;

			if ((skip1 && skip2) == true)
				continue;

			
			if (parameters.Compare_by_IO == 1 && skip1 == false && skip1_test == false)
			{
				result = test_IO.compare(IO);
			}
			else if(skip2 == false && skip2_test == false)
			{
				result = kks_test.compare(kks);
			}
			else
			{
				result = test_IO.compare(IO);
			}
			
			// found signal
			if (result==0)
			{	
				Project_compare_line(project.data[row], project_data_test.data[index], proj_res[row], change_array[row],ok_count,index);
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

	int modification_count = size + (project.valid_entries - ok_count);
	if (modification_count <= 0)
	{
		Hide_progress();
		return 0;
	}

	Show_progress(str.Progress.search_diference.s[lang], size);
	row = project.valid_entries;
	
	project.data.resize(project.valid_entries +size+1);

	//adding new data
	for (int index = 0; index < size; index++)
	{
		row++;
		if (parameters.column_in_import.IO_text >= 0)
			project.data[row].IO_text = project_data_test.data[test_res[index]].IO_text;
		else
			project.data[row].IO_text = L"";
		if (parameters.column_in_import.Cabinet >= 0)
			project.data[row].Cabinet = project_data_test.data[test_res[index]].Cabinet;
		else
			project.data[row].Cabinet = L"";
		if (parameters.column_in_import.Channel >= 0)
			project.data[row].Channel = project_data_test.data[test_res[index]].Channel;
		else
			project.data[row].Channel = L"";
		if (parameters.column_in_import.Module_name >= 0)
			project.data[row].Module_name = project_data_test.data[test_res[index]].Module_name;
		else
			project.data[row].Module_name = L"";
		if (parameters.column_in_import.Number >= 0)
			project.data[row].number = project_data_test.data[test_res[index]].number;
		else
			project.data[row].number = L"";
		if (parameters.column_in_import.Page >= 0)
			project.data[row].Page = project_data_test.data[test_res[index]].Page;
		else
			project.data[row].Page = L"";
		if (parameters.column_in_import.KKS >= 0)
			project.data[row].KKS = project_data_test.data[test_res[index]].KKS;
		else
			project.data[row].KKS = L"";
		if (parameters.column_in_import.Section >= 0)
			project.data[row].Section = project_data_test.data[test_res[index]].Section;
		else
			project.data[row].Section = L"";
		if (parameters.column_in_import.Range_min >= 0)
			project.data[row].Range_min = project_data_test.data[test_res[index]].Range_min;
		else
			project.data[row].Range_min = L"";
		if (parameters.column_in_import.Range_max >= 0)
			project.data[row].Range_max = project_data_test.data[test_res[index]].Range_max;
		else
			project.data[row].Range_max = L"";
		if (parameters.column_in_import.Units >= 0)
			project.data[row].Units = project_data_test.data[test_res[index]].Units;
		else
			project.data[row].Units = L"";
		if (parameters.column_in_import.False_text >= 0)
			project.data[row].False_text = project_data_test.data[test_res[index]].False_text;
		else
			project.data[row].False_text = L"";
		if (parameters.column_in_import.True_text >= 0)
			project.data[row].True_text = project_data_test.data[test_res[index]].True_text;
		else
			project.data[row].True_text = L"";
		if (parameters.column_in_import.Revision >= 0)
			project.data[row].Revision = project_data_test.data[test_res[index]].Revision;
		else
			project.data[row].Revision = L"";
		if (parameters.column_in_import.Cable >= 0)
			project.data[row].Cable = project_data_test.data[test_res[index]].Cable;
		else
			project.data[row].Cable = L"";
		if (parameters.column_in_import.Pin >= 0)
			project.data[row].Pin = project_data_test.data[test_res[index]].Pin;
		else
			project.data[row].Pin = L"";
		if (parameters.column_in_import.Changed >= 0)
			project.data[row].Changed = project_data_test.data[test_res[index]].Changed;
		else
			project.data[row].Changed = L"1";

		for (int iCol = 0; iCol <= project.number_collums; iCol++)
		{
			change_array[row].column_changed[iCol] = true;
		}
		change_array[row].changed = false;

		set_progress_value(index);
	}

	Show_progress(str.Progress.search_diference.s[lang], project.valid_entries);

	IOlistautomation::Compare_result forma;

	wstring text_test = L"";
	wstring text_current = L"";


	//change data
	for (int index = 0; index <= project.valid_entries; index++)
	{
		project.data[index].Changed = L"";
		if (proj_res[index].nr_change>=0)
		{
			int number_change = proj_res[index].nr_change;

			text_test = project_data_test.data[number_change].KKS;
			text_current = project.data[index].KKS;

			for (int iCol = 0; iCol <= project.number_collums; iCol++)
			{
				if (change_array[index].column_changed[iCol] == true)
				{
					text_current.append(L"\r\n");
					text_current.append(Project_get_data_switch(iCol, index));					

					text_test.append(L"\r\n");
					text_test.append(Project_data_switch(project_data_test.data[number_change], iCol));					
				}
			}

			if (result != Result_No_all && result != Result_Yes_all)
			{
				if (test_mode_str.compare(L" ") == 0)
				{
					forma.Confirm_check_init(text_current, text_test);
					//				forma.return_value == Result_Yes;
					forma.ShowDialog();
					result = forma.return_value;
				}
				else
					result = Result_No;
			}

			if (result == Result_Yes || result == Result_Yes_all || test_mode_str.compare(L" ") != 0)
			{
				if (change_array[index].column_changed[0] == true)
					project.data[index].number = project_data_test.data[number_change].number;
				if (change_array[index].column_changed[1] == true)
					project.data[index].KKS = project_data_test.data[number_change].KKS;
				if (change_array[index].column_changed[2] == true)
					project.data[index].Section = project_data_test.data[number_change].Section;
				if (change_array[index].column_changed[3] == true)
					project.data[index].Range_min = project_data_test.data[number_change].Range_min;
				if (change_array[index].column_changed[4] == true)
					project.data[index].Range_max = project_data_test.data[number_change].Range_max;
				if (change_array[index].column_changed[5] == true)
					project.data[index].Units = project_data_test.data[number_change].Units;
				if (change_array[index].column_changed[6] == true)
					project.data[index].False_text = project_data_test.data[number_change].False_text;
				if (change_array[index].column_changed[7] == true)
					project.data[index].True_text = project_data_test.data[number_change].True_text;
				if (change_array[index].column_changed[8] == true)
					project.data[index].Revision = project_data_test.data[number_change].Revision;
				if (change_array[index].column_changed[9] == true)
					project.data[index].Cable = project_data_test.data[number_change].Cable;
				if (change_array[index].column_changed[10] == true)
					project.data[index].Cabinet = project_data_test.data[number_change].Cabinet;
				if (change_array[index].column_changed[11] == true)
					project.data[index].Module_name = project_data_test.data[number_change].Module_name;
				if (change_array[index].column_changed[12] == true)
					project.data[index].Pin = project_data_test.data[number_change].Pin;
				if (change_array[index].column_changed[13] == true)
					project.data[index].Channel = project_data_test.data[number_change].Channel;
				if (change_array[index].column_changed[14] == true)
					project.data[index].IO_text = project_data_test.data[number_change].IO_text;
				if (change_array[index].column_changed[15] == true)
					project.data[index].Page = project_data_test.data[number_change].Page;
				if (change_array[index].column_changed[16] == true)
					project.data[index].Changed = project_data_test.data[number_change].Changed;
				else
					project.data[index].Changed = L"1";
			}
			else if (result == Result_No || result == Result_No_all)
			{
				for (int iCol = 0; iCol <= project.number_collums; iCol++)
				{
					change_array[index].column_changed[iCol] = false;
				}
				change_array[index].changed = false;
				project.data[index].Changed = L"";
			}
		}
		set_progress_value(index);
	}

	//remove data
	for (int index = 0; index <= project.valid_entries; index++)
	{
		if (proj_res[index].delete_row == true)
		{
			project.data.erase(project.data.begin()+index);
			project.valid_entries--;
		}		
		set_progress_value(index);
	}

	project.valid_entries = project.data.size()-1;

	Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
	Global_color_data_listview(Design_grid_index, project.valid_entries, project.number_collums, change_array, change_array.size());

	texts = str.Info.compare_project.s[lang];
	texts.append(info_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	Hide_progress();

	return 0;
}
