#include "config.h"
#include "MainWindow.h"

using namespace std;
using namespace System;



HWND confirmWND;

char err_txt[255];
char info_txt[255];

struct parameters_str parameters;

int GetNumberOfDigits(int i)
{
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

String^ wstring_to_system_string(wstring text)
{
	String^ new_text = gcnew String(text.c_str());
	return new_text;
}

wstring system_string_to_wstring(System::String^ text)
{
	wstring new_text = msclr::interop::marshal_as< std::wstring >(text);
	return new_text;
}

string system_string_to_string(System::String^ text)
{
	string new_text = msclr::interop::marshal_as< std::string >(text);
	return new_text;
}

wstring int_to_wstring(int number, int nr_of_digits)
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

string laikas()
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


int Display_no_function(System::String^ buttonName)
{
	string converted_text = system_string_to_string(buttonName).c_str();
	const char *tekstas = converted_text.c_str();
	wstring wstr(tekstas, tekstas + strlen(tekstas));
	wstr.append(L" --- no such function, maybe it will be ready soon");
	
	strcpy_s(err_txt, sizeof err_txt, tekstas);
	strcat_s(err_txt, sizeof err_txt, " --- Buvo bandyta atidaryti, bet nera tokios funkcijos");
	info_write(err_txt);
	int msgboxID = MessageBox(
		NULL,
		wstr.c_str(),
		L"Error",
		NULL
	);	
	return msgboxID;
}

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

void err_write_show(char *tekstas)
{
	FILE *fp;
	string laiks;
	char ats[255];

	laiks=laikas();
	strcpy_s(ats, sizeof ats, laiks.c_str());

	fopen_s(&fp, "_error_log.txt", "a");
	fprintf(fp, "%s - Klaida: %s\n", ats, tekstas);
	fclose(fp);
	Display_error(tekstas);
}

void info_write(char *tekstas)
{
	FILE *fp;
	string laiks;
	char ats[255];

	laiks = laikas();
	strcpy_s(ats, sizeof ats, laiks.c_str());
	fopen_s(&fp, "_info_log.txt", "a");
	fprintf(fp, "%s - %s\n", ats, tekstas);
	fclose(fp);
}

void reset_logs()
{
	remove("_error_log.txt");
	remove("_info_log.txt");
}



void Show_progress(wstring text,int max)
{
	String^ MyString = wstring_to_system_string(text);

	GlobalForm::forma->progressBaras->Minimum = 0;
	GlobalForm::forma->progressBaras->Maximum = max;

	GlobalForm::forma->progressBaras->Value = 0;
	GlobalForm::forma->Progress_label->Text = MyString;	//MyString;
//	GlobalForm::forma->Progress_label->BackColor = System::Drawing::Color::Transparent;

	GlobalForm::forma->Progress_label->Visible = true;
	GlobalForm::forma->Progress_label->Show();
	
	GlobalForm::forma->progressBaras->Visible = true;
	GlobalForm::forma->progressBaras->Show();

	GlobalForm::forma->Refresh();
}

void Hide_progress()
{
	GlobalForm::forma->progressBaras->Value = 0;

	GlobalForm::forma->progressBaras->Visible = false;
	GlobalForm::forma->progressBaras->Hide();
	
	GlobalForm::forma->Progress_label->Visible = false;
	GlobalForm::forma->Progress_label->Hide();

	GlobalForm::forma->Refresh();
}


void set_progress_value(int value)
{
	GlobalForm::forma->progressBaras->Value = value;
}

char parametrai_str[5][255] = { "height", "width" , "debug", "clr_logs_on_start", "excel_row_nr_with_name"};

int cfg_puts(char *tekstas, struct parameters_str *pars)
{
	char * parametras;
	char * skaicius;
	long numeris;
	char *next_token1 = NULL;
	bool fStringMatch = FALSE;
	int stringo_nr = 0;
	int count = 0;

	parametras = strtok_s(tekstas, "=", &next_token1);
	if (parametras == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, "Tuscias parametras eiluteje");
		err_write_show(err_txt);
		return 1;
	}
	skaicius = strtok_s(NULL, "\n", &next_token1);
	if (skaicius == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, parametras);
		strcat_s(err_txt, sizeof err_txt, " --- Nera skaiciaus parametrai");
		err_write_show(err_txt);
		return 1;
	}

	count = sizeof parametrai_str / sizeof parametrai_str[0];
	for (int i = 0; i < count; i++)
	{
		fStringMatch = (strcmp(parametrai_str[i], parametras) == 0);
		if (fStringMatch)
		{
			numeris=atoi(skaicius);
			stringo_nr = i;
			break;
		}
	}

	if (!fStringMatch)
	{
		strcpy_s(err_txt, sizeof err_txt, parametras);
		strcat_s(err_txt, sizeof err_txt, " --- Neegzistuojantis parametras");
		err_write_show(err_txt);
		return 1;
	}
	else
	{
		switch (stringo_nr)
		{
			case 0:
				pars->height = numeris;
				break;
			case 1:
				pars->width = numeris;
				break;
			case 2:
				pars->debug = numeris;
				break;
			case 3:
				pars->clr_logs_on_start = numeris;
				break;
			case 4:
				pars->excel_row_nr_with_name = numeris;
				break;
			default:
				strcpy_s(err_txt, sizeof err_txt, parametras);
				strcat_s(err_txt, sizeof err_txt, " --- ups!!! Programos klaida, neidetas parametras, ji reikia pasalinti is _cfg.txt arba suprogramuoti :)");
				err_write_show(err_txt);
				break;
		}
		if (pars->debug)
		{
			strcpy_s(info_txt, sizeof info_txt, parametras);
			strcat_s(info_txt, sizeof info_txt, " = ");
			strcat_s(info_txt, sizeof info_txt, skaicius);
			info_write(info_txt);
		}
	}
	return 0;
}

int cfg_reads(struct parameters_str *params)
{
	FILE *fp;
	errno_t  erroras;
	char str[255];
	int par_klaida;

	erroras = fopen_s(&fp, "_cfg.txt", "r");
	if (erroras != 0) {
		strcpy_s(err_txt, sizeof err_txt, "_cfg.txt --- Nepavyko atidaryti konfiguracinio failo");
		err_write_show(err_txt);
		return 1;
	}
	while (fgets(str, 255, fp) != NULL)
	{
		par_klaida=cfg_puts(str, params);
	}
	fclose(fp);
	return 0;
}
