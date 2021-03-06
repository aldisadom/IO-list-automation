#include "config.h"
#include "MainWindow.h"
#include "Global_Functions.h"

using namespace std;
using namespace System;


HWND confirmWND;

char err_txt[255];
char info_txt[255];

struct parameters_str parameters;
struct test_str test;
struct addres_str adres;

int lang = 0;

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
	wstring new_text = msclr::interop::marshal_as< std::wstring >(text);
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
	wstring text = L"";
	int b = nr_of_digits - GetNumberOfDigits(number);
	
	for (int a = 0; a < b; a++)
	{
		text.append(L"0");
	}
	text.append(to_wstring(number));
	return text;
}


std::string get_time_string()
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
	return ats;
//	strcat_s( at, sizeof at, ats);
}


// writes to info which button is pressed and returns converted to string
std::string button_press_name_write(System::String^ buttonName)
{
	string converted_text = system_string_to_string(buttonName).c_str();
	const char *button_text= converted_text.c_str();

	strcpy_s(info_txt, sizeof info_txt, button_text);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, info_button_press[lang]);
	info_write(info_txt);

	return converted_text;
}



// shows messagebox with button name which function doesnt exists
int Display_no_function(System::String^ buttonName)
{
	string converted_text = system_string_to_string(buttonName).c_str();
	const char *tekstas = converted_text.c_str();

	strcpy_s(info_txt, sizeof info_txt, tekstas);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, info_no_function[lang]);
	info_write(info_txt);

	wstring wstr(info_txt, info_txt + strlen(info_txt));

	int msgboxID = MessageBox(
		NULL,
		wstr.c_str(),
		L"Error",
		NULL
	);	
	return msgboxID;
}
// displays error as messagebox
int Display_error(char *tekstas)
{
	wstring wstr(tekstas, tekstas + strlen(tekstas));
	int msgboxID = MessageBox(
		NULL,
		wstr.c_str(),
		L"Error",
		NULL
	);
	return msgboxID;
}
// displays confirmation window
int show_confirm_window(LPCWSTR tekstas)
{
	int msgboxID = MessageBox(
		NULL,
		tekstas,
		L"Confirmation",
		MB_OKCANCEL | MB_SYSTEMMODAL | MB_TOPMOST
	);
	return msgboxID;
}



//writes error to log file
void err_write(char *tekstas)
{
	FILE *fp;
	string laiks;
	char ats[255];

	laiks = get_time_string();
	strcpy_s(ats, sizeof ats, laiks.c_str());

	fopen_s(&fp, "_error_log.txt", "a");
	fprintf(fp, "%s", ats);
	fprintf(fp, " - %s: ", err_string[lang]);
	fprintf(fp, "%s\n", tekstas);

	fclose(fp);

	info_write(tekstas);
}
//writes error and shows it as messagebox
void err_write_show(char *tekstas)
{
	err_write(tekstas);
	Display_error(tekstas);
}
// writes information to log
void info_write(char *tekstas)
{
	FILE *fp;
	string laiks;
	char ats[255];

	laiks = get_time_string();
	strcpy_s(ats, sizeof ats, laiks.c_str());
	fopen_s(&fp, "_info_log.txt", "a");
	fprintf(fp, "%s - %s\n", ats, tekstas);
	fclose(fp);
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
char parametrai_str[40][255] = { "height", "width" , "debug", "clr_logs_on_start", "excel_row_nr_with_name","CPU","text_Language","SCADA","IO_list_Language","auto_column_with","indirect",
"Beckhoff_vlv", "Beckhoff_hc", "Beckhoff_mot", "Beckhoff_ai", "Beckhoff_fc", "Beckhoff_pid",
"Siemens_vlv", "Siemens_hc", "Siemens_mot", "Siemens_ai", "Siemens_fc", "Siemens_pid",
"ABB_800xA_vlv", "ABB_800xA_hc", "ABB_800xA_mot", "ABB_800xA_ai", "ABB_800xA_fc", "ABB_800xA_pid",
"Schneider_vlv", "Schneider_hc", "Schneider_mot", "Schneider_ai", "Schneider_fc", "Schneider_pid",
"try_import_if_corupt", "paste_sel_match" , "adresing_from_1", "search_function_in_IO_text","ABB_800xA_app_name",
};



int adr_par_retrieve(char * text, addres_pars_str &adr_pars)
{
	char *next_token1 = NULL;
	int index = 0;
	text = strtok_s(text, ",\n", &next_token1);

	while (text != NULL)
	{
		switch (index)
		{
		case 0:	adr_pars.w1.area = atoi(text);
			break;
		case 1:	adr_pars.w1.start_adr = atoi(text);
			break;
		case 2:	adr_pars.w1.offset = atoi(text);
			break;
		case 3:	adr_pars.w2.area = atoi(text);
			break;
		case 4:	adr_pars.w2.start_adr = atoi(text);
			break;
		case 5:	adr_pars.w2.offset = atoi(text);
			break;
		case 6:	adr_pars.cmd.area = atoi(text);
			break;
		case 7:	adr_pars.cmd.start_adr = atoi(text);
			break;
		case 8:	adr_pars.cmd.offset = atoi(text);
			break;
		case 9:	adr_pars.val.area = atoi(text);
			break;
		case 10:	adr_pars.val.start_adr = atoi(text);
			break;
		case 11:	adr_pars.val.offset = atoi(text);
			break;
		case 12:	adr_pars.pars.area = atoi(text);
			break;
		case 13:	adr_pars.pars.start_adr = atoi(text);
			break;
		case 14:	adr_pars.pars.offset = atoi(text);
			break;
		default:
			return 1;
			break;
		}

		index++;
		text = strtok_s(NULL, ",\n", &next_token1);
	}
	return 0;	
}

//puts parameter in structure
int cfg_puts(char *tekstas, struct parameters_str *pars)
{
	char * parametras;
	char * value_text;
	long value;
	char *next_token1 = NULL;
	bool fStringMatch = FALSE;
	int stringo_nr = 0;
	int count = 0;
	string tmp_text = "";
	//geting which parameter it is read
	parametras = strtok_s(tekstas, "=", &next_token1);
	if (parametras == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, tekstas);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, err_cfg_empty_parameter[lang]);
		err_write_show(err_txt);
		return 1;
	}
	//get parameter value
	value_text = strtok_s(NULL, "\n", &next_token1);
	if (value_text == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, parametras);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, err_cfg_empty_value[lang]);
		err_write_show(err_txt);
		return 1;
	}
	// matching parameter whith parameter strings
	count = sizeof parametrai_str / sizeof parametrai_str[0];
	for (int i = 0; i < count; i++)
	{
		fStringMatch = (strcmp(parametrai_str[i], parametras) == 0);
		if (fStringMatch)
		{
			value =atoi(value_text);
			stringo_nr = i;
			break;
		}
	}

	if (!fStringMatch)
	{
		strcpy_s(err_txt, sizeof err_txt, parametras);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, err_cfg_bad_parameter[lang]);
		err_write_show(err_txt);
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
				if (fStringMatch = (strcmp(value_text, Global_get_CPU_name(Beckhoff_index)) == 0))
				{
					pars->CPU = Beckhoff_index;
				}
				else if (fStringMatch = (strcmp(value_text, Global_get_CPU_name(Siemens_index)) == 0))
				{
					pars->CPU = Siemens_index;
				}
				else if (fStringMatch = (strcmp(value_text, Global_get_CPU_name(Schneider_index)) == 0))
				{
					pars->CPU = Schneider_index;
				}
				else if (fStringMatch = (strcmp(value_text, Global_get_CPU_name(ABB_800xA_index)) == 0))
				{
					pars->CPU = ABB_800xA_index;
				}
				else
				{
					pars->CPU = Beckhoff_index;
					strcpy_s(err_txt, sizeof err_txt, parametras);
					strcat_s(err_txt, sizeof err_txt, error_separator);
					strcat_s(err_txt, sizeof err_txt, err_cfg_bad_value[lang]);
					err_write_show(err_txt);
				}
				break;

			case 6:
				if (fStringMatch = (strcmp(value_text, "LT") == 0))
				{
					lang = LT_index;
				}
				else if (fStringMatch = (strcmp(value_text, "EN") == 0))
				{
					lang = EN_index;
				}
				else
				{
					lang = LT_index;
					strcpy_s(err_txt, sizeof err_txt, parametras);
					strcat_s(err_txt, sizeof err_txt, error_separator);
					strcat_s(err_txt, sizeof err_txt, err_cfg_bad_value[lang]);
					err_write_show(err_txt);
				}
				break;
			case 7:
				if (fStringMatch = (strcmp(value_text, "System Platform") == 0))
				{
					pars->SCADA = System_platform;
				}
				else if (fStringMatch = (strcmp(value_text, "WinCC") == 0))
				{
					pars->SCADA = WinCC;
				}				
				else
				{
					pars->SCADA = Beckhoff_index;
					strcpy_s(err_txt, sizeof err_txt, parametras);
					strcat_s(err_txt, sizeof err_txt, error_separator);
					strcat_s(err_txt, sizeof err_txt, err_cfg_bad_value[lang]);
					err_write_show(err_txt);
				}
				break;				
			case 8:
				if (fStringMatch = (strcmp(value_text, "LT") == 0))
				{
					pars->Language = LT_index;
				}
				else if (fStringMatch = (strcmp(value_text, "EN") == 0))
				{
					pars->Language = EN_index;
				}
				else if (fStringMatch = (strcmp(value_text, "LV") == 0))
				{
					pars->Language = LV_index;
				}
				else if (fStringMatch = (strcmp(value_text, "RU") == 0))
				{
					pars->Language = RU_index;
				}
				else
				{
					pars->Language = LT_index;
					strcpy_s(err_txt, sizeof err_txt, parametras);
					strcat_s(err_txt, sizeof err_txt, error_separator);
					strcat_s(err_txt, sizeof err_txt, err_cfg_bad_value[lang]);
					err_write_show(err_txt);
				}
				break;
			case 9:
				pars->auto_column_with = value;
				break;
			case 10:
				pars->indirect = (value !=0);
				break;
			case 11:
				adr_par_retrieve(value_text, adres.Beckhoff.vlv);
				break;
			case 12:
				adr_par_retrieve(value_text, adres.Beckhoff.hc);
				break;
			case 13:
				adr_par_retrieve(value_text, adres.Beckhoff.mot);
				break;
			case 14:
				adr_par_retrieve(value_text, adres.Beckhoff.ai);
				break;
			case 15:
				adr_par_retrieve(value_text, adres.Beckhoff.fc);
				break;
			case 16:
				adr_par_retrieve(value_text, adres.Beckhoff.pid);
				break;
			case 17:
				adr_par_retrieve(value_text, adres.Siemens.vlv);
				break;
			case 18:
				adr_par_retrieve(value_text, adres.Siemens.hc);
				break;
			case 19:
				adr_par_retrieve(value_text, adres.Siemens.mot);
				break;
			case 20:
				adr_par_retrieve(value_text, adres.Siemens.ai);
				break;
			case 21:
				adr_par_retrieve(value_text, adres.Siemens.fc);
				break;
			case 22:
				adr_par_retrieve(value_text, adres.Siemens.pid);
				break;
			case 23:
				adr_par_retrieve(value_text, adres.ABB_800xA.vlv);
				break;
			case 24:
				adr_par_retrieve(value_text, adres.ABB_800xA.hc);
				break;
			case 25:
				adr_par_retrieve(value_text, adres.ABB_800xA.mot);
				break;
			case 26:
				adr_par_retrieve(value_text, adres.ABB_800xA.ai);
				break;
			case 27:
				adr_par_retrieve(value_text, adres.ABB_800xA.fc);
				break;
			case 28:
				adr_par_retrieve(value_text, adres.ABB_800xA.pid);
				break;
			case 29:
				adr_par_retrieve(value_text, adres.Schneider.vlv);
				break;
			case 30:
				adr_par_retrieve(value_text, adres.Schneider.hc);
				break;
			case 31:
				adr_par_retrieve(value_text, adres.Schneider.mot);
				break;
			case 32:
				adr_par_retrieve(value_text, adres.Schneider.ai);
				break;
			case 33:
				adr_par_retrieve(value_text, adres.Schneider.fc);
				break;
			case 34:
				adr_par_retrieve(value_text, adres.Schneider.pid);
				break;
			case 35:
				pars->try_import_if_corupt = value;
				break;
			case 36:
				pars->paste_sel_match = value;
				break;	
			case 37:
				if (value > 0)
				{
					pars->adresing_from_1 = 1;
				}
				else
				{
					pars->adresing_from_1 = 0;
				}
				break;
			case 38:
				if (value > 0)
				{
					pars->search_function_in_IO_text = 1;
				}
				else
				{
					pars->search_function_in_IO_text = 0;
				}
				break;
			case 39:
				tmp_text = value_text;
				pars->ABB_800xA_app_name = string_to_wstring(tmp_text);
				break;
				
			default:
				strcpy_s(err_txt, sizeof err_txt, parametras);
				strcat_s(err_txt, sizeof err_txt, error_separator);
				strcat_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
				err_write_show(err_txt);
				break;
		}
		if (pars->debug)
		{
			strcpy_s(info_txt, sizeof info_txt, parametras);
			strcat_s(info_txt, sizeof info_txt, " = ");
			strcat_s(info_txt, sizeof info_txt, value_text);
			info_write(info_txt);
		}
	}
	return 0;
}
//reads parameters from config file
int cfg_reads(struct parameters_str *params)
{
	FILE *fp;
	errno_t  erroras;
	char str[255];
	int par_klaida;

	erroras = fopen_s(&fp, "_cfg.txt", "r");
	if (erroras != 0) {
		strcpy_s(err_txt, sizeof err_txt, err_no_cfg_file[lang]);
		err_write_show(err_txt);
		return 1;
	}
	while (fgets(str, 255, fp) != NULL)
	{
		if (strcmp(str, "\n") != 0)
		{
			par_klaida = cfg_puts(str, params);
		}
	}
	fclose(fp);
	return 0;
}

