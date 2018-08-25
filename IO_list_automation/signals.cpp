#include "config.h"
#include "signals.h"


#include <stdio.h>
#include <stdlib.h>

#include"libxl.h"
#include "design.h"
#include "MainWindow.h"
#include "Global_Functions.h"

using namespace std;
using namespace IOlistautomation;
using namespace libxl;


struct signal_str signals;
struct object_str objects;
struct learning_str learn;



std::wstring Signals_get_data_switch(int iCol, int index)
{
	wstring cell_text = L"";
	// fill all cells with data

	switch (iCol)
	{
	case 0:	cell_text = signals.data[index].number;
		break;
	case 1:	cell_text = signals.data[index].Cabinet;
		break;
	case 2:	cell_text = signals.data[index].operatyv;
		break;
	case 3:	cell_text = signals.data[index].KKS.Full;
		break;
	case 4:	cell_text = signals.data[index].KKS.Part1;
		break;
	case 5:	cell_text = signals.data[index].KKS.Part2;
		break;
	case 6:	cell_text = signals.data[index].Used;
		break;
	case 7:	cell_text = signals.data[index].Object_type;
		break;
	case 8:	cell_text = signals.data[index].Object_text;
		break;
	case 9:	cell_text = signals.data[index].Extendet_object_text;
		break;
	case 10:	cell_text = signals.data[index].Function_text;
		break;
	case 11:	cell_text = signals.data[index].Function;
		break;
	case 12:	cell_text = signals.data[index].IO_text;
		break;
	case 13:	cell_text = signals.data[index].Module;
		break;
	case 14:	cell_text = signals.data[index].Channel;
		break;
	case 15:	cell_text = signals.data[index].Pin;
		break;
	case 16:	cell_text = signals.data[index].Page;
		break;
	default:cell_text = LPWSTR(L"");
		break;
	}
	return cell_text;
}
void Signals_put_data_switch(int iCol, int index, wstring cell_text)
{
	switch (iCol)
	{
	case 0:	signals.data[index].number = cell_text;
		break;
	case 1:	signals.data[index].Cabinet = cell_text;
		break;
	case 2:	signals.data[index].operatyv = cell_text;
		break;
	case 3:	signals.data[index].KKS.Full = cell_text;
		break;
	case 4:	signals.data[index].KKS.Part1 = cell_text;
		break;
	case 5:	signals.data[index].KKS.Part2 = cell_text;
		break;
	case 6:	signals.data[index].Used = cell_text;
		break;
	case 7:	signals.data[index].Object_type = cell_text;
		break;
	case 8:	signals.data[index].Object_text = cell_text;
		break;
	case 9:	signals.data[index].Extendet_object_text = cell_text;
		break;
	case 10:	signals.data[index].Function_text = cell_text;
		break;
	case 11:	signals.data[index].Function = cell_text;
		break;
	case 12:	signals.data[index].IO_text = cell_text;
		break;
	case 13:	signals.data[index].Module = cell_text;
		break;
	case 14:	signals.data[index].Channel = cell_text;
		break;
	case 15:	signals.data[index].Pin = cell_text;
		break;
	case 16:	signals.data[index].Page = cell_text;
		break;
	}
}
//check if there is data in any variable
int Signals_valid_row_check(int row)
{
	if (signals.data[row].number.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Cabinet.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].operatyv.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Used.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Object_type.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Object_text.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Extendet_object_text.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Function_text.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Function.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].IO_text.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Module.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Channel.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Pin.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Page.empty() == 0)
	{
		return 1;
	}
	return 0;
}



