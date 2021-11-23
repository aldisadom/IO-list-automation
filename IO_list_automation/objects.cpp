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


int Object_find_obj_link(int index, bool pid_link)
{
	wstring text = objects.data[index].Object_link;
	wstring compare_string;
	int result = 0;
	for (int i = 0; i < objects.valid_entries; i++)
	{
		if (pid_link)
			compare_string = objects.data[i].PID_link;
		else
			compare_string = objects.data[i].Object_link;

		result = compare_string.compare(L"");
		if (result != 0)
		{
			result = text.compare(compare_string);
			if (result >= 0)
				return i;
		}
	}
	wstring texts = objects.data[index].KKS;
	texts.append(error_separator);
	texts.append(str.Error.bad_link.s[lang]);
	texts.append(error_separator);
	texts.append(text);
	err_write_show(texts);
	return -1;
}

// get data from memory to wstring
std::wstring Objects_get_data_switch(int iCol, int index)
{
	switch (iCol)
	{
	case 0:	return objects.data[index].number;
		break;
	case 1:	return objects.data[index].CPU;
		break;
	case 2:	return objects.data[index].operatyv;
		break;
	case 3:	return objects.data[index].KKS;
		break;
	case 4:	return objects.data[index].Object_type;
		break;
	case 5:	return objects.data[index].Object_text;
		break;
	case 6:	return objects.data[index].Object_link;
		break;
	case 7:	return objects.data[index].PID_link;
		break;
	case 8:	return objects.data[index].Lenght;
		break;
	case 9:	return objects.data[index].Adress_val;
		break;
	case 10:	return objects.data[index].Adress_sw1;
		break;
	case 11:	return objects.data[index].Adress_sw2;
		break;
	case 12:	return objects.data[index].Adress_cmd;
		break;
	case 13:	return objects.data[index].Adress_pars;
		break;
	default:return LPWSTR(L"");
		break;
	}
}
// put data from wstring to memory
void Objects_put_data_switch(int iCol, int index, wstring cell_text)
{
	switch (iCol)
	{
	case 0:	objects.data[index].number = cell_text;
		break;
	case 1:	objects.data[index].CPU = cell_text;
		break;
	case 2:	objects.data[index].operatyv = cell_text;
		break;
	case 3:	objects.data[index].KKS = cell_text;
		break;
	case 4:	objects.data[index].Object_type = cell_text;
		break;
	case 5:	objects.data[index].Object_text = cell_text;
		break;
	case 6:	objects.data[index].Object_link = cell_text;
		break;
	case 7:	objects.data[index].PID_link = cell_text;
		break;
	case 8:	objects.data[index].Lenght = cell_text;
		break;
	case 9:	objects.data[index].Adress_val = cell_text;
		break;
	case 10:	objects.data[index].Adress_sw1 = cell_text;
		break;
	case 11:	objects.data[index].Adress_sw2 = cell_text;
		break;
	case 12:	objects.data[index].Adress_cmd = cell_text;
		break;
	case 13:	objects.data[index].Adress_pars = cell_text;
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

int Objects_get_description_lenght()
{
	wstring texts;
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	Show_progress(str.Progress.lenght.s[lang], objects.valid_entries);
	texts = str.Info.lenght.s[lang];
	info_write(texts);

	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		objects.data[index].Lenght = int_to_wstring(objects.data[index].Object_text.size(),0);
		set_progress_value(index);
	}
	Hide_progress();

	texts = str.Info.lenght.s[lang];
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
	return 0;
}

//find unique objects in signals data
int Objects_find_uniques()
{
	wstring texts;
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.collumn_with, false);
	if (signals.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	vector <wstring> temp_KKS;
	vector <wstring> unique_KKS;
	wstring KKS_to_compare;


	temp_KKS.resize(signals.valid_entries+1);

	Show_progress(str.Progress.uniques_find.s[lang], project.valid_entries);
	texts = str.Info.find_uniques.s[lang];
	info_write(texts);

	//put all data to temporaty KKS bufer
	for (int index = 0; index <= signals.valid_entries; index++)
	{
		if (signals.data[index].KKS.Full.empty() == 0)
		{
			temp_KKS[index] = signals.data[index].CPU;
			temp_KKS[index].append(separator);
			temp_KKS[index].append(signals.data[index].KKS.Full);
		}
	}
	// sort and find uniques then transfer further
	std::sort(temp_KKS.begin(), temp_KKS.end());
	unique_copy(temp_KKS.begin(), temp_KKS.end(), back_inserter(unique_KKS));

	// check if first data is empty, then delete it
	if (unique_KKS[0].empty() == 1)
	{
		unique_KKS.erase(unique_KKS.begin());
	}

	int max_digits = GetNumberOfDigits(unique_KKS.size());
	if ((pow(10, max_digits - 1) * 9) < unique_KKS.size()) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	bool transfer_new=false;

	if (objects.valid_entries > 1)
	{
		int size_temp = unique_KKS.size() - 1;
		int i = 0;

		if (unique_KKS.size() == objects.data.size()-1) // after reading data from list there is allways one blank row at end
		{
			//comparing all unique KKS with all objects KKS 
			for (int index = 0; index <= size_temp; ++index)
			{
				for (i = 0; i <= size_temp; i++)
				{
					int result = unique_KKS[index].find(separator);
					if (result > 0)
					{
						KKS_to_compare = unique_KKS[index].substr(0, result);
					}
					else
					{
						KKS_to_compare = L"";
					}

					KKS_to_compare.append(separator);
					KKS_to_compare.append(objects.data[i].KKS);

					if (unique_KKS[index].compare(KKS_to_compare) == 0)
					{
						break;
					}
				}
				if (i > size_temp)
				{
					transfer_new = true; // if there is KKS in uniques that doesnt match in objects, transfer diferences
					break;
				}
			}			
		}
		else // if there is diference in size, transfer diferences
		{
			transfer_new = true;
		}
		if (transfer_new == true)
		{
			//put all new data to end of list
			int new_valid_entries = objects.valid_entries;			
			Show_progress(str.Progress.uniques_find.s[lang], size_temp);
			for (int index = 0; index <= size_temp; ++index)
			{
				for (i = 0; i <= objects.valid_entries; i++)
				{
					int result = unique_KKS[index].find(separator);
					if (result > 0)
					{
						KKS_to_compare = unique_KKS[index].substr(0, result);
					}
					else
					{
						KKS_to_compare = L"";
					}

					KKS_to_compare.append(separator);
					KKS_to_compare.append(objects.data[i].KKS);

					if (unique_KKS[index].compare(KKS_to_compare) == 0)
					{
						break;
					}
				}
				if (i > objects.valid_entries)  // if havent found matching kks addd to end of list
				{
					for (int j = 0; j <= signals.valid_entries; ++j) // find unique KKS in signal data
					{
						int result = unique_KKS[index].find(separator);
						int size_KKS = unique_KKS[index].size();
						if ((result >= 0) && (size_KKS > result) )
						{
							KKS_to_compare = unique_KKS[index].substr(result+1);
						}
						else
						{
							KKS_to_compare = L"";
						}

						if (KKS_to_compare.compare(signals.data[j].KKS.Full) == 0) // when found put signal data to object data
						{
							new_valid_entries++;
							objects.data.resize(new_valid_entries + 1);

							objects.data[new_valid_entries].KKS = signals.data[j].KKS.Full;
							objects.data[new_valid_entries].number = int_to_wstring(new_valid_entries, max_digits);
							objects.data[new_valid_entries].Object_text = signals.data[j].Object_text;
							objects.data[new_valid_entries].CPU = signals.data[j].CPU;
							break;
						}
					}
				}
				set_progress_value(index);
			}
			objects.valid_entries = new_valid_entries;

			Hide_progress();
			Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
			return 0;
		}

		// if everything matches ask for rewrite everything
		int result = show_confirm_window(str.Confirm.objects_overwrite.s[lang]);
		if (result == IDYES)
		{
			texts = str.Info.erase_data.s[lang];
			texts.append(info_separator);
			texts.append(str.General.objects_txt.s[lang]);
			info_write(texts);

			objects.data = {};
			Global_get_width_list(Objects_grid_index,objects.number_collums, objects.collumn_with);
		}
		else
		{
			texts = str.Error.canceled_selection.s[lang];
			err_write(texts);
			return 1;
		}
	}

	objects.valid_entries = unique_KKS.size()-1;
	int size_signals = signals.valid_entries;

	objects.data.resize(objects.valid_entries + 1);

	Show_progress(str.Progress.uniques_find.s[lang], objects.valid_entries);


	for (int index = 0; index <= objects.valid_entries; ++index) // for all unique kks 
	{
		for (int i = 0; i <= signals.valid_entries; ++i) 
		{
			
			KKS_to_compare = signals.data[i].CPU;
			KKS_to_compare.append(separator);
			KKS_to_compare.append(signals.data[i].KKS.Full);

			if (unique_KKS[index].compare(KKS_to_compare) == 0) // match unique KKS to signal KKS, and then transfer signal data to object data 
			{
				objects.data[index].KKS = signals.data[i].KKS.Full;
				objects.data[index].number = int_to_wstring(index, max_digits);
				objects.data[index].Object_text = signals.data[i].Object_text;		
				objects.data[index].CPU = signals.data[i].CPU;
				break;
			}			
		}
		set_progress_value(index);
	}
	Hide_progress();
	texts = str.Info.find_uniques.s[lang];
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
	Objects_get_description_lenght();

	return 0;
}
//find what kind of object it is
int Objects_find_objects()
{
	GlobalForm::forma->tabControl1->SelectedIndex = Objects_grid_index;
	wstring texts;

	if (Signals_learn_data() == 1)
	{
		return 1;
	}


	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	Show_progress(str.Progress.uniques_object_type.s[lang], project.valid_entries);
	texts = str.Info.find_objects.s[lang];
	info_write(texts);

	Show_progress(str.Progress.process_data.s[lang], objects.valid_entries);

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

		//selecting where to search and convert to lowercase
		search_in = objects.data[index].Object_text;
		std::transform(search_in.begin(), search_in.end(), search_in.begin(), ::toupper);

		//search for AI object
		if (find_place < 0)
		{
			for (int j = 0; j < AI_size; ++j)
			{
				//selecting for what to search and convert to lowercase
				search_for = learn.Analog_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = AI_type;
					break;
				}
			}
		}

		//search for VLV object
		if (find_place < 0)
		{
			for (int j = 0; j < Vlv_size; ++j)
			{
				//selecting for what to search and convert to lowercase
				search_for = learn.Valve_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = Vlv_type;
					break;
				}
			}
		}

		//search for HC object
		if (find_place < 0)
		{
			for (int j = 0; j < HC_size; ++j)
			{
				//selecting for what to search and convert to lowercase
				search_for = learn.Cilinder_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = HC_type;
					break;
				}
			}
		}

		//search for Mot object
		if (find_place < 0)
		{
			for (int j = 0; j < Mot_size; ++j)
			{
				//selecting for what to search and convert to lowercase
				search_for = learn.Motor_name[j];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

				find_place = search_in.find(search_for);
				if (find_place >= 0)
				{
					Object_type = Mot_type;
					break;
				}
			}
		}

		if (objects.data[index].Object_type.empty() == 1)  // if no data, but now its found, then put type in objects
		{
			objects.data[index].Object_type = Object_type;
		}
		else if (Object_type.compare(objects.data[index].Object_type) != 0)//if type of data in object exists ask for overwrite
		{
			GlobalForm::forma->Object_grid->FirstDisplayedScrollingRowIndex = index;
			GlobalForm::forma->Object_grid->CurrentCell = GlobalForm::forma->Object_grid[3, index]; // show whitch cell is overwriten

			text_confirm = str.Confirm.objects_type_overwrite.s[lang];
			text_confirm.append(L" --- ");
			text_confirm.append(objects.data[index].Object_type);
			text_confirm.append(L" -> ");
			text_confirm.append(Object_type);

			int result = show_confirm_window(text_confirm.c_str());
			if (result == IDYES)
			{
				objects.data[index].Object_type = Object_type;

			}
			else if (result == IDCANCEL)
			{
				return 0;
			}
		}

		set_progress_value(index);
	}
	Hide_progress();

	texts = str.Info.find_objects.s[lang];
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
	return 0;
}
//find operative marking
int Objects_find_operatyv()
{
	wstring texts;
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	Show_progress(str.Progress.operatyv.s[lang], objects.valid_entries);
	texts = str.Info.find_operatyv.s[lang];
	info_write(texts);

	int find_1;
	int find_2;
	//operative marking are between ()
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

	texts = str.Info.find_operatyv.s[lang];
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
	return 0;
}
//transfer objects data back to signals
int Objects_transfer_to_signals(bool test_mode)
{
	wstring texts;
	IOlistautomation::Object_check_Form forma;
	GlobalForm::forma->tabControl1->SelectedIndex =Signals_grid_index;
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.collumn_with, false);
	if (signals.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.signals_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	Show_progress(str.Progress.transfer_data.s[lang], signals.valid_entries);

	texts = str.Info.transfer_data.s[lang];
	texts.append(info_separator);
	texts.append(str.General.design_txt.s[lang]);
	texts.append(L"->");
	texts.append(str.General.signals_txt.s[lang]);
	info_write(texts);

	//for all signals search matching objects
	for (int index = 0; index <= signals.valid_entries; ++index)  
	{
		for (int i = 0; i <= objects.valid_entries; ++i)
		{
			if (signals.data[index].KKS.Full.empty() == 0)
			{
				if (objects.data[i].KKS.compare(signals.data[index].KKS.Full) == 0)
				{
					// if found transfer
					signals.data[index].Object_type = objects.data[i].Object_type;
					signals.data[index].operatyv = objects.data[i].operatyv;

					// if object text does not match in signals or objects
					if (objects.data[i].Object_text.compare(signals.data[index].Object_text) != 0)
					{
						// show which cell
						GlobalForm::forma->Signals_grid->FirstDisplayedScrollingRowIndex = index;
						GlobalForm::forma->Signals_grid->CurrentCell = GlobalForm::forma->Signals_grid[8, index];

						test.Object_text = objects.data[i].Object_text;
						test.IO_text = signals.data[index].Object_text;
						test.KKS.Full = signals.data[index].KKS.Full;

						//init, and show edit dialog
						forma.Object_check_init();
						if (test_mode == false)
							forma.ShowDialog();

						if ((forma.return_value == Result_Exit ) && test_mode == false)
						{
							Hide_progress();
							texts = str.Info.transfer_data.s[lang];
							texts.append(info_separator);
							texts.append(str.General.design_txt.s[lang]);
							texts.append(L"->");
							texts.append(str.General.signals_txt.s[lang]);
							texts.append(error_separator);
							texts.append(str.General.cancel_txt.s[lang]);
							info_write(texts);
							
							Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
							return 0;
						}

						int a = test.KKS.Full.find(L"_");
						if (a > 0)
						{
							signals.data[index].KKS.Part1 = test.KKS.Full.substr(0, a);
							signals.data[index].KKS.Part2 = test.KKS.Full.substr(a+1);

						}
						if (test_mode == true)
							test.text_to_copy = objects.data[i].Object_text;

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

	texts = str.Info.transfer_data.s[lang];
	texts.append(info_separator);
	texts.append(str.General.design_txt.s[lang]);
	texts.append(L"->");
	texts.append(str.General.signals_txt.s[lang]);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
	return 0;
}




