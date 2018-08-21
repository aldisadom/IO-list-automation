#include "config.h"
#include "objects.h"

#include <stdio.h>
#include <stdlib.h>

#include "signals.h"
#include "design.h"
#include "MainWindow.h"
#include "Object_check_Form.h"

#include "config.h"
#include "signals.h"

using namespace std;
using namespace IOlistautomation;


void Objects_put_with_list()
{
	int a = objects.collumn_with.size();
	if (a > 0 && parameters.auto_column_with == 0)
	{
		GlobalForm::forma->Object_grid->AutoResizeColumns();
		for (int i = 0; i < a; i++)
		{
			GlobalForm::forma->Object_grid->Columns[i]->Width = objects.collumn_with[i];
		}
	}
	else
	{
		GlobalForm::forma->Object_grid->AutoResizeColumns();
	}
}

void Objects_get_with_list()
{
	int a = GlobalForm::forma->Object_grid->ColumnCount;
	objects.collumn_with.resize(a);

	for (int i = 0; i < a; i++)
	{
		objects.collumn_with[i] = GlobalForm::forma->Object_grid->Columns[i]->Width;
	}
}

int Objects_find_uniques()
{
	Signals_get_data_listview();
	if (signals.valid_entries < 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		return 1;
	}

	vector <wstring> temp_KKS;
	vector <wstring> unique_KKS;
	if (objects.valid_entries > 1)
	{
		if (show_confirm_window(conf_objects_overwrite[lang]) == IDOK)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
			objects = {};
			Objects_delete_list();
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}

	temp_KKS.resize(signals.valid_entries+1);

	Show_progress(prog_uniques_find[lang], project.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_find_uniques[lang]);
	info_write(info_txt);

	for (int index = 0; index <= signals.valid_entries; index++)
	{
		temp_KKS[index] = signals.KKS[index].Full;
	}
	std::sort(temp_KKS.begin(), temp_KKS.end());
	unique_copy(temp_KKS.begin(), temp_KKS.end(), back_inserter(unique_KKS));

	if (unique_KKS[0].empty() == 1)
	{
		unique_KKS.erase(unique_KKS.begin());
	}

	objects.valid_entries = unique_KKS.size()-1;
	int size_signals = signals.valid_entries;

	Object_resize_data(objects.valid_entries+1);

	Show_progress(prog_uniques_find[lang], objects.valid_entries);

	int max_digits = GetNumberOfDigits(project.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < project.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		for (int i = 0; i <= signals.valid_entries; ++i)
		{
			if (unique_KKS[index].compare(signals.KKS[i].Full) == 0)
			{
				objects.KKS[index] = signals.KKS[i].Full;
				objects.number[index] = int_to_wstring(index, max_digits);
				objects.Object_text[index] = signals.Object_text[i];				
				break;
			}			
		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_find_uniques[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Objects_put_data_listview();
	return 0;
}


int Objects_find_objects()
{
	GlobalForm::forma->tabControl1->SelectedIndex = 2;
	int override_all = 0;
	if (learn.done == false)
	{
		if (Signals_learn_data() == 1)
		{
			return 1;
		}
	}	

	Objects_get_data_listview();
	if (objects.valid_entries < 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		return 1;
	}

	Show_progress(prog_uniques_object_type[lang], project.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_find_objects[lang]);
	info_write(info_txt);

	Show_progress(prog_process_data[lang], objects.valid_entries);


	wstring search_in = L"";
	wstring search_for=L"";
	wstring Object_type = L"";
	wstring text_confirm = L"";

	int AI_size = learn.Analog_name.size()-1;
	int Vlv_size = learn.Valve_name.size() - 1;
	int Mot_size = learn.Motor_name.size() - 1;
	int HC_size = learn.Cilinder_name.size() - 1;
	int find_place = 0;

	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		Object_type = L"";
		find_place = -1;
		search_in = objects.Object_text[index];
		std::transform(search_in.begin(), search_in.end(), search_in.begin(), ::tolower);
		if (find_place < 0)
		{
			for (int j = 0; j < AI_size; ++j)
			{
				search_for = learn.Analog_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = L"AI";
					break;
				}
			}
		}
		if (find_place < 0)
		{
			for (int j = 0; j < Vlv_size; ++j)
			{
				search_for = learn.Valve_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = L"VLV";
					break;
				}
			}
		}
		if (find_place < 0)
		{
			for (int j = 0; j < HC_size; ++j)
			{
				search_for = learn.Cilinder_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = L"HC";
					break;
				}
			}
		}
		if (find_place < 0)
		{
			for (int j = 0; j < Mot_size; ++j)
			{
				search_for = learn.Motor_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = L"MOT";
					break;
				}
			}
		}

		if (objects.Object_type[index].empty() == 1)
		{
			objects.Object_type[index] = Object_type;
		}
		else if (override_all == 1)
		{
			objects.Object_type[index] = Object_type;
		}
		else
		{
			GlobalForm::forma->Object_grid->FirstDisplayedScrollingRowIndex = index;
			GlobalForm::forma->Object_grid->CurrentCell = GlobalForm::forma->Object_grid[3, index];

			text_confirm = conf_objects_type_overwrite[lang];
			text_confirm.append(L" --- ");
			text_confirm.append(Object_type);
			if (show_confirm_window(text_confirm.c_str()) == IDOK)
			{
				override_all = 1;
			}
		}

		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_find_objects[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Objects_put_data_listview();
	return 0;
}

