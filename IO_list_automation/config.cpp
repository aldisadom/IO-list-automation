#include "config.h"
#include "MainWindow.h"
#include "Global_Functions.h"


#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#include<sstream>
#include <string>
#include <filesystem>
#include <wchar.h>
#include <codecvt>

#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std::experimental::filesystem;

using namespace std;
using namespace System;


HWND confirmWND;

struct parameters_str parameters;
struct test_str test;
struct addres_str adres;
int IO_form_result = 0;

struct filter_str design_filter;
struct filter_str signal_filter;
struct filter_str object_filter;

int lang = 1;

Dump_names_str Dump_names;

// get number of digits from integer
int GetNumberOfDigits(int i)
{
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

System::String^ string_to_system_string(std::string text)
{
	String^ new_text = gcnew String(text.c_str());
	return new_text;
}
System::String^ wstring_to_system_string(std::wstring text)
{
	String^ new_text = gcnew String(text.c_str());
	return new_text;
}
std::wstring system_string_to_wstring(System::String^ text)
{
	std::wstring new_text = msclr::interop::marshal_as< std::wstring >(text);
	return new_text;
}
std::string system_string_to_string(System::String^ text)
{
	string new_text = msclr::interop::marshal_as< std::string >(text);
	return new_text;
}
std::string wstring_to_string(std::wstring text)
{
	string s(text.begin(), text.end());
	s.assign(text.begin(), text.end());
	return s;
}
std::wstring string_to_wstring(const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());
	return wsTmp;
}



// convert integer to wstring adding 0 bassed on number of digits
std::wstring int_to_wstring(int number, int nr_of_digits)
{	
	std::wstring text = L"";
	int b = nr_of_digits - GetNumberOfDigits(number);
	
	for (int a = 0; a < b; a++)
	{
		text.append(L"0");
	}
	text.append(to_wstring(number));
	return text;
}
// convert wstring to integer
long wstring_to_long(std::wstring text)
{
	string textas = wstring_to_string(text);
	long tmp = atol(textas.c_str());
	return tmp;
}


// convert double to wstring
std::wstring double_to_wstring(double number)
{
	wstring text = L"";

	text.append(to_wstring(number));
	return text;
}
// convert wstring to double
double wstring_to_double(wstring text)
{
	string textas = wstring_to_string(text);
	double tmp = strtod(textas.c_str(), NULL);
	return tmp;
}

std::wstring get_time_string()
{
	char ats[255];
	char tmp[255];
	SYSTEMTIME time;
	GetLocalTime(&time);
	_itoa_s(time.wYear, tmp, sizeof tmp, 10);
	strcpy_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, "-");

	//month
	_itoa_s(time.wMonth, tmp, sizeof tmp, 10);
	if (time.wMonth < 10)
	{		
		strcat_s(ats, sizeof ats, "0");
	}
	strcat_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, "-");

	//day
	_itoa_s(time.wDay, tmp, sizeof tmp, 10);
	if (time.wDay < 10)
	{
		strcat_s(ats, sizeof ats, "0");
	}
	strcat_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, "  ");

	//hour
	_itoa_s(time.wHour, tmp, sizeof tmp, 10);
	if (time.wHour < 10)
	{
		strcat_s(ats, sizeof ats, "0");
	}
	strcat_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, ":");

	//minute
	_itoa_s(time.wMinute, tmp, sizeof tmp, 10);
	if (time.wMinute < 10)
	{
		strcat_s(ats, sizeof ats, "0");
	}
	strcat_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, ":");

	//second
	_itoa_s(time.wSecond, tmp, sizeof tmp, 10);
	if (time.wSecond < 10)
	{
		strcat_s(ats, sizeof ats, "0");
	}
	strcat_s(ats, sizeof ats, tmp);
	strcat_s(ats, sizeof ats, ".");

	//milisecond
	_itoa_s(time.wMilliseconds, tmp, sizeof tmp, 10);
	if (time.wMilliseconds < 100)
	{
		strcat_s(ats, sizeof ats, "0");
	}
	if (time.wMilliseconds < 10)
	{
		strcat_s(ats, sizeof ats, "0");
	}


	strcat_s(ats, sizeof ats, tmp);
	
	return string_to_wstring(ats);
//	strcat_s( at, sizeof at, ats);
}


