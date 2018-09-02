#include "config.h"
#include "Instance.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "ResultForm.h"
#include "IO_Form.h"

#include "signals.h"
#include "IO_declare.h"


using namespace std;

int IO_generate_Rack(int index, std::wstring &text)
{
	text = signals.data[index].Cabinet;
	if (text.empty() == 1)
	{
		text = L"";
		return 1;
	}
	int number = _wtoi(text.c_str());
	//testing that in IO tag wouldnt be numbers first 
	if (number > 0)
	{
		// removing numbers from cabinet
		text = text.substr(GetNumberOfDigits(number));
	}

	return 0;
}
int IO_generate_module(int index, std::wstring &text)
{
	if (IO_generate_Rack(index, text)==1)
	{
		text = L"";
		return 1;
	}

	text.append(L"_");
	text.append(signals.data[index].Module);

	return 0;
}
int IO_generate_signal(int index, std::wstring &text)
{
	if (IO_generate_module(index, text) == 1)
	{
		text = L"";
		return 1;
	}

	text.append(L"_");
	text.append(signals.data[index].Channel);

	return 0;
}

void IO_put_switch(int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{
	row++;
	grid->Rows->Add();
	grid->Rows[row - 1]->Cells[0]->Value = wstring_to_system_string(signal);
	grid->Rows[row - 1]->Cells[4]->Value = wstring_to_system_string(comment);
}


void IO_show_modules (IOlistautomation::IO_Form^ Io_forma)
{
	vector <wstring> temp_Module;
	vector <wstring> unique_Module;

	vector <wstring> temp_Rack;
	vector <wstring> unique_Rack;

	temp_Module.resize(signals.valid_entries + 1);
	temp_Rack.resize(signals.valid_entries + 1);
	//put all data to temporaty bufer
	for (int index = 0; index <= signals.valid_entries; index++)
	{
		IO_generate_Rack(index, temp_Rack[index]);
		IO_generate_module(index, temp_Module[index]);
	}
	// sort and find uniques then transfer further
	std::sort(temp_Rack.begin(), temp_Rack.end());
	unique_copy(temp_Rack.begin(), temp_Rack.end(), back_inserter(unique_Rack));

	std::sort(temp_Module.begin(), temp_Module.end());
	unique_copy(temp_Module.begin(), temp_Module.end(), back_inserter(unique_Module));

	// check if first data is empty, then delete it
	if (unique_Module[0].empty() == 1)
	{
		unique_Module.erase(unique_Module.begin());
	}

	if (unique_Rack[0].empty() == 1)
	{
		unique_Rack.erase(unique_Rack.begin());
	}

	System::Windows::Forms::DataGridView^ grid = Io_forma->Grid_Module;

	int row = 0;
	int result_find = 0;

	for (unsigned int i = 0; i < unique_Rack.size(); ++i)
	{
		int rack_row = row;

		//put rack name
		for (unsigned int j = 0; j < unique_Module.size(); ++j)
		{
			result_find = unique_Module[j].find(unique_Rack[i]);
			if (result_find >= 0)
			{
				// module matches rack
				grid->Rows->Add();
				row++;
				grid->Rows[row - 1]->Cells[2]->Value = wstring_to_system_string(unique_Module[j]);

			}
		}

		grid->Rows[rack_row]->Cells[1]->Value = wstring_to_system_string(unique_Rack[i]);
	}
}


int IO_generate()
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

	strcpy_s(info_txt, sizeof info_txt, info_generate_IO_tags[lang]);
	info_write(info_txt);

	Show_progress(prog_generate_IO[lang], signals.valid_entries);

	wstring tag_text = L"";
	wstring text_confirm = L"";


	for (int index = 0; index <= signals.valid_entries; ++index)
	{
		IO_generate_signal(index, tag_text);

		if (signals.data[index].Tag.empty() == 1)  // if no data, but now its found, then put type in signal
		{
			signals.data[index].Tag = tag_text;
		}
		else if (tag_text.compare(signals.data[index].Tag) !=0)//if type of data in object exists ask for overwrite
		{
			GlobalForm::forma->Signals_grid->FirstDisplayedScrollingRowIndex = index;
			GlobalForm::forma->Signals_grid->CurrentCell = GlobalForm::forma->Signals_grid[16, index]; // show which cell is overwriten

			text_confirm = conf_signal_TAG_overwrite[lang];
			text_confirm.append(L" --- ");
			text_confirm.append(signals.data[index].Tag);
			text_confirm.append(L" -> ");
			text_confirm.append(tag_text);
			if (show_confirm_window(text_confirm.c_str()) == IDOK)
			{
				signals.data[index].Tag = tag_text;
			}
		}

		set_progress_value(index);
	}
	Hide_progress();


	strcpy_s(info_txt, sizeof info_txt, info_generate_IO_tags[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	return 0;
}

int IO_show()
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

	strcpy_s(info_txt, sizeof info_txt, info_generate_IO_adress[lang]);
	info_write(info_txt);

	IOlistautomation::IO_Form Io_forma;
	System::Windows::Forms::DataGridView^ grid = Io_forma.Grid_Module;
	System::Windows::Forms::DataGridView^ grid_io = Io_forma.Grid_IO;
	Io_forma.IO_form_init();

	grid->Columns[0]->ReadOnly = true;
	
	IO_show_modules(%Io_forma);
	Io_forma.ShowDialog();

	Show_progress(prog_generate_IO_adress[lang], signals.valid_entries);

	Io_forma.tabControl1->SelectedIndex = 1;
	
	int index_rack = 4;
	int index_module = 5;
	int index_signals_nr = 6;
	wstring text = L"";
	wstring module_value = L"";
	wstring signal_value = L"";
	int row = 0;
	int signals_in_module = 0;
	int number_digits = 0;
	int result = 0;
	int result_row = 0;

	for (int index = 0; index < grid->RowCount; ++index)
	{
		if (grid->Rows[index]->Cells[index_rack]->Value != L"" && grid->Rows[index]->Cells[index_rack]->Value != nullptr)
		{
			// make rack adjustments to adresing
			int a = 0;
					
		}
		if (grid->Rows[index]->Cells[index_module]->Value == L"" || grid->Rows[index]->Cells[index_module]->Value == nullptr)
		{
			continue;
		}
		module_value = Global_get_cell_value(index, index_module, grid);

		// add adresses
		text = Global_get_cell_value(index, index_signals_nr, grid);		
		signals_in_module = _wtoi(text.c_str());

		number_digits = GetNumberOfDigits(signals_in_module);
		text = L"";
		for (int sig_nr = 1; sig_nr <= signals_in_module; sig_nr++)
		{
			// generate io
			signal_value = module_value;
			signal_value.append(L"_");

//			signal_value.append(int_to_wstring(sig_nr, number_digits));
			signal_value.append(int_to_wstring(sig_nr, 2));
			for (row = 0; row <= signals.valid_entries; row++)
			{
				if (IO_generate_signal(row, text) == 1)
				{
					continue;
				}
				//test if match
				result = signal_value.compare(text);
				if ( result == 0)
				{
					IO_put_switch(result_row, signals.data[row].Tag, signals.data[row].IO_text, grid_io);
					break;
				}
				

			}
			// no match 
			if (row > signals.valid_entries)
			{
				IO_put_switch(result_row, signal_value, L"", grid_io);
			}
		}
		result_row++;
		grid_io->Rows->Add();
		
		set_progress_value(index);
	}
	Hide_progress();

	Io_forma.Update();
	Io_forma.ShowDialog();

	strcpy_s(info_txt, sizeof info_txt, info_generate_IO_adress[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	
	return 0;
}