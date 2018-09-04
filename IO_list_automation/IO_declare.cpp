#include "config.h"
#include "Instance.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "ResultForm.h"
#include "IO_Form.h"

#include "signals.h"
#include "IO_declare.h"

struct begin_adress_str
{
	int DI = 0;
	int DO = 0;
	int AI = 256;
	int AO = 256;
};

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
	text.append(signals.data[index].Module_name);

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

void IO_Beckhoff(int modul_index, begin_adress_str &begin_adress, int rack_nr, int module_nr, int signal_nr, int signals_in_module, int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{	
	wstring address_text = L"AT%";
	wstring address_type_text = L":";
	wstring comment_text = L"";

	comment_text = L"(*";
	comment_text.append(comment);
	comment_text.append(L"*)");

	int adress_nr;
	int bit_nr;

	switch (modul_index)
	{
	case DI_index:
		adress_nr = signal_nr / 8;
		bit_nr = signal_nr - adress_nr * 8;

		address_text.append(L"IX");
		address_text.append(to_wstring(begin_adress.DI+adress_nr));
		address_text.append(L".");
		address_text.append(to_wstring(bit_nr));
		address_type_text.append(L"BOOL");
		break;
	case DO_index:
		adress_nr = signal_nr / 8;
		bit_nr = signal_nr - adress_nr * 8;

		address_text.append(L"QX");
		address_text.append(to_wstring(begin_adress.DO + adress_nr));
		address_text.append(L".");
		address_text.append(to_wstring(bit_nr));
		address_type_text.append(L"BOOL");
		break;
	case AI_index:
		adress_nr = signal_nr *2;

		address_text.append(L"IW");
		address_text.append(to_wstring(begin_adress.AI + adress_nr));
		address_type_text.append(L"WORD");
		break;
	case AO_index:
		adress_nr = signal_nr *2;

		address_text.append(L"QW");
		address_text.append(to_wstring(begin_adress.AO + adress_nr));
		address_type_text.append(L"WORD");
		break;
	}
	address_type_text.append(L";");

	grid->Rows[row]->Cells[1]->Value = wstring_to_system_string(signal);
	grid->Rows[row]->Cells[2]->Value = wstring_to_system_string(address_text);
	grid->Rows[row]->Cells[3]->Value = wstring_to_system_string(address_type_text);
	grid->Rows[row]->Cells[4]->Value = wstring_to_system_string(comment_text);
}
void IO_Siemens(int modul_index, begin_adress_str &begin_adress, int rack_nr, int module_nr, int signal_nr, int signals_in_module, int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{
	wstring address_text = L"%";
	wstring address_type_text = L"";

	int adress_nr;
	int bit_nr;

	switch (modul_index)
	{
	case DI_index:
		adress_nr = signal_nr / 8;
		bit_nr = signal_nr - adress_nr * 8;

		address_text.append(L"I");
		address_text.append(to_wstring(begin_adress.DI + adress_nr));
		address_text.append(L".");
		address_text.append(to_wstring(bit_nr));
		address_type_text.append(L"BOOL");
		break;
	case DO_index:
		adress_nr = signal_nr / 8;
		bit_nr = signal_nr - adress_nr * 8;

		address_text.append(L"Q");
		address_text.append(to_wstring(begin_adress.DO + adress_nr));
		address_text.append(L".");
		address_text.append(to_wstring(bit_nr));
		address_type_text.append(L"BOOL");
		break;
	case AI_index:
		adress_nr = signal_nr * 2;

		address_text.append(L"IW");
		address_text.append(to_wstring(begin_adress.AI + adress_nr));
		address_type_text.append(L"INT");
		break;
	case AO_index:
		adress_nr = signal_nr * 2;

		address_text.append(L"QW");
		address_text.append(to_wstring(begin_adress.AO + adress_nr));
		address_type_text.append(L"INT");
		break;
	}

	grid->Rows[row]->Cells[1]->Value = wstring_to_system_string(signal);	
	grid->Rows[row]->Cells[2]->Value = wstring_to_system_string(address_type_text);
	grid->Rows[row]->Cells[3]->Value = wstring_to_system_string(address_text);
	grid->Rows[row]->Cells[4]->Value = L"FALSE";
	grid->Rows[row]->Cells[5]->Value = L"FALSE";
	grid->Rows[row]->Cells[6]->Value = L"FALSE";
	grid->Rows[row]->Cells[7]->Value = L"FALSE";


	grid->Rows[row]->Cells[9]->Value = wstring_to_system_string(comment);
}
void IO_ABB_800xA(int signal_index,int modul_index, begin_adress_str &begin_adress, int rack_nr, int module_nr, int signal_nr, int signals_in_module, int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{
	if (signal_index > 0)
	{
		wstring app_tag = L"";
		if (signals.data[signal_index].KKS.Full.empty() != 1)
		{
			int result = signals.data[signal_index].Module_name.find(L"FS");

			app_tag = parameters.ABB_800xA_app_name;
			if (result >= 0)
			{
				app_tag.append(L"_SRS");
			}
			
			app_tag.append(L".");
			app_tag.append(signals.data[signal_index].KKS.Full);

			if (result < 0)
			{
				app_tag.append(L".ioc");
			}
			
			if (signals.data[signal_index].Function.empty() != 1)
			{				
				app_tag.append(L".");				

				app_tag.append(signals.data[signal_index].Function);
			}
			grid->Rows[row]->Cells[1]->Value = wstring_to_system_string(app_tag);
			grid->Rows[row]->Cells[2]->Value = wstring_to_system_string(comment);
		}

	}

	grid->Rows[row]->Cells[0]->Value = signal_nr;
}
void IO_Schneider(int modul_index, begin_adress_str &begin_adress, int rack_nr, int module_nr, int signal_nr, int signals_in_module, int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{

}

void IO_put_switch(int signal_index, int modul_index, begin_adress_str &begin_adress,int rack_nr, int module_nr, int signal_nr, int signals_in_module,int &row, std::wstring signal, std::wstring comment, System::Windows::Forms::DataGridView^ grid)
{
	grid->Rows->Add();
	switch (parameters.CPU)
	{
	case Beckhoff_index:
		IO_Beckhoff(modul_index, begin_adress, rack_nr, module_nr, signal_nr, signals_in_module, row, signal, comment, grid);
		break;
	case Siemens_index:
		IO_Siemens(modul_index, begin_adress, rack_nr, module_nr, signal_nr, signals_in_module, row, signal, comment, grid);
		break;
	case Schneider_index:
		IO_Schneider(modul_index, begin_adress, rack_nr, module_nr, signal_nr, signals_in_module, row, signal, comment, grid);
		break;
	case ABB_800xA_index:
		IO_ABB_800xA(signal_index,modul_index, begin_adress, rack_nr, module_nr, signal_nr, signals_in_module, row, signal, comment, grid);
		break;
	}
	row++;
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

	Show_progress(prog_generate_IO_adress[lang], grid->RowCount);

	Io_forma.tabControl1->SelectedIndex = 1;
	
	int index_rack = 4;
	int index_module = 5;
	int index_module_type = 6;
	int index_signals_nr = 7;

	wstring text = L"";
	wstring module_value = L"";
	wstring signal_value = L"";
	int row = 0;
	int signals_in_module = 0;
	int number_digits = 0;
	int result = 0;
	int result_row = 0;

	int rack_nr = -1;
	int module_nr = -1;
	int modul_index = 0;

	begin_adress_str begin_adress;

	for (int index = 0; index < grid->RowCount; ++index)
	{
		if (grid->Rows[index]->Cells[index_rack]->Value != L"" && grid->Rows[index]->Cells[index_rack]->Value != nullptr)
		{
			module_nr = -1;
			rack_nr++;
			if (rack_nr > 0)
			{
				//add adressing modification to ai di do ao, when new rack is added
			}

			if (parameters.CPU == Beckhoff_index)
			{
				text = to_wstring(rack_nr);
				text.append(L" Rack  --- ");
				text.append(Global_get_cell_value(index, index_rack, grid));				

				grid_io->Rows->Add();
				grid_io->Rows[result_row]->Cells[0]->Value = wstring_to_system_string(text);
				result_row++;
			}
		}
		if (grid->Rows[index]->Cells[index_module]->Value == L"" || grid->Rows[index]->Cells[index_module]->Value == nullptr)
		{
			continue;
		}


		module_nr++;
		module_value = Global_get_cell_value(index, index_module, grid);

		if (parameters.CPU == ABB_800xA_index)
		{			
			text = L"Module  --- ";
			text.append (module_value);

			grid_io->Rows->Add();
			grid_io->Rows[result_row]->Cells[0]->Value = wstring_to_system_string(text);
			result_row++;
		}

		wstring module_type = Global_get_cell_value(index, index_module_type, grid);
		

		modul_index=Global_Module_index(module_type);

		text = Global_get_cell_value(index, index_signals_nr, grid);		
		signals_in_module = _wtoi(text.c_str());

		number_digits = GetNumberOfDigits(signals_in_module);
		text = L"";
		for (int sig_nr = 0; sig_nr < signals_in_module; sig_nr++)
		{
			// generate io
			signal_value = module_value;
			signal_value.append(L"_");

//			signal_value.append(int_to_wstring(sig_nr, number_digits));
			signal_value.append(int_to_wstring(sig_nr+ parameters.adresing_from_1, 2));
			for (row = 0; row <= signals.valid_entries; row++)
			{
				if (IO_generate_signal(row, text) == 1)
				{
					continue;
				}
				//test if match
				result = signal_value.compare(text);
				wstring yyyy = signals.data[row].Tag;
				if ( result == 0)
				{
					IO_put_switch(row, modul_index, begin_adress, rack_nr, module_nr, sig_nr, signals_in_module, result_row, signals.data[row].Tag, signals.data[row].IO_text, grid_io);
					break;
				}
			}
			// no match 
			if (row > signals.valid_entries)
			{
				IO_put_switch(-1, modul_index,begin_adress, rack_nr, module_nr, sig_nr, signals_in_module, result_row, signal_value, L"", grid_io);
			}
		}

		switch (modul_index)
		{
		case DI_index:
			begin_adress.DI = begin_adress.DI + signals_in_module / 8;
			break;
		case DO_index:
			begin_adress.DO = begin_adress.DO + signals_in_module / 8;
			break;
		case AI_index:
			begin_adress.AI = begin_adress.AI + signals_in_module * 2;
			break;
		case AO_index:
			begin_adress.AO = begin_adress.AO + signals_in_module * 2;
			break;

		default:
			strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
			err_write_show(err_txt);
			return 1;
			break;
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