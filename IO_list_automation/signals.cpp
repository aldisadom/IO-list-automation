#include "config.h"
#include "signals.h"
#include "MainWindow.h"

struct signal_str signals;
struct object_str objects;

void dummy_function()
{
	int row = 1;
	int max_rows = 100;
	int a = 0;
	strcpy_s(info_txt, sizeof info_txt, "Skaitomi duomenys is excelio");
	info_write(info_txt);
	Show_progress( L"Skaitomi duomenys",100);


	set_progress_value(a);


	Hide_progress();
	strcpy_s(info_txt, sizeof info_txt, "Skaitomi duomenys is excelio -- Done");
	info_write(info_txt);

}


void Signals_get_data_design()
{
	Project_get_data_listview(true);
	strcpy_s(info_txt, sizeof info_txt, "Perkeliami duomenys signalams");
	info_write(info_txt);
	Show_progress( L"Perkeliami duomenys signalams", project.valid_entries);
	int colon = 0;
	int semi= 0;
	int space = 0;
	wstring tmp_KKS;
	wstring end0_char;
	wstring end1_char;

	Signals_resize_data(project.valid_entries + 1);

	for (int row = 0; row <= project.valid_entries; row++)
	{
		signals.number[row] = project.number[row];
		signals.Cabinet[row] = project.Cabinet[row];
		signals.Module[row] = project.Module[row];
		signals.Pin[row] = project.Pin[row];
		signals.Channel[row] = project.Channel[row];
		signals.IO_text[row] = project.IO_text[row];
		signals.Page[row] = project.Page[row];

		// IO_signal = (KKS_text) (Object text) ; (extendext object) : (signal function) 

		colon = signals.IO_text[row].find(L":");
		semi = signals.IO_text[row].find(L";");
		space = signals.IO_text[row].find(L" ");

		//check if first word is KKS symbol
		// if atleast one of two last symbols are numers its kks
		if (space != -1)
		{
			tmp_KKS = signals.IO_text[row].substr(0, space);
			
			end0_char = tmp_KKS.back();
			end1_char = tmp_KKS.substr(tmp_KKS.size()-2,1);

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

		signals.KKS[row] = tmp_KKS;

		if ((colon != -1) && (semi != -1))  // found colon, found semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space, semi);
			signals.Extendet_object_text[row] = signals.IO_text[row].substr(semi+1, colon- semi);
			signals.Function_text[row] = signals.IO_text[row].substr(colon + 1);
		}
		else if (semi != -1)						// no colon, found semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space, semi);
			signals.Extendet_object_text[row] = signals.IO_text[row].substr(semi + 1);
			signals.Function_text[row] = LPWSTR(L"");
		}
		else if (colon != -1)							// found colon, no semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space,colon);
			signals.Extendet_object_text[row] = LPWSTR(L"");
			signals.Function_text[row] = signals.IO_text[row].substr(colon + 1);
		}
		else												// no colon, no semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space);
			signals.Extendet_object_text[row] = LPWSTR(L"");
			signals.Function_text[row] = LPWSTR(L"");
		}

		// filling other simbols in blank 
		signals.KKS1[row] = LPWSTR(L"");
		signals.KKS2[row] = LPWSTR(L"");
		signals.Object_type[row]=0;

		set_progress_value(row);
	}

	Hide_progress();
	strcpy_s(info_txt, sizeof info_txt, "Perkeliami duomenys signalams -- Done");
	info_write(info_txt);

}

void Signals_resize_data(int size)
{
	signals.number.resize(size);
	signals.Cabinet.resize(size);
	signals.Module.resize(size);
	signals.Pin.resize(size);
	signals.Channel.resize(size);
	signals.IO_text.resize(size);
	signals.Page.resize(size);

	signals.Object_text.resize(size);
	signals.Extendet_object_text.resize(size);
	signals.Function_text.resize(size);
	signals.KKS.resize(size);
	signals.KKS1.resize(size);
	signals.KKS2.resize(size);
	signals.Object_type.resize(size);
}

void Signals_delete_row(int row)
{
	signals.number.erase(signals.number.begin() + row);
	signals.Cabinet.erase(signals.Cabinet.begin() + row);
	signals.Module.erase(signals.Module.begin() + row);
	signals.Pin.erase(signals.Pin.begin() + row);
	signals.Channel.erase(signals.Channel.begin() + row);
	signals.IO_text.erase(signals.IO_text.begin() + row);
	signals.Page.erase(signals.Page.begin() + row);

	signals.Object_text.erase(signals.Object_text.begin() + row);
	signals.Extendet_object_text.erase(signals.Extendet_object_text.begin() + row);
	signals.Function_text.erase(signals.Function_text.begin() + row);
	signals.KKS.erase(signals.KKS.begin() + row);
	signals.KKS1.erase(signals.KKS1.begin() + row);
	signals.KKS2.erase(signals.KKS2.begin() + row);
	signals.Object_type.erase(signals.Object_type.begin() + row);
}

int Signals_invalid_row_check(int row)
{
	if (project.Cabinet[row].empty() == 0)
	{
		return 1;
	}

	if (project.Cabinet[row].empty() == 0)
	{
		return 1;
	}

	if (project.Module[row].empty() == 0)
	{
		return 1;
	}

	if (project.Pin[row].empty() == 0)
	{
		return 1;
	}

	if (project.Channel[row].empty() == 0)
	{
		return 1;
	}

	if (project.IO_text[row].empty() == 0)
	{
		return 1;
	}

	if (project.Page[row].empty() == 0)
	{
		return 1;
	}

	return 0;
}