int Signals_get_data_design()
{
	Global_get_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
	if (project.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
		return 1;
	}

	if (signals.valid_entries > 1)
	{
		if (show_confirm_window(conf_signal_overwrite[lang]) == IDOK)
		{
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
			signals.data = {};
			Global_get_width_list(Signals_grid_index,signals.number_collums, signals.collumn_with);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	
	
	strcpy_s(info_txt, sizeof info_txt, info_transfer_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, "->");
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);

	info_write(info_txt);
	Show_progress(prog_transfer_data[lang], project.valid_entries);
	int colon = 0;
	int semi= 0;
	int space = 0;
	wstring tmp_KKS;
	wstring end0_char;
	wstring end1_char;


	signals.valid_entries = project.valid_entries;
	Global_resize_data(Signals_grid_index, signals.valid_entries + 1);

	for (int row = 0; row <= project.valid_entries; row++)
	{
		signals.data[row].number = project.data[row].number;
		signals.data[row].Cabinet = project.data[row].Cabinet;
		signals.data[row].Module = project.data[row].Module;
		signals.data[row].Pin = project.data[row].Pin;
		signals.data[row].Channel = project.data[row].Channel;
		signals.data[row].IO_text = project.data[row].IO_text;
		signals.data[row].Page = project.data[row].Page;

		// IO_signal = (KKS_text) (Object text) ; (extendext object) : (signal function) 

		colon = signals.data[row].IO_text.find(L":");
		semi = signals.data[row].IO_text.find(L";");
		space = signals.data[row].IO_text.find(L" ");

		//check if first word is KKS symbol
		// if atleast one of two last symbols are numers its kks
		if (space != -1)
		{
			tmp_KKS = signals.data[row].IO_text.substr(0, space);
			
			end0_char = tmp_KKS.back();
			end1_char = tmp_KKS.substr(tmp_KKS.size()-2,1);
			space++;
			if ((end0_char.find_first_of(L"0123456789") ==-1) && (end1_char.find_first_of(L"0123456789") == -1))
			{
				tmp_KKS = LPWSTR(L"");
				space = 0;
			}
		}
		else
		{
			tmp_KKS = LPWSTR(L"");
			space = 0;
		}

		signals.data[row].KKS.Full = tmp_KKS;

		if ((colon != -1) && (semi != -1))  // found colon, found semicolon
		{
			signals.data[row].Object_text = signals.data[row].IO_text.substr(space, semi-space);
			signals.data[row].Extendet_object_text = signals.data[row].IO_text.substr(semi+2, colon- semi-2);
			signals.data[row].Function_text = signals.data[row].IO_text.substr(colon + 2);
		}
		else if (semi != -1)						// no colon, found semicolon
		{
			signals.data[row].Object_text = signals.data[row].IO_text.substr(space, semi-space);
			signals.data[row].Extendet_object_text = signals.data[row].IO_text.substr(semi + 2);
			signals.data[row].Function_text = LPWSTR(L"");
		}
		else if (colon != -1)							// found colon, no semicolon
		{
			signals.data[row].Object_text = signals.data[row].IO_text.substr(space,colon-space);
			signals.data[row].Extendet_object_text = LPWSTR(L"");
			signals.data[row].Function_text = signals.data[row].IO_text.substr(colon + 2);
		}
		else												// no colon, no semicolon
		{
			signals.data[row].Object_text = signals.data[row].IO_text.substr(space);
			signals.data[row].Extendet_object_text = LPWSTR(L"");
			signals.data[row].Function_text = LPWSTR(L"");
		}
		set_progress_value(row);
	}

	Hide_progress();
	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	strcpy_s(info_txt, sizeof info_txt, info_transfer_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, design_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, "->");
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);

	info_write(info_txt);
	return 0;

}

KKS_str Signals_KKS_trim(wstring KKS_text)
{
	struct KKS_str KKS;
	int a;
	int i;
	if (KKS_text.empty() == 0)
	{
		a = KKS_text.size() - parameters.KKS_del1 - parameters.KKS_del2;
		if (a > 0)
		{
			KKS.Full = KKS_text.substr(parameters.KKS_del1, a);
			if (KKS.Full.size() < 10)
			{
				i = KKS.Full.size() - 5;
				if (i < 1)
				{
					i = 0;
				}
			}
			else
			{
				i = 5;
			}
			KKS.Part2 = KKS.Full.substr(i, KKS.Full.size() - i);
			KKS.Part1 = KKS.Full.substr(0, KKS.Full.find(KKS.Part2));

			KKS.Full = KKS.Part1;
			if (KKS.Part1.empty() == 0)
			{
				KKS.Full.append(L"_");
			}
			KKS.Full.append(KKS.Part2);
		}
		else
		{
			KKS.Full = L"";
			KKS.Part1 = L"";
			KKS.Part2 = L"";
		}
	}
	else
	{
		KKS.Full = L"";
		KKS.Part1 = L"";
		KKS.Part2 = L"";
	}
	return KKS;
}