// writes to info which button is pressed and returns converted to string
std::wstring button_press_name_write(System::String^ buttonName)
{
	wstring converted_text = system_string_to_wstring(buttonName).c_str();

	wstring texts = converted_text;
	texts.append(error_separator);
	texts.append(str.Info.button_press.s[lang]);

	info_write(texts);

	return converted_text;
}



// shows messagebox with button name which function doesnt exists
int Display_no_function(System::String^ buttonName)
{
	wstring converted_text = system_string_to_wstring(buttonName).c_str();

	wstring texts = converted_text;
	texts.append(error_separator);
	texts.append(str.Info.no_function.s[lang]);

	info_write(texts);


	int msgboxID = MessageBox(
		NULL,
		texts.c_str(),
		L"Error",
		NULL
	);	
	return msgboxID;
}
// displays error as messagebox
int Display_error(wstring tekstas)
{
	int msgboxID = MessageBox(
		NULL,
		tekstas.c_str(),
		L"Error",
		NULL
	);
	return msgboxID;
}
// displays confirmation window
int show_confirm_window(wstring tekstas) // IDYES; IDNO; IDCANCEL
{
	
	LPCWSTR tekstas_show = tekstas.c_str();
	int msgboxID = MessageBox(
		NULL,
		tekstas_show,
		L"Confirmation",
		MB_YESNOCANCEL | MB_SYSTEMMODAL | MB_TOPMOST
	);
	return msgboxID;
}



//writes error to log file
void err_write(wstring tekstas)
{
	std::wofstream temp_file("_error_log.txt", std::ios::binary | fstream::app);

	wstring laiks;
	laiks = get_time_string();

	temp_file << laiks;
	temp_file << L" - ";
	temp_file << str.Error.string.s[lang];
	temp_file << L": ";
	temp_file << tekstas;
	temp_file << L"\r\n";
	temp_file.close();

	info_write(tekstas);
}
//writes error and shows it as messagebox
void err_write_show(wstring tekstas)
{
	err_write(tekstas);
	Display_error(tekstas);
}

//writes programming error and shows it as messagebox
void err_prog()
{
	wstring texts = str.Error.cfg_parameter_programing_error.s[lang];
	err_write_show(texts);
}
// writes information to log
void info_write(wstring tekstas)
{
	std::wofstream temp_file("_info_log.txt", std::ios::binary | fstream::app);

	wstring laiks;
	laiks = get_time_string();

	temp_file << laiks;
	temp_file << L" - ";
	temp_file << tekstas;
	temp_file << L"\r\n";
	temp_file.close();
}
// resets all logs
void reset_logs()
{
	remove("_error_log.txt");
	remove("_info_log.txt");
}



// shows progress bar and labels it
void Show_progress(std::wstring text,int max)
{
	String^ MyString = wstring_to_system_string(text);

	GlobalForm::forma->progressBaras->Minimum = 0;
	GlobalForm::forma->progressBaras->Maximum = max;

	GlobalForm::forma->progressBaras->Value = 0;
	GlobalForm::forma->Progress_label->Text = MyString;	//MyString;


	GlobalForm::forma->Progress_label->Visible = true;
	GlobalForm::forma->Progress_label->Show();
	
	GlobalForm::forma->progressBaras->Visible = true;
	GlobalForm::forma->progressBaras->Show();

	GlobalForm::forma->Refresh();
}
//hides progress bar
void Hide_progress()
{
	GlobalForm::forma->progressBaras->Value = 0;

	GlobalForm::forma->progressBaras->Visible = false;
	GlobalForm::forma->progressBaras->Hide();
	
	GlobalForm::forma->Progress_label->Visible = false;
	GlobalForm::forma->Progress_label->Hide();

	GlobalForm::forma->Refresh();
}
// updates progress bar
void set_progress_value(int value)
{
	GlobalForm::forma->progressBaras->Value = value;
}


// parameters that can be added to _cfg file
wstring parametrai_str[38]= { 
L"height",
L"width" ,
L"debug",
L"clr_logs_on_start",
L"excel_row_nr_with_name",
L"CPU",
L"text_Language",
L"SCADA",
L"IO_list_Language",
L"auto_column_with",
L"indirect",
L"try_import_if_corupt",
L"paste_sel_match" ,
L"adresing_from_1",
L"search_function_in_IO_text",
L"ABB_800xA_app_name",
L"separator_function",
L"separator_detailed",
L"number_column_in_excel",
L"KKS_column_in_excel",
L"Section_column_in_excel",
L"Range_min_column_in_excel",
L"Range_max_column_in_excel",
L"Units_column_in_excel",
L"False_text_column_in_excel",
L"True_text_column_in_excel",
L"Revision_column_in_excel",
L"Cable_column_in_excel",
L"Cabinet_column_in_excel",
L"Module_name_column_in_excel",
L"Pin_column_in_excel",
L"Channel_column_in_excel",
L"IO_text_column_in_excel",
L"Page_column_in_excel",
L"Changed_column_in_excel",
L"Delete_if_no_module",
L"Compare_by_IO",
L"CPU_column_in_excel",
};