int Objects_find_operatyv()
{
	Objects_get_data_listview();
	if (objects.valid_entries < 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		return 1;
	}

	Show_progress(prog_operatyv[lang], objects.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_find_operatyv[lang]);
	info_write(info_txt);

	int find_1;
	int find_2;

	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		find_1 = objects.Object_text[index].find(L"(");
		find_2 = objects.Object_text[index].find(L")");

		if (find_1 >= 0 && find_2 >= 0)
		{
			int a= find_2 - find_1-1;
			if (a > 0)
			{
				objects.operatyv[index] = objects.Object_text[index].substr(find_1 + 1, a);
			}			
		}

		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_find_operatyv[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Objects_put_data_listview();
	return 0;
}

int Objects_transfer_to_signals()
{
	IOlistautomation::Object_check_Form forma;
	GlobalForm::forma->tabControl1->SelectedIndex = 1;
	Signals_get_data_listview();
	if (signals.valid_entries < 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		return 1;
	}
	Objects_get_data_listview();
	if (objects.valid_entries < 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		return 1;
	}

	Show_progress(prog_transfer_data[lang], signals.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_transfer_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, "->");
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	info_write(info_txt);

	for (int index = 0; index <= signals.valid_entries; ++index)
	{
		for (int i = 0; i <= objects.valid_entries; ++i)
		{
			if (signals.KKS[index].Full.empty() == 0)
			{
				if (objects.KKS[i].compare(signals.KKS[index].Full) == 0)
				{
					signals.Object_type[index] = objects.Object_type[i];
					signals.operatyv[index] = objects.operatyv[i];
					if (objects.Object_text[i].compare(signals.Object_text[index]) != 0)
					{
						GlobalForm::forma->Signals_grid->FirstDisplayedScrollingRowIndex = index;
						GlobalForm::forma->Signals_grid->CurrentCell = GlobalForm::forma->Signals_grid[8, index];

						test.Object_text = objects.Object_text[i];
						test.IO_text = signals.Object_text[index];
						test.KKS.Full = signals.KKS[index].Full;

						forma.Object_check_init();
						forma.ShowDialog();

						int a = test.KKS.Full.find(L"_");
						if (a > 0)
						{
							signals.KKS[index].Part1 = test.KKS.Full.substr(0, a);
							signals.KKS[index].Part2 = test.KKS.Full.substr(a+1);

						}
						signals.KKS[index].Full = test.KKS.Full;
						signals.Object_text[index] = test.text_to_copy;
					}
					break;
				}
			}
		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_transfer_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, "->");
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Signals_put_data_listview();
	return 0;
}


void Object_resize_data(int size)
{
	objects.number.resize(size);
	objects.operatyv.resize(size);
	objects.Object_text.resize(size);
	objects.KKS.resize(size);
	objects.Object_type.resize(size);
}

void Objects_put_data_listview()
{
	Objects_delete_list();
	GlobalForm::forma->Update();
	int iCol;
	int max_digits = GetNumberOfDigits(objects.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < objects.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	Show_progress(prog_grid_put[lang], objects.valid_entries);

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
	info_write(info_txt);


	// Add the columns.
	GlobalForm::forma->Object_grid->ColumnCount = objects.number_collums + 1;

	for (iCol = 0; iCol <= objects.number_collums; iCol++)
	{
		// Load the names of the column headings from the string resources.
		GlobalForm::forma->Object_grid->Columns[iCol]->Name = wstring_to_system_string(objects.column_name[iCol]);
	}

	wstring cell_text = L"";


	for (int index = 0; index <= objects.valid_entries; index++)
	{
		GlobalForm::forma->Object_grid->Rows->Add();

		// fill all cells with data
		for (iCol = 0; iCol <= objects.number_collums; iCol++)
		{
			switch (iCol)
			{
			case 0:	cell_text = objects.number[index];
				break;
			case 1:	cell_text = objects.operatyv[index];
				break;
			case 2:	cell_text = objects.KKS[index];
				break;			
			case 3:	cell_text = objects.Object_type[index];
				break;
			case 4:	cell_text = objects.Object_text[index];
				break;			
			default:cell_text = LPWSTR(L"");
				break;
			}
			String^ textas = wstring_to_system_string(cell_text);

			// Insert items into the list.
			GlobalForm::forma->Object_grid->Rows[index]->Cells[iCol]->Value = textas;
		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	GlobalForm::forma->tabControl1->SelectedIndex = 2;

	Objects_put_with_list();
	GlobalForm::forma->Update();
}

void Objects_get_data_listview()
{

	if (GlobalForm::forma->Object_grid->RowCount > 0)
	{
		objects.valid_entries = GlobalForm::forma->Object_grid->RowCount - 1;
		Object_resize_data(objects.valid_entries + 1);

		objects.number_collums = GlobalForm::forma->Object_grid->ColumnCount - 1;

		Show_progress(prog_grid_take[lang], objects.valid_entries);

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
		info_write(info_txt);

		wstring cell_text = L"";

		int iCol;
		for (iCol = 0; iCol <= objects.number_collums; iCol++)
		{
			objects.column_name[iCol] = system_string_to_wstring(GlobalForm::forma->Object_grid->Columns[iCol]->Name);
		}

		for (int index = 0; index <= objects.valid_entries; index++)
		{

			// fill all cells with data
			for (iCol = 0; iCol <= objects.number_collums; iCol++)
			{
				cell_text = system_string_to_wstring(GlobalForm::forma->Object_grid->Rows[index]->Cells[iCol]->FormattedValue->ToString());

				switch (iCol)
				{
				case 0:	objects.number[index] = cell_text;
					break;
				case 1:	objects.operatyv[index] = cell_text;
					break;
				case 2:	objects.KKS[index] = cell_text;
					break;
				case 3:	objects.Object_type[index] = cell_text;
					break;
				case 4:	objects.Object_text[index] = cell_text;
					break;
				}
			}
			set_progress_value(index);
		}
		Hide_progress();

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
		info_write(info_txt);

		if (unstable_release == 1)
		{
			Objects_save_data(true, " ");
		}
		Objects_get_with_list();
	}
	else
	{
		objects = {};
	}
}

void Objects_delete_list()
{
	GlobalForm::forma->Object_grid->Rows->Clear();
	GlobalForm::forma->Object_grid->Columns->Clear();
}



int Objects_save_data(bool auto_save, std::string file_name_global)
{
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = "Save document |*.osave" +
		"|All Files|*.*";
	sfd->FileName = "Project";

	wstring cell_text = L"Objects";
	string extension = ".osave";
	std::string file_name = "_autosave";
	file_name.append(extension);


	if (objects.valid_entries <= 0)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
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
		Show_progress(prog_save[lang], objects.valid_entries);
	}
	fopen_s(&outFile, file_name.c_str(), "w+,ccs=UTF-8");

	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
	info_write(info_txt);

	if (outFile == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_file_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	if (auto_save == 0)
	{
		Objects_get_data_listview();
	}


	cell_text.append(L"\n");
	const wchar_t* x = cell_text.c_str();


	for (iCol = 0; iCol <= objects.number_collums; iCol++)
	{
		cell_text.append(objects.column_name[iCol]);
		cell_text.append(separator);
	}

	cell_text.append(L"\n");
	x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);

	wstring cell_text_write;

	for (int index = 0; index <= objects.valid_entries; index++)
	{
		cell_text_write = L"";
		// fill all cells with data
		for (iCol = 0; iCol <= objects.number_collums; iCol++)
		{
			switch (iCol)
			{
			case 0:	cell_text = objects.number[index];
				break;
			case 1:	cell_text = objects.operatyv[index];
				break;
			case 2:	cell_text = objects.KKS[index];
				break;
			case 3:	cell_text = objects.Object_type[index];
				break;
			case 4:	cell_text = objects.Object_text[index];
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
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}

int Objects_Load_data(std::string file_name_global)
{
	wchar_t cmp_text[255] = L"Objects";

	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = "Load document |*.osave" +
		"|All Files|*.*";
	string extension = ".osave";

	if (objects.valid_entries > 0)
	{
		if (show_confirm_window(conf_objects_overwrite[lang]) == IDOK)
		{
			objects = {};
			Objects_delete_list();

			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	Show_progress(prog_load[lang], 100);

	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
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
			strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
			err_write_show(err_txt);
			return 1;
		}

		wchar_t x[1023];
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
			strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
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
			strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
			err_write_show(err_txt);
			return 1;
		}
		while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
		{
			objects.number_collums = iCol;
			objects.column_name.resize(objects.number_collums + 1);
			objects.column_name[iCol] = cell_text;
			iCol++;
			cell_text = wcstok_s(NULL, separator, &next_token1);
		}
		int a = 0;

		while (fgetws(x, sizeof x, inFile) != NULL)
		{
			objects.valid_entries = index;
			Object_resize_data(index + 1);
			iCol = 0;

			cell_text = wcstok_s(x, separator, &next_token1);
			while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
			{

				if (wcscmp(cell_text, L" ") != 0)
				{
					switch (iCol)
					{
					case 0:	objects.number[index] = cell_text;
						break;					
					case 1:	objects.operatyv[index] = cell_text;
						break;
					case 2:	objects.KKS[index] = cell_text;
						break;					
					case 3:	objects.Object_type[index] = cell_text;
						break;
					case 4:	objects.Object_text[index] = cell_text;
						break;
					}
				}
				iCol++;
				cell_text = wcstok_s(NULL, separator, &next_token1);
			}
			a++;
			index++;
			if (a > 100)
			{
				a = a - 100;
			}
			set_progress_value(a);
		}
		fclose(inFile);

		Hide_progress();


	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Objects_put_data_listview();
	return 0;

}