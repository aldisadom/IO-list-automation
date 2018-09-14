#include "config.h"
#include "signals.h"


#include <stdio.h>
#include <stdlib.h>

#include"libxl.h"
#include "design.h"
#include "MainWindow.h"
#include "Global_Functions.h"
#include "IO_Form.h"
#include "IO_declare.h"

using namespace std;
using namespace IOlistautomation;
using namespace libxl;


struct signal_str signals;
struct object_str objects;
struct learning_str learn;


// get data from memory to wstring
std::wstring Signals_get_data_switch(int iCol, int index)
{
	switch (iCol)
	{
	case 0:	return signals.data[index].number;
		break;
	case 1:	return signals.data[index].CPU;
		break;
	case 2:	return signals.data[index].Cabinet;
		break;
	case 3:	return signals.data[index].operatyv;
		break;
	case 4:	return signals.data[index].KKS.Full;
		break;
	case 5:	return signals.data[index].KKS.Part1;
		break;
	case 6:	return signals.data[index].KKS.Part2;
		break;
	case 7:	return signals.data[index].Used;
		break;
	case 8:	return signals.data[index].Object_type;
		break;
	case 9:	return signals.data[index].Object_text;
		break;
	case 10:	return signals.data[index].Extendet_object_text;
		break;
	case 11:	return signals.data[index].Function_text;
		break;
	case 12:	return signals.data[index].Function;
		break;
	case 13:	return signals.data[index].IO_text;
		break;
	case 14:	return signals.data[index].Module_name;
		break;
	case 15:	return signals.data[index].Module_type;
		break;
	case 16:	return signals.data[index].Channel;
		break;
	case 17:	return signals.data[index].Pin;
		break;
	case 18:	return signals.data[index].Tag;
		break;
	case 19:	return signals.data[index].Page;
		break;
	default:return LPWSTR(L"");
		break;
	}
}
// put data from wstring to memory
void Signals_put_data_switch(int iCol, int index, wstring cell_text)
{
	switch (iCol)
	{
	case 0:	signals.data[index].number = cell_text;
		break;
	case 1:	signals.data[index].CPU = cell_text;
		break;
	case 2:	signals.data[index].Cabinet = cell_text;
		break;
	case 3:	signals.data[index].operatyv = cell_text;
		break;
	case 4:	signals.data[index].KKS.Full = cell_text;
		break;
	case 5:	signals.data[index].KKS.Part1 = cell_text;
		break;
	case 6:	signals.data[index].KKS.Part2 = cell_text;
		break;
	case 7:	signals.data[index].Used = cell_text;
		break;
	case 8:	signals.data[index].Object_type = cell_text;
		break;
	case 9:	signals.data[index].Object_text = cell_text;
		break;
	case 10:	signals.data[index].Extendet_object_text = cell_text;
		break;
	case 11:	signals.data[index].Function_text = cell_text;
		break;
	case 12:	signals.data[index].Function = cell_text;
		break;
	case 13:	signals.data[index].IO_text = cell_text;
		break;
	case 14:	signals.data[index].Module_name = cell_text;
		break;
	case 15:	signals.data[index].Module_type = cell_text;
		break;
	case 16:	signals.data[index].Channel = cell_text;
		break;
	case 17:	signals.data[index].Pin = cell_text;
		break;
	case 18:	signals.data[index].Tag = cell_text;
		break;
	case 19:	signals.data[index].Page = cell_text;
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
	if (signals.data[row].Module_name.empty() == 0)
	{
		return 1;
	}
	if (signals.data[row].Module_type.empty() == 0)
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


//get data from project to signals
int Signals_get_data_design()
{
	Global_get_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
	if (project.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, design_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	if (signals.valid_entries > 1)
	{
		int result = show_confirm_window(conf_signal_overwrite[lang]);
		if (result == IDYES)
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
	int size_text = 0;
	int signal_row = 0;
	int channel_text_size = 0;

	wstring tmp_KKS;
	wstring end0_char;
	wstring end1_char;
	wstring channel_text;
	wstring test_module;
	wstring test_text = L"";

	signals.valid_entries = project.valid_entries;
	signals.data.resize(signals.valid_entries + 1);

	int max_digits = GetNumberOfDigits(project.valid_entries);
	if ((pow(10, max_digits - 1) * 9) < signals.valid_entries) // if numbers are 90% filed increase digits by one
	{
		max_digits++;
	}

	int result = 0;
	int module_index = 0;
	for (int row = 0; row <= project.valid_entries; row++)
	{
		channel_text = project.data[row].Channel;
		channel_text_size = channel_text.size();

		module_index = Global_Module_index(project.data[row].Module_name);
		if (module_index < 0)
		{
			module_index = Global_Module_index(project.data[row].Channel);
		}

		signals.data[signal_row].Module_type = Global_Module_type(module_index);

		if (channel_text_size>2)
		{
			channel_text = channel_text.substr(channel_text_size - 2);
			channel_text_size = 2;
		}	

		//test if last 2 symbols are numbers
		test_module =int_to_wstring(_wtoi(channel_text.c_str()), channel_text_size);
		if (channel_text.compare(test_module.c_str()) != 0)
		{
			continue;
		}

		signals.data[signal_row].number = int_to_wstring(signal_row, max_digits);
		signals.data[signal_row].Cabinet = project.data[row].Cabinet;
		signals.data[signal_row].Module_name = project.data[row].Module_name;
		signals.data[signal_row].Pin = project.data[row].Pin;
		signals.data[signal_row].Channel = channel_text;
		signals.data[signal_row].IO_text = project.data[row].IO_text;
		signals.data[signal_row].Page = project.data[row].Page;



		// IO_signal = (KKS_text) (Object text) ; (extendext object) : (signal function) 

		colon = signals.data[signal_row].IO_text.find(L":");
		semi = signals.data[signal_row].IO_text.find(L";");
		space = signals.data[signal_row].IO_text.find(L" ");
		size_text = signals.data[signal_row].IO_text.size();


		//check if first word is KKS symbol
		// if atleast one of two last symbols are numers its kks
		if (space != -1)
		{
			tmp_KKS = signals.data[signal_row].IO_text.substr(0, space);
			
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

		int ofset_separator = 1;

		if (semi + ofset_separator >= size_text)
		{
			semi = -1;
		}
		if (colon + ofset_separator >= size_text)
		{
			colon = -1;
		}
		if ((colon >= 0) && (semi >= colon- ofset_separator))
		{
			semi = -1;
		}

		signals.data[signal_row].KKS.Full = tmp_KKS;

		if ((colon != -1) && (semi != -1))  // found colon, found semicolon
		{
			signals.data[signal_row].Object_text = signals.data[signal_row].IO_text.substr(space, semi-space);
			signals.data[signal_row].Extendet_object_text = signals.data[signal_row].IO_text.substr(semi+ ofset_separator, colon- semi- ofset_separator);
			signals.data[signal_row].Function_text = signals.data[signal_row].IO_text.substr(colon + ofset_separator);
		}
		else if (semi != -1)						// no colon, found semicolon
		{
			signals.data[signal_row].Object_text = signals.data[signal_row].IO_text.substr(space, semi-space);
			signals.data[signal_row].Extendet_object_text = signals.data[signal_row].IO_text.substr(semi + ofset_separator);
			signals.data[signal_row].Function_text = LPWSTR(L"");
		}
		else if (colon != -1)							// found colon, no semicolon
		{
			signals.data[signal_row].Object_text = signals.data[signal_row].IO_text.substr(space,colon-space);
			signals.data[signal_row].Extendet_object_text = LPWSTR(L"");
			signals.data[signal_row].Function_text = signals.data[signal_row].IO_text.substr(colon + ofset_separator);
		}
		else												// no colon, no semicolon
		{
			signals.data[signal_row].Object_text = signals.data[signal_row].IO_text.substr(space);
			signals.data[signal_row].Extendet_object_text = LPWSTR(L"");
			signals.data[signal_row].Function_text = LPWSTR(L"");
		}

		// object text
		test_text = signals.data[signal_row].Object_text;
		if (test_text.empty() == 0)
		{
			// removing spaces at end
			size_text = test_text.size()-1;
			result = test_text.find_last_of(L" ");
			while (result == size_text)
			{
				test_text.pop_back();
				size_text = test_text.size()-1;
				result = test_text.find_last_of(L" ");
			}
			// removing spaces at begining
			result = test_text.find_first_of(L" ");
			while (result == 0)
			{
				test_text.erase(0, 1);
				result = test_text.find_first_of(L" ");
			}
			signals.data[signal_row].Object_text = test_text;
		}

		// object extended text
		test_text = signals.data[signal_row].Extendet_object_text;
		if (test_text.empty() == 0)
		{
			// removing spaces at end
			size_text = test_text.size()-1;
			result = test_text.find_last_of(L" ");
			while (result == size_text)
			{
				test_text.pop_back();
				size_text = test_text.size()-1;
				result = test_text.find_last_of(L" ");
			}
			// removing spaces at begining
			result = test_text.find_first_of(L" ");
			while (result == 0)
			{
				test_text.erase(0, 1);
				result = test_text.find_first_of(L" ");
			}
			signals.data[signal_row].Extendet_object_text = test_text;
		}

		// function text
		test_text = signals.data[signal_row].Function_text;
		if (test_text.empty() == 0)
		{
			// removing spaces at end
			size_text = test_text.size()-1;
			result = test_text.find_last_of(L" ");
			while (result == size_text)
			{
				test_text.pop_back();
				size_text = test_text.size()-1;
				result = test_text.find_last_of(L" ");
			}
			// removing spaces at begining
			result = test_text.find_first_of(L" ");
			while (result == 0)
			{
				test_text.erase(0,1);
				result = test_text.find_first_of(L" ");
			}
			signals.data[signal_row].Function_text = test_text;
		}


		signal_row++;
		set_progress_value(row);
	}
	signals.valid_entries = signal_row-1;
	signals.data.resize(signal_row);

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


//KKS triming algorithm removes back ant front parts, and splits into two parts
KKS_str Signals_KKS_trim(wstring KKS_text)
{
	struct KKS_str KKS;
	int a;
	int i;
	if (KKS_text.empty() == 0)
	{
		a = KKS_text.size() - parameters.KKS_del1 - parameters.KKS_del2;
		if (a > 0) // if delete to much clear KKS
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
			// first kks part is first 4 symbols
			// second part is rest symbols from 5
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
//trims all KKS data in signals
int Signals_all_KKS_trim()
{
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	if (signals.valid_entries > 1)
	{
		int i = 0;
		while (1)
		{	
			//searching for first valid KKS in data
			if (signals.data[i].KKS.Full.empty() == 0)
			{
				test.test_KKS = signals.data[i].KKS.Full;
				break;
			}
			i++;
			if (i > signals.valid_entries)
			{
				return 1;
			}
		}

		IOlistautomation::KKS_edit KKS;
		KKS.ShowDialog();	// open KKS edit dialog with example
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


//reads learning data for object and function recognition
int Signals_learn_data()
{
	learn = {};
	
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
						// put data where it bellongs
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

	return 0;
}
//finds functions in signal data
int Signals_find_function()
{
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	int find_2_1 = 0;
	int find_2_2 = 0;
	int find_1 = 0;

	wstring search_in_extended = L"";
	wstring search_in_function_txt = L"";
	wstring search_for = L"";

	if (Signals_learn_data() == 1)
	{
		return 1;
	}
	

	strcpy_s(info_txt, sizeof info_txt, info_find_function[lang]);
	info_write(info_txt);

	Show_progress(prog_learning_data[lang], signals.valid_entries);

	int size_part1 = learn.Function_txt1.size();
	int size_part2_1 = learn.Function_txt2_part1.size();
	int size_part2_2 = learn.Function_txt2_part2.size();

	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		//selecting where to search for normal data
		search_in_function_txt = signals.data[row].Function_text;
		
		if (search_in_function_txt.empty() == 0)
		{
			//selecting where to search for extended data
			search_in_extended = signals.data[row].Extendet_object_text;
			//transforming all data to lowercase
			std::transform(search_in_function_txt.begin(), search_in_function_txt.end(), search_in_function_txt.begin(), ::toupper);
			std::transform(search_in_extended.begin(), search_in_extended.end(), search_in_extended.begin(), ::toupper);
			
			find_2_2 = -1;
			// finding with 2 parts
			for (int i = 0; i < size_part2_1; ++i)
			{
				//selecting what to search and putting to lower case
				search_for = learn.Function_txt2_part1[i];
				std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

				find_2_1 = search_in_extended.find(search_for);
				if (find_2_1 >= 0) // if found data search for part 2
				{
					for (int j = 0; j < size_part2_2; ++j)
					{
						//selecting what to search and putting to lower case
						search_for = learn.Function_txt2_part2[i];
						std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

						find_2_2 = search_in_function_txt.find(search_for);
						if (find_2_2 >= 0) // found part 1 and part 2, put function to signals
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
					//selecting what to search and putting to lower case
					search_for = learn.Function_txt1[i];
					std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

					find_1 = search_in_function_txt.find(search_for);
					if (find_1 >= 0) // found data, put function to signals
					{
						signals.data[row].Function = learn.Function_txt1_meaning[i];
						break;
					}
				}
			}
		}
		set_progress_value(row);
	}

	if (parameters.search_function_in_IO_text>0)
	{
		for (int row = 0; row <= signals.valid_entries; ++row)
		{
			//selecting where to search for normal data
			search_in_function_txt = signals.data[row].IO_text;

			if (search_in_function_txt.empty() == 0 && signals.data[row].Function.empty() == 1)
			{
				//selecting where to search for extended data
				search_in_extended = signals.data[row].Extendet_object_text;
				//transforming all data to lowercase
				std::transform(search_in_function_txt.begin(), search_in_function_txt.end(), search_in_function_txt.begin(), ::toupper);
				std::transform(search_in_extended.begin(), search_in_extended.end(), search_in_extended.begin(), ::toupper);

				find_2_2 = -1;
				// finding with 2 parts
				for (int i = 0; i < size_part2_1; ++i)
				{
					//selecting what to search and putting to lower case
					search_for = learn.Function_txt2_part1[i];
					std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

					find_2_1 = search_in_extended.find(search_for);
					if (find_2_1 >= 0) // if found data search for part 2
					{
						for (int j = 0; j < size_part2_2; ++j)
						{
							//selecting what to search and putting to lower case
							search_for = learn.Function_txt2_part2[i];
							std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

							find_2_2 = search_in_function_txt.find(search_for);
							if (find_2_2 >= 0) // found part 1 and part 2, put function to signals
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
						//selecting what to search and putting to lower case
						search_for = learn.Function_txt1[i];
						std::transform(search_for.begin(), search_for.end(), search_for.begin(), ::toupper);

						find_1 = search_in_function_txt.find(search_for);
						if (find_1 >= 0) // found data, put function to signals
						{
							signals.data[row].Function = learn.Function_txt1_meaning[i];
							break;
						}
					}
				}
			}
			set_progress_value(row);
		}
	}

	Hide_progress();
	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	strcpy_s(info_txt, sizeof info_txt, info_find_function[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	return 0;
}


int Signals_multi_cpu()
{
	GlobalForm::forma->tabControl1->SelectedIndex = Signals_grid_index;

	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	if (signals.data[0].Tag == L"")
	{
		IO_generate();
	}

	strcpy_s(info_txt, sizeof info_txt, info_multi_CPU[lang]);
	info_write(info_txt);

	IOlistautomation::IO_Form Io_forma;
	System::Windows::Forms::DataGridView^ grid = Io_forma.Grid_Module;
//	System::Windows::Forms::DataGridView^ grid_io = Io_forma.Grid_IO;
	Io_forma.IO_form_init();

	grid->Columns[0]->ReadOnly = false;
	grid->Columns[4]->Visible = false;
	grid->Columns[5]->Visible = false;
	grid->Columns[6]->Visible = false;
	grid->Columns[7]->Visible = false;

	IO_show_modules(Io_forma.Grid_Module);
	Io_forma.ShowDialog();

	Show_progress(prog_multi_cpu[lang], grid->RowCount);
	int result = 0;
	wstring text=L"";
	wstring CPU_name = L"";
	wstring Module_name = L"";
	for (int index = 0; index < grid->RowCount; ++index)
	{
		CPU_name = Global_get_cell_value(index, 0, grid);
		text = Global_get_cell_value(index, 2, grid);
		
		for (int row = 0; row <= signals.valid_entries; row++)
		{			
			//test if match	
			if (IO_generate_module(signals.data[row].Cabinet, signals.data[row].Module_name, Module_name)==1)
			{
				continue;
			}
			result = Module_name.compare(text);
			if (result == 0)
			{
				signals.data[row].CPU = CPU_name;
			}
		}
		set_progress_value(index);
	}	

	Hide_progress();

	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	strcpy_s(info_txt, sizeof info_txt, info_multi_CPU[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}




