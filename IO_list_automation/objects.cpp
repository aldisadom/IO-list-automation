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
#include "Global_Functions.h"

using namespace std;
using namespace IOlistautomation;


std::wstring Objects_get_data_switch(int iCol, int index)
{
	wstring cell_text = L"";
	// fill all cells with data

	switch (iCol)
	{
	case 0:	cell_text = objects.data[index].number;
		break;
	case 1:	cell_text = objects.data[index].operatyv;
		break;
	case 2:	cell_text = objects.data[index].KKS;
		break;
	case 3:	cell_text = objects.data[index].Object_type;
		break;
	case 4:	cell_text = objects.data[index].Object_text;
		break;
	default:cell_text = LPWSTR(L"");
		break;
	}
	return cell_text;
}
void Objects_put_data_switch(int iCol, int index, wstring cell_text)
{
	switch (iCol)
	{
	case 0:	objects.data[index].number = cell_text;
		break;
	case 1:	objects.data[index].operatyv = cell_text;
		break;
	case 2:	objects.data[index].KKS = cell_text;
		break;
	case 3:	objects.data[index].Object_type = cell_text;
		break;
	case 4:	objects.data[index].Object_text = cell_text;
		break;
	}
}
//check if there is data in any variable
int Objects_valid_row_check(int row)
{
	if (objects.data[row].number.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].operatyv.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].KKS.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Object_type.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Object_text.empty() == 0)
	{
		return 1;
	}

	return 0;
}




int Objects_find_uniques()
{
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		return 1;
	}

	vector <wstring> temp_KKS;
	vector <wstring> unique_KKS;

	temp_KKS.resize(signals.valid_entries+1);

	Show_progress(prog_uniques_find[lang], project.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_find_uniques[lang]);
	info_write(info_txt);

	for (int index = 0; index <= signals.valid_entries; index++)
	{
		temp_KKS[index] = signals.data[index].KKS.Full;
	}
	std::sort(temp_KKS.begin(), temp_KKS.end());
	unique_copy(temp_KKS.begin(), temp_KKS.end(), back_inserter(unique_KKS));

	if (unique_KKS[0].empty() == 1)
	{
		unique_KKS.erase(unique_KKS.begin());
	}

	int max_digits = GetNumberOfDigits(unique_KKS.size());
	if ((pow(10, max_digits - 1) * 9) < unique_KKS.size()) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	bool transfer_new=false;
	if (objects.valid_entries > 1)
	{
		int size_temp = unique_KKS.size() - 1;
		int i = 0;

		if (unique_KKS.size() == objects.data.size()-1)
		{
			for (int index = 0; index <= size_temp; ++index)
			{
				for (i = 0; i <= size_temp; i++)
				{
					if (unique_KKS[index].compare(objects.data[i].KKS) == 0)
					{
						break;
					}
				}
				if (i > size_temp)
				{
					transfer_new = true;
					break;
				}
			}			
		}
		else
		{
			transfer_new = true;
		}
		if (transfer_new == true)
		{
			
			int new_valid_entries = objects.valid_entries;			
			Show_progress(prog_uniques_find[lang], size_temp);
			for (int index = 0; index <= size_temp; ++index)
			{
				for (i = 0; i <= objects.valid_entries; i++)
				{
					if (unique_KKS[index].compare(objects.data[i].KKS) == 0)
					{
						break;
					}					
				}
				if (i > objects.valid_entries)
				{
					for (int j = 0; j <= signals.valid_entries; ++j)
					{
						if (unique_KKS[index].compare(signals.data[j].KKS.Full) == 0)
						{
							new_valid_entries++;
							Global_resize_data(Objects_grid_index, new_valid_entries + 1);

							objects.data[new_valid_entries].KKS = signals.data[j].KKS.Full;
							objects.data[new_valid_entries].number = int_to_wstring(new_valid_entries, max_digits);
							objects.data[new_valid_entries].Object_text = signals.data[j].Object_text;
							break;
						}
					}
				}
				set_progress_value(index);
			}
			objects.valid_entries = new_valid_entries;

			Hide_progress();
			Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
			return 0;
		}

		if (show_confirm_window(conf_objects_overwrite[lang]) == IDOK)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, objects_txt[lang]);
			objects.data = {};
			Global_get_width_list(Objects_grid_index,objects.number_collums, objects.collumn_with);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}

	objects.valid_entries = unique_KKS.size()-1;
	int size_signals = signals.valid_entries;

	Global_resize_data(Objects_grid_index, objects.valid_entries+1);

	Show_progress(prog_uniques_find[lang], objects.valid_entries);


	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		for (int i = 0; i <= signals.valid_entries; ++i)
		{
			if (unique_KKS[index].compare(signals.data[i].KKS.Full) == 0)
			{
				objects.data[index].KKS = signals.data[i].KKS.Full;
				objects.data[index].number = int_to_wstring(index, max_digits);
				objects.data[index].Object_text = signals.data[i].Object_text;				
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
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	return 0;
}

int Objects_find_objects()
{
	GlobalForm::forma->tabControl1->SelectedIndex = Objects_grid_index;
	int override_all = 0;
	if (learn.done == false)
	{
		if (Signals_learn_data() == 1)
		{
			return 1;
		}
	}	

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
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
		search_in = objects.data[index].Object_text;
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

		if (objects.data[index].Object_type.empty() == 1)
		{
			objects.data[index].Object_type = Object_type;
		}
		else if (override_all == 1)
		{
			objects.data[index].Object_type = Object_type;
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
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	return 0;
}

int Objects_find_operatyv()
{
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
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
		find_1 = objects.data[index].Object_text.find(L"(");
		find_2 = objects.data[index].Object_text.find(L")");

		if (find_1 >= 0 && find_2 >= 0)
		{
			int a= find_2 - find_1-1;
			if (a > 0)
			{
				objects.data[index].operatyv = objects.data[index].Object_text.substr(find_1 + 1, a);
			}			
		}

		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_find_operatyv[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	return 0;
}

int Objects_transfer_to_signals()
{
	IOlistautomation::Object_check_Form forma;
	GlobalForm::forma->tabControl1->SelectedIndex =Signals_grid_index;
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		return 1;
	}
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
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
			if (signals.data[index].KKS.Full.empty() == 0)
			{
				if (objects.data[i].KKS.compare(signals.data[index].KKS.Full) == 0)
				{
					signals.data[index].Object_type = objects.data[i].Object_type;
					signals.data[index].operatyv = objects.data[i].operatyv;
					if (objects.data[i].Object_text.compare(signals.data[index].Object_text) != 0)
					{
						GlobalForm::forma->Signals_grid->FirstDisplayedScrollingRowIndex = index;
						GlobalForm::forma->Signals_grid->CurrentCell = GlobalForm::forma->Signals_grid[8, index];

						test.Object_text = objects.data[i].Object_text;
						test.IO_text = signals.data[index].Object_text;
						test.KKS.Full = signals.data[index].KKS.Full;

						forma.Object_check_init();
						forma.ShowDialog();

						int a = test.KKS.Full.find(L"_");
						if (a > 0)
						{
							signals.data[index].KKS.Part1 = test.KKS.Full.substr(0, a);
							signals.data[index].KKS.Part2 = test.KKS.Full.substr(a+1);

						}
						signals.data[index].KKS.Full = test.KKS.Full;
						signals.data[index].Object_text = test.text_to_copy;
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
	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	return 0;
}