int Signals_all_KKS_trim()
{
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	if (signals.valid_entries > 1)
	{
		Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
		int i = 0;
		while (1)
		{			
			if (signals.data[i].KKS.Full.empty() == 0)
			{
				test.test_KKS = signals.data[i].KKS.Full;
				break;
			}
			i++;
			if (i > signals.valid_entries)
			{
				break;
			}
		}

		IOlistautomation::KKS_edit KKS;
		KKS.ShowDialog();
		if (KKS.return_value == 0)
		{
			strcpy_s(info_txt, sizeof info_txt, info_KKS_edit[lang]);
			info_write(info_txt);

			Show_progress(prog_read_data[lang], signals.valid_entries);

			for (int row = 0; row <= signals.valid_entries; row++)
			{
				signals.data[row].KKS = Signals_KKS_trim(signals.data[row].KKS.Full);
			}

			strcpy_s(info_txt, sizeof info_txt, info_KKS_edit[lang]);
			strcat_s(info_txt, sizeof info_txt, error_separator);
			strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
			info_write(info_txt);

			Hide_progress();
			Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
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
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}
	
	return 0;
}


int Signals_learn_data()
{
	if (learn.done == true)
	{
		if (show_confirm_window(conf_learn_overwrite[lang]) == IDOK)
		{
			project.data = {};
			learn.done = false;			

			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, learning_txt[lang]);
			info_write(info_txt);

		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	
	std::wstring file_name = L".\\learning\\";	

	switch (parameters.Language)
	{
	case LT_index:	file_name.append(L"LT");
		break;
	case EN_index:	file_name.append(L"EN");
		break;
	case LV_index:	file_name.append(L"LV");
		break;
	case RU_index:	file_name.append(L"RU");
		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return 1;
		break;
	}
	file_name.append(L".xls");

	ifstream f(file_name.c_str());
	if (f.good()== false)
	{
		string s = wstring_to_string(file_name);

		strcpy_s(err_txt, sizeof err_txt, err_no_learn_file[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		
		strcat_s(err_txt, sizeof err_txt, s.c_str());
		err_write_show(err_txt);
		return 1;
	}

	strcpy_s(info_txt, sizeof info_txt, info_learning[lang]);
	info_write(info_txt);

	Book* book = xlCreateBook();	
	const char* error_lic = "can't read more cells in trial version";
	bool fStringMatch = FALSE;		

	if (book->load(file_name.c_str()))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			int max_rows = sheet->lastRow();
			int max_col = sheet->lastCol();
			const wchar_t* s = L" ";
			wstring texts = L" ";
			const char* error_message = " ";

			Show_progress(prog_learning_data[lang], max_rows);

			// first two rows are for comments
			for (int row = sheet->firstRow()+2; row < max_rows; ++row)
			{			
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
							book->load(file_name.c_str());
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
					if (texts.empty() == 0)
					{
						switch (col)
						{
						case 0:	learn.Valve_name.resize(row - 1);
							learn.Valve_name[row-2] = texts;
							break;
						case 1:	learn.Motor_name.resize(row - 1);
							learn.Motor_name[row-2] = texts;
							break;
						case 2:	learn.Analog_name.resize(row - 1);
							learn.Analog_name[row-2] = texts;
							break;
						case 3:	learn.Cilinder_name.resize(row - 1);
							learn.Cilinder_name[row-2] = texts;
							break;

						case 5:	learn.Function_txt1.resize(row - 1);
							learn.Function_txt1[row-2] = texts;
							break;
						case 6:	learn.Function_txt1_meaning.resize(row - 1);
							learn.Function_txt1_meaning[row-2] = texts;
							break;

						case 8:	learn.Function_txt2_part1.resize(row - 1);
							learn.Function_txt2_part1[row-2] = texts;
							break;
						case 9:	learn.Function_txt2_part2.resize(row - 1);
							learn.Function_txt2_part2[row-2] = texts;
							break;
						case 10:	learn.Function_txt2_meaning.resize(row - 1);
							learn.Function_txt2_meaning[row-2] = texts;
							break;
						}
					}
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

	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_learning[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	learn.done = true;

	return 0;
}

int Signals_find_function()
{
	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	int find_2_1 = 0;
	int find_2_2 = 0;
	int find_1 = 0;

	wstring search_in_extended = L"";
	wstring search_in_function_txt = L"";
	wstring search_for = L"";

	if (learn.done == false)
	{
		if (Signals_learn_data() == 1)
		{
			return 1;
		}
	}

	strcpy_s(info_txt, sizeof info_txt, info_find_function[lang]);
	info_write(info_txt);

	Show_progress(prog_learning_data[lang], signals.valid_entries);

	int size_part1 = learn.Function_txt1.size();
	int size_part2_1 = learn.Function_txt2_part1.size();
	int size_part2_2 = learn.Function_txt2_part2.size();

	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		search_in_function_txt = signals.data[row].Function_text;
		
		if (search_in_function_txt.empty() == 0)
		{
			search_in_extended = signals.data[row].Extendet_object_text;
			std::transform(search_in_function_txt.begin(), search_in_function_txt.end(), search_in_function_txt.begin(), ::tolower);
			std::transform(search_in_extended.begin(), search_in_extended.end(), search_in_extended.begin(), ::tolower);
			
			find_2_2 = -1;
			// finding with 2 parts
			for (int i = 0; i < size_part2_1; ++i)
			{
				search_for = learn.Function_txt2_part1[i];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

				find_2_1 = search_in_extended.find(search_for);
				if (find_2_1 >= 0)
				{
					for (int j = 0; j < size_part2_2; ++j)
					{
						search_for = learn.Function_txt2_part2[i];
						std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

						find_2_2 = search_in_function_txt.find(search_for);
						if (find_2_2 >= 0)
						{
							signals.data[row].Function = learn.Function_txt2_meaning[j];
							break;
						}
					}
					if (find_2_2 >= 0)
					{
						break;
					}
				}
			}
			//finding with 1 part 
			if (find_2_2 != 0)
			{
				for (int i = 0; i < size_part1; ++i)
				{
					search_for = learn.Function_txt1[i];
					std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::tolower);

					find_1 = search_in_function_txt.find(search_for);
					if (find_1 >= 0)
					{
						signals.data[row].Function = learn.Function_txt1_meaning[i];
						break;
					}
				}
			}
		}
		set_progress_value(row);
	}

	Hide_progress();
	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	strcpy_s(info_txt, sizeof info_txt, info_find_function[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	return 0;
}





