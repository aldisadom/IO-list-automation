#include "config.h"
#include "Instance.h"

#include <stdio.h>
#include <stdlib.h>
#include "ResultForm.h"

#include "objects.h"
#include "signals.h"
#include "Declare.h"
#include "IO_declare.h"

#include "Instance_siemens.h"
#include "Global_Functions.h"

int Instance_Siemens_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring search_for_KKS = objects.data[index_object].KKS;
	wstring cell_text = L"";
	wstring tag_txt = L"";
	int result = 0;

	Instance_grid_add_line(grid_row_index, grid);

	cell_text = L"(//---------------------- ";
	cell_text.append(search_for_KKS);
	cell_text.append(L" : ");
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	cell_text = objects.data[index_object].Object_text;
	cell_text.append(L" ----------------------");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);

	// create function call
	cell_text = L"CALL fb_";
	cell_text.append(objects.data[index_object].Object_type);
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"Puls_100ms:= pulsas";
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"dv := \"";
	cell_text.append(L"V\".\"");
	cell_text.append(search_for_KKS);
	cell_text.append(L"\"");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	//search for signals that belong to function
	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		if (search_for_KKS.compare(signals.data[row].KKS.Full) == 0)
		{
			if (signals.data[row].Tag.empty() == 1)
			{
				strcpy_s(err_txt, sizeof err_txt, err_no_tag[lang]);
				strcat_s(err_txt, sizeof err_txt, info_separator);
				strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
				err_write_show(err_txt);
				return 1;
			}
			tag_txt = signals.data[row].Tag;

			// return that this IO is used
			signals.data[row].Used = L"1";
	
			Instance_grid_add_line(grid_row_index, grid);

			cell_text =signals.data[row].Function;
			cell_text.append(L"_in :=");
			Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);
			Instance_grid_write_cell(grid_row_index, 2, tag_txt, grid);
			cell_text = L"//";
			cell_text.append(signals.data[row].IO_text);
			Instance_grid_write_cell(grid_row_index, 3, cell_text, grid);
		}
	}
	Instance_grid_add_line(grid_row_index, grid);
	return 0;
}

int Instance_Siemens_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring search_for_KKS = objects.data[index_object].KKS;
	wstring cell_text = L"";
	wstring tag_txt = L"";
	int result = 0;

	Instance_grid_add_line(grid_row_index, grid);

	cell_text = L"(//---------------------- ";
	cell_text.append(search_for_KKS);
	cell_text.append(L" : ");
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	cell_text = objects.data[index_object].Object_text;
	cell_text.append(L" ----------------------");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);

	// create function call
	cell_text = L"CALL fb_";
	cell_text.append(objects.data[index_object].Object_type);
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"Puls_100ms:= pulsas";
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"dv := \"";
	cell_text.append(L"M\".\"");
	cell_text.append(search_for_KKS);
	cell_text.append(L"\"");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	//search for signals that belong to function
	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		if (search_for_KKS.compare(signals.data[row].KKS.Full) == 0)
		{
			if (signals.data[row].Tag.empty() == 1)
			{
				strcpy_s(err_txt, sizeof err_txt, err_no_tag[lang]);
				strcat_s(err_txt, sizeof err_txt, info_separator);
				strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
				err_write_show(err_txt);
				return 1;
			}
			tag_txt = signals.data[row].Tag;

			// return that this IO is used
			signals.data[row].Used = L"1";

			Instance_grid_add_line(grid_row_index, grid);

			cell_text = signals.data[row].Function;
			cell_text.append(L"_in :=");
			Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);
			Instance_grid_write_cell(grid_row_index, 2, tag_txt, grid);
			cell_text = L"//";
			cell_text.append(signals.data[row].IO_text);
			Instance_grid_write_cell(grid_row_index, 3, cell_text, grid);
		}
	}
	Instance_grid_add_line(grid_row_index, grid);
	return 0;
}