//puts parameter in structure
int cfg_puts(wstring tekstas, struct parameters_str *pars, int comment_pos)
{
	long value;
	int fStringMatch;
	int stringo_nr = 0;
	int count = 0;
	wstring tmp_text = L"";
	wstring parametras = L"";
	wstring value_text = L"";
	int separator_nr = 0;
	int lenght_value_text = 0;

	//geting which parameter it is read
	separator_nr = tekstas.find(L"=", 0);

	parametras = tekstas.substr(0, separator_nr);

	if (comment_pos > 0)
		lenght_value_text = comment_pos - separator_nr - 2;
	else
		lenght_value_text = tekstas.length() - separator_nr - 1;

	value_text = tekstas.substr(separator_nr + 1, lenght_value_text);
	if (tekstas.empty())
		return 0;

	if (parametras.empty())
	{
		wstring texts = tekstas;
		texts.append(error_separator);
		texts.append(str.Error.cfg_empty_parameter.s[lang]);
		err_write_show(texts);
		return 1;
	}

	if (value_text.empty())
	{
		wstring texts = parametras;
		texts.append(error_separator);
		texts.append(str.Error.cfg_empty_value.s[lang]);
		err_write_show(texts);
		return 1;
	}
	// matching parameter whith parameter strings
	count = sizeof parametrai_str / sizeof parametrai_str[0];
	for (int i = 0; i < count; i++)
	{
		fStringMatch = parametras.compare(parametrai_str[i]);
		if (fStringMatch == 0)
		{
			value = _wtol(value_text.c_str());
			stringo_nr = i;
			break;
		}
	}

	if (fStringMatch != 0)
	{
		wstring texts = parametras;
		texts.append(error_separator);
		texts.append(str.Error.cfg_bad_parameter.s[lang]);
		err_write_show(texts);
		return 1;
	}
	else
	{
		// putting parameter value to structure
		switch (stringo_nr)
		{
			case 0:
				pars->height = value;
				break;
			case 1:
				pars->width = value;
				break;
			case 2:
				pars->debug = value;
				break;
			case 3:
				pars->clr_logs_on_start = value;
				break;
			case 4:
				pars->excel_row_nr_with_name = value;
				break;
			case 5:
				if (fStringMatch = value_text.compare(Global_get_CPU_name(Beckhoff_index)) == 0)
				{
					pars->CPU = Beckhoff_index;
				}
				else if (fStringMatch = value_text.compare(Global_get_CPU_name(Siemens_index)) == 0)
				{
					pars->CPU = Siemens_index;
				}
				else if (fStringMatch = value_text.compare(Global_get_CPU_name(Schneider_index)) == 0)
				{
					pars->CPU = Schneider_index;
				}
				else if (fStringMatch = value_text.compare(Global_get_CPU_name(ABB_800xA_index)) == 0)
				{
					pars->CPU = ABB_800xA_index;
				}
				else
				{
					pars->CPU = Beckhoff_index;

					wstring texts = parametras;
					texts.append(error_separator);
					texts.append(str.Error.cfg_bad_value.s[lang]);
					err_write_show(texts);
				}
				break;

			case 6:
				if (fStringMatch = value_text.compare(str.General.language.s[LT_index]) == 0)
				{
					lang = LT_index;
				}
				else if (fStringMatch = value_text.compare(str.General.language.s[EN_index]) == 0)
				{
					lang = EN_index;
				}
				else
				{
					lang = LT_index;

					wstring texts = parametras;
					texts.append(error_separator);
					texts.append(str.Error.cfg_bad_value.s[lang]);
					err_write_show(texts);
				}
				break;
			case 7:
				if (fStringMatch = value_text.compare(Global_get_scada_name(System_platform_index)) == 0)
				{
					pars->SCADA = System_platform_index;
				}
				else if (fStringMatch = value_text.compare(Global_get_scada_name(WinCC_index)) == 0)
				{
					pars->SCADA = WinCC_index;
				}				
				else
				{
					pars->SCADA = System_platform_index;
					wstring texts = parametras;
					texts.append(error_separator);
					texts.append(str.Error.cfg_bad_value.s[lang]);
					err_write_show(texts);
				}
				break;				
			case 8:
				if (fStringMatch = value_text.compare(str.General.language.s[LT_index]) == 0)
				{
					pars->Language = LT_index;
				}
				else if (fStringMatch = value_text.compare(str.General.language.s[EN_index]) == 0)
				{
					pars->Language = EN_index;
				}
				else if (fStringMatch = value_text.compare(str.General.language.s[LV_index]) == 0)
				{
					pars->Language = LV_index;
				}
				else if (fStringMatch = value_text.compare(str.General.language.s[RU_index]) == 0)
				{
					pars->Language = RU_index;
				}
				else
				{
					pars->Language = LT_index;

					wstring texts = parametras;
					texts.append(error_separator);
					texts.append(str.Error.cfg_bad_value.s[lang]);
					err_write_show(texts);
				}
				break;
			case 9:
				pars->auto_column_with = value;
				break;
			case 10:
				pars->indirect = (value !=0);
				break;			
			case 11:
				pars->try_import_if_corupt = value;
				break;
			case 12:
				pars->paste_sel_match = value;
				break;	
			case 13:
				if (value > 0)
				{
					pars->adresing_from_1 = 1;
				}
				else
				{
					pars->adresing_from_1 = 0;
				}
				break;
			case 14:
				if (value > 0)
				{
					pars->search_function_in_IO_text = 1;
				}
				else
				{
					pars->search_function_in_IO_text = 0;
				}
				break;
			case 15:
				pars->ABB_800xA_app_name = value_text;
				break;
			case 16:
				pars->separator_function = value_text;
				break;
			case 17:
				pars->separator_detailed = value_text;
				break;
			case 18:
				pars->column_in_import.Number = value;
				break;
			case 19:
				pars->column_in_import.KKS = value;
				break;
			case 20:
				pars->column_in_import.Section = value;
				break;
			case 21:
				pars->column_in_import.Range_min = value;
				break;
			case 22:
				pars->column_in_import.Range_max = value;
				break;
			case 23:
				pars->column_in_import.Units = value;
				break;
			case 24:
				pars->column_in_import.False_text = value;
				break;
			case 25:
				pars->column_in_import.True_text = value;
				break;
			case 26:
				pars->column_in_import.Revision = value;
				break;
			case 27:
				pars->column_in_import.Cable = value;
				break;
			case 28:
				pars->column_in_import.Cabinet = value;
				break;
			case 29:
				pars->column_in_import.Module_name = value;
				break;
			case 30:
				pars->column_in_import.Pin = value;
				break;
			case 31:
				pars->column_in_import.Channel = value;
				break;
			case 32:
				pars->column_in_import.IO_text = value;
				break;
			case 33:
				pars->column_in_import.Page = value;
				break;
			case 34:
				pars->column_in_import.Changed = value;
				break;
			case 35:
				pars->Delete_if_no_module = value;
				break;
			case 36:
				pars->Compare_by_IO = value;
				break;		
			case 37:
				pars->column_in_import.CPU = value;
				break;
			default:
				wstring texts = parametras;
				texts.append(error_separator);
				texts.append(str.Error.cfg_parameter_programing_error.s[lang]);
				err_write_show(texts);
				break;
		}
		if (pars->debug)
		{
			wstring texts = parametras;
			texts.append(L" = ");
			texts.append(value_text);
			info_write(texts);
		}
	}
	return 0;
}
//reads parameters from config file
int cfg_reads(struct parameters_str *params, wstring test_mode)
{
	
	int par_klaida = 0;
	wstring test_mode_str;
	wstring file_name = L"_cfg.txt";
	
	if (test_mode.compare(L" ") != 0)
	{
		file_name = L".\\Test data\\IO\\_cfg_";
		file_name.append(test_mode);
		file_name.append(L".txt");
	}

	std::wifstream files(file_name);

	if (files) 
	{
		std::wstring lines;

		while (std::getline(files, lines))
		{
			int result = lines.find(L"#");
			if (result != 0)
				if (lines.compare(L"\n") != 0)
					par_klaida = cfg_puts(lines, params, result);
		}
	}
	else
	{
		wstring texts = str.Error.no_cfg_file.s[lang];
		err_write_show(texts);
		return 1;
	}
	files.close();
	return 0;
}

