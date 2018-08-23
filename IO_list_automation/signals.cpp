#include "config.h"
#include "signals.h"


#include <stdio.h>
#include <stdlib.h>

#include"libxl.h"
#include "design.h"
#include "MainWindow.h"

using namespace std;
using namespace IOlistautomation;
using namespace libxl;


struct signal_str signals;
struct object_str objects;
struct learning_str learn;


wstring Signals_get_data_switch(int iCol, int index)
{
	wstring cell_text = L"";
	// fill all cells with data

	switch (iCol)
	{
	case 0:	cell_text = signals.number[index];
		break;
	case 1:	cell_text = signals.Cabinet[index];
		break;
	case 2:	cell_text = signals.operatyv[index];
		break;
	case 3:	cell_text = signals.KKS[index].Full;
		break;
	case 4:	cell_text = signals.KKS[index].Part1;
		break;
	case 5:	cell_text = signals.KKS[index].Part2;
		break;
	case 6:	cell_text = signals.Used[index];
		break;
	case 7:	cell_text = signals.Object_type[index];
		break;
	case 8:	cell_text = signals.Object_text[index];
		break;
	case 9:	cell_text = signals.Extendet_object_text[index];
		break;
	case 10:	cell_text = signals.Function_text[index];
		break;
	case 11:	cell_text = signals.Function[index];
		break;
	case 12:	cell_text = signals.IO_text[index];
		break;
	case 13:	cell_text = signals.Module[index];
		break;
	case 14:	cell_text = signals.Channel[index];
		break;
	case 15:	cell_text = signals.Pin[index];
		break;
	case 16:	cell_text = signals.Page[index];
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
	case 0:	signals.number[index] = cell_text;
		break;
	case 1:	signals.Cabinet[index] = cell_text;
		break;
	case 2:	signals.operatyv[index] = cell_text;
		break;
	case 3:	signals.KKS[index].Full = cell_text;
		break;
	case 4:	signals.KKS[index].Part1 = cell_text;
		break;
	case 5:	signals.KKS[index].Part2 = cell_text;
		break;
	case 6:	signals.Used[index] = cell_text;
		break;
	case 7:	signals.Object_type[index] = cell_text;
		break;
	case 8:	signals.Object_text[index] = cell_text;
		break;
	case 9:	signals.Extendet_object_text[index] = cell_text;
		break;
	case 10:	signals.Function_text[index] = cell_text;
		break;
	case 11:	signals.Function[index] = cell_text;
		break;
	case 12:	signals.IO_text[index] = cell_text;
		break;
	case 13:	signals.Module[index] = cell_text;
		break;
	case 14:	signals.Channel[index] = cell_text;
		break;
	case 15:	signals.Pin[index] = cell_text;
		break;
	case 16:	signals.Page[index] = cell_text;
		break;
	}
}
//check if there is data in any variable
int Signals_valid_row_check(int row)
{
	if (signals.number[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Cabinet[row].empty() == 0)
	{
		return 1;
	}
	if (signals.operatyv[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Used[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Object_type[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Object_text[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Extendet_object_text[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Function_text[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Function[row].empty() == 0)
	{
		return 1;
	}
	if (signals.IO_text[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Module[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Channel[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Pin[row].empty() == 0)
	{
		return 1;
	}
	if (signals.Page[row].empty() == 0)
	{
		return 1;
	}
	return 0;
}


void Signals_delete_list()
{
	GlobalForm::forma->Signals_grid->Rows->Clear();
	GlobalForm::forma->Signals_grid->Columns->Clear();
}

//setting grid width
void Signals_put_with_list()
{
	int a = signals.collumn_with.size();

	// if there is no width parameters or automatic cullumn with, auto size collumns
	if (a > 0 && parameters.auto_column_with == 0)
	{
		GlobalForm::forma->Signals_grid->AutoResizeColumns();
		for (int i = 0; i < a; i++)
		{
			GlobalForm::forma->Signals_grid->Columns[i]->Width = signals.collumn_with[i];
		}
	}
	else
	{
		GlobalForm::forma->Signals_grid->AutoResizeColumns();
	}
}
//getting grid width
void Signals_get_with_list()
{
	int a = GlobalForm::forma->Signals_grid->ColumnCount;
	signals.collumn_with.resize(a);

	for (int i = 0; i < a; i++)
	{
		signals.collumn_with[i] = GlobalForm::forma->Signals_grid->Columns[i]->Width;
	}
}
//put data to grid
void Signals_put_data_listview()
{
	//before puting data clear list
	Signals_delete_list();
	GlobalForm::forma->Update();
	int iCol;

	Show_progress(prog_grid_put[lang], signals.valid_entries);

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	info_write(info_txt);


	// Add the columns.
	GlobalForm::forma->Signals_grid->ColumnCount = signals.number_collums + 1;

	for (iCol = 0; iCol <= signals.number_collums; iCol++)
	{
		// Load the names of the column headings from the string resources.
		GlobalForm::forma->Signals_grid->Columns[iCol]->Name = wstring_to_system_string(signals.column_name[iCol]);
	}

	wstring cell_text = L"";

	int grid_cell = 0;
	for (int index = 0; index <= signals.valid_entries; index++)
	{
		if (Signals_valid_row_check(index) == 1)
		{
			GlobalForm::forma->Signals_grid->Rows->Add();

			// fill all cells with data
			for (iCol = 0; iCol <= signals.number_collums; iCol++)
			{
				cell_text = Signals_get_data_switch(iCol, index);

				String^ textas = wstring_to_system_string(cell_text);

				// Insert items into the list.
				GlobalForm::forma->Signals_grid->Rows[grid_cell]->Cells[iCol]->Value = textas;
			}
			grid_cell++;
		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	GlobalForm::forma->tabControl1->SelectedIndex = Signals_grid_index;


	Signals_put_with_list();
	GlobalForm::forma->Update();

}
//get data from grid
void Signals_get_data_listview()
{
	// if there is data get it
	if (GlobalForm::forma->Signals_grid->RowCount > 0)
	{
		signals.valid_entries = GlobalForm::forma->Signals_grid->RowCount - 1;
		Signals_resize_data(signals.valid_entries + 1);

		signals.number_collums = GlobalForm::forma->Signals_grid->ColumnCount - 1;

		Show_progress(prog_grid_take[lang], signals.valid_entries);

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
		info_write(info_txt);

		wstring cell_text = L"";

		int iCol;
		for (iCol = 0; iCol <= signals.number_collums; iCol++)
		{
			signals.column_name[iCol] = system_string_to_wstring(GlobalForm::forma->Signals_grid->Columns[iCol]->Name);
		}
		for (int index = 0; index <= signals.valid_entries; index++)
		{

			// fill all cells with data
			for (iCol = 0; iCol <= signals.number_collums; iCol++)
			{
				cell_text = system_string_to_wstring(GlobalForm::forma->Signals_grid->Rows[index]->Cells[iCol]->FormattedValue->ToString());

				Signals_put_data_switch(iCol, index, cell_text);
			}
			set_progress_value(index);
		}

		Hide_progress();

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
		info_write(info_txt);

		if (unstable_release == 1 && signals.valid_entries>1)
		{
			Signals_save_data(true, " ");
		}
		Signals_get_with_list();
	}
	else
	{
		signals = {};
	}
}


//resize data
void Signals_resize_data(int size)
{
	signals.number.resize(size);
	signals.Cabinet.resize(size);
	signals.Module.resize(size);
	signals.Pin.resize(size);
	signals.Channel.resize(size);
	signals.IO_text.resize(size);
	signals.Page.resize(size);

	signals.operatyv.resize(size);
	signals.Used.resize(size);
	signals.Object_text.resize(size);
	signals.Extendet_object_text.resize(size);
	signals.Function_text.resize(size);
	signals.Function.resize(size);
	signals.KKS.resize(size);
	signals.Object_type.resize(size);
}
// delete single row
void Signals_delete_row(int row)
{
	signals.number.erase(signals.number.begin() + row);
	signals.Cabinet.erase(signals.Cabinet.begin() + row);
	signals.Module.erase(signals.Module.begin() + row);
	signals.Pin.erase(signals.Pin.begin() + row);
	signals.Channel.erase(signals.Channel.begin() + row);
	signals.IO_text.erase(signals.IO_text.begin() + row);
	signals.Page.erase(signals.Page.begin() + row);

	signals.operatyv.erase(signals.operatyv.begin() + row);
	signals.Used.erase(signals.Used.begin() + row);
	signals.Object_text.erase(signals.Object_text.begin() + row);
	signals.Extendet_object_text.erase(signals.Extendet_object_text.begin() + row);
	signals.Function_text.erase(signals.Function_text.begin() + row);
	signals.Function.erase(signals.Function.begin() + row);
	signals.KKS.erase(signals.KKS.begin() + row);
	signals.Object_type.erase(signals.Object_type.begin() + row);
}



int Signals_save_data(bool auto_save, std::string file_name_global)
{
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = "Save document |*.ssave" +
		"|All Files|*.*";
	sfd->FileName = "Project";

	wstring cell_text = L"Signals";
	string extension = ".ssave";
	std::string file_name = "_autosave";
	file_name.append(extension);


	if (signals.valid_entries <= 0)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
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
		Show_progress(prog_save[lang], signals.valid_entries);
	}
	fopen_s(&outFile, file_name.c_str(), "w+,ccs=UTF-8");

	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	info_write(info_txt);

	if (outFile == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_file_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	if (auto_save == 0)
	{
		Signals_get_data_listview();
	}

	cell_text.append(L"\n");
	const wchar_t* x = cell_text.c_str();


	for (iCol = 0; iCol <= signals.number_collums; iCol++)
	{
		cell_text.append(signals.column_name[iCol]);
		cell_text.append(separator);
	}

	cell_text.append(L"\n");
	x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);
	wstring cell_text_write;

	for (int index = 0; index <= signals.valid_entries; index++)
	{
		cell_text_write = L"";
		// fill all cells with data
		for (iCol = 0; iCol <= signals.number_collums; iCol++)
		{
			cell_text = Signals_get_data_switch(iCol, index);
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
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}

int Signals_Load_data(std::string file_name_global)
{
	wchar_t cmp_text[255] = L"Signals";

	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = "Load document |*.ssave" +
		"|All Files|*.*";
	string extension = ".ssave";

	if (signals.valid_entries > 0)
	{
		if (show_confirm_window(conf_signal_overwrite[lang]) == IDOK)
		{
			signals = {};
			Signals_delete_list();

			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	Show_progress(prog_load[lang], 1000);

	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
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
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
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
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
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
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}
	while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
	{
		signals.number_collums = iCol;
		signals.column_name.resize(signals.number_collums + 1);
		signals.column_name[iCol] = cell_text;
		iCol++;
		cell_text = wcstok_s(NULL, separator, &next_token1);
	}

	int a = 0;

	while (fgetws(x, sizeof x, inFile) != NULL)
	{
		signals.valid_entries = index;
		Signals_resize_data(index + 1);
		iCol = 0;

		cell_text = wcstok_s(x, separator, &next_token1);
		while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
		{

			if (wcscmp(cell_text, L" ") != 0)
			{
				Signals_put_data_switch(iCol, index, cell_text);
			}
			iCol++;
			cell_text = wcstok_s(NULL, separator, &next_token1);
		}
		a++;
		index++;
		if (a > 1000)
		{
			a = a - 1000;
		}
		set_progress_value(a);
	}
	fclose(inFile);

	Hide_progress();



	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, signals_txt[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Signals_put_data_listview();
	return 0;

}




int Signals_get_data_design()
{
	Project_get_data_listview();
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
			signals = {};
			Signals_delete_list();
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
	Signals_resize_data(signals.valid_entries + 1);

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

		signals.KKS[row].Full = tmp_KKS;

		if ((colon != -1) && (semi != -1))  // found colon, found semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space, semi-space);
			signals.Extendet_object_text[row] = signals.IO_text[row].substr(semi+2, colon- semi-2);
			signals.Function_text[row] = signals.IO_text[row].substr(colon + 2);
		}
		else if (semi != -1)						// no colon, found semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space, semi-space);
			signals.Extendet_object_text[row] = signals.IO_text[row].substr(semi + 2);
			signals.Function_text[row] = LPWSTR(L"");
		}
		else if (colon != -1)							// found colon, no semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space,colon-space);
			signals.Extendet_object_text[row] = LPWSTR(L"");
			signals.Function_text[row] = signals.IO_text[row].substr(colon + 2);
		}
		else												// no colon, no semicolon
		{
			signals.Object_text[row] = signals.IO_text[row].substr(space);
			signals.Extendet_object_text[row] = LPWSTR(L"");
			signals.Function_text[row] = LPWSTR(L"");
		}
		set_progress_value(row);
	}

	Hide_progress();
	Signals_put_data_listview();

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
	Signals_get_data_listview();
	if (signals.valid_entries > 1)
	{
		Signals_get_data_listview();
		int i = 0;
		while (1)
		{			
			if (signals.KKS[i].Full.empty() == 0)
			{
				test.test_KKS = signals.KKS[i].Full;
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
				signals.KKS[row] = Signals_KKS_trim(signals.KKS[row].Full);
			}

			strcpy_s(info_txt, sizeof info_txt, info_KKS_edit[lang]);
			strcat_s(info_txt, sizeof info_txt, error_separator);
			strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
			info_write(info_txt);

			Hide_progress();
			Signals_put_data_listview();
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
			project = {};
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


			Project_resize_data(max_rows);
			// first two rows are for comments
			for (int row = sheet->firstRow()+2; row < max_rows; ++row)
			{
				project.number[row] = row;				
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

	Signals_get_data_listview();
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
		search_in_function_txt = signals.Function_text[row];
		
		if (search_in_function_txt.empty() == 0)
		{
			search_in_extended = signals.Extendet_object_text[row];
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
							signals.Function[row] = learn.Function_txt2_meaning[j];
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
						signals.Function[row] = learn.Function_txt1_meaning[i];
						break;
					}
				}
			}
		}
		set_progress_value(row);
	}

	Hide_progress();
	Signals_put_data_listview();

	strcpy_s(info_txt, sizeof info_txt, info_find_function[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	return 0;
}