int Instance_Siemens_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Instance_Siemens_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring search_for_KKS = objects.data[index_object].KKS;
	wstring cell_text = L"";
	wstring tag_txt = L"";
	int result = 0;

	Instance_grid_add_line(grid_row_index, grid);

	cell_text = L"(//---------------------- ";
	cell_text.append(search_for_KKS);
	cell_text.append(L" : ");
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	cell_text = objects.data[index_object].Object_text;
	cell_text.append(L" ----------------------");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);

	// create function call
	cell_text = L"CALL fb_";
	cell_text.append(objects.data[index_object].Object_type);
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"Puls_100ms:= pulsas";
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"dv := \"";
	cell_text.append(L"HC\".\"");
	cell_text.append(search_for_KKS);
	cell_text.append(L"\"");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	//search for signals that belong to function
	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		if (search_for_KKS.compare(signals.data[row].KKS.Full) == 0)
		{
			if (signals.data[row].Tag.empty() == 1)
			{
				strcpy_s(err_txt, sizeof err_txt, err_no_tag[lang]);
				strcat_s(err_txt, sizeof err_txt, info_separator);
				strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
				err_write_show(err_txt);
				return 1;
			}
			tag_txt = signals.data[row].Tag;

			// return that this IO is used
			signals.data[row].Used = L"1";

			Instance_grid_add_line(grid_row_index, grid);

			cell_text = signals.data[row].Function;
			cell_text.append(L"_in :=");
			Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);
			Instance_grid_write_cell(grid_row_index, 2, tag_txt, grid);
			cell_text = L"//";
			cell_text.append(signals.data[row].IO_text);
			Instance_grid_write_cell(grid_row_index, 3, cell_text, grid);
		}
	}
	Instance_grid_add_line(grid_row_index, grid);
	return 0;
}

int Instance_Siemens_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring search_for_KKS = objects.data[index_object].KKS;
	wstring cell_text = L"";
	wstring tag_txt = L"";
	int result = 0;

	Instance_grid_add_line(grid_row_index, grid);

	cell_text = L"(//---------------------- ";
	cell_text.append(search_for_KKS);
	cell_text.append(L" : ");
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	cell_text = objects.data[index_object].Object_text;
	cell_text.append(L" ----------------------");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);

	// create function call
	cell_text = L"CALL fb_";
	cell_text.append(objects.data[index_object].Object_type);
	Instance_grid_write_cell(grid_row_index, 0, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"Puls_100ms:= pulsas";
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	Instance_grid_add_line(grid_row_index, grid);
	cell_text = L"dv := \"";
	cell_text.append(L"A\".\"");
	cell_text.append(search_for_KKS);
	cell_text.append(L"\"");
	Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);

	//search for signals that belong to function
	for (int row = 0; row <= signals.valid_entries; ++row)
	{
		if (search_for_KKS.compare(signals.data[row].KKS.Full) == 0)
		{
			if (signals.data[row].Tag.empty() == 1)
			{
				strcpy_s(err_txt, sizeof err_txt, err_no_tag[lang]);
				strcat_s(err_txt, sizeof err_txt, info_separator);
				strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
				err_write_show(err_txt);
				return 1;
			}
			tag_txt = signals.data[row].Tag;

			// return that this IO is used
			signals.data[row].Used = L"1";

			Instance_grid_add_line(grid_row_index, grid);

			cell_text = signals.data[row].Function;
			cell_text.append(L"value_in :=");
			Instance_grid_write_cell(grid_row_index, 1, cell_text, grid);
			Instance_grid_write_cell(grid_row_index, 2, tag_txt, grid);
			cell_text = L"//";
			cell_text.append(signals.data[row].IO_text);
			Instance_grid_write_cell(grid_row_index, 3, cell_text, grid);
		}
	}
	Instance_grid_add_line(grid_row_index, grid);
	return 0;
}