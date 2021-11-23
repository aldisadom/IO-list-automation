#include "config.h"
#include "Instance_SCADA.h"

#include <stdio.h>
#include <stdlib.h>
#include "ResultForm.h"

#include "objects.h"
#include "signals.h"
#include "Declare.h"
#include "IO_declare.h"

#include "Global_Functions.h"

#include "Instance_platform.h"
#include "Instance_wincc.h"


int Init_scada_vlv_switch(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Init_platform_vlv(grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Init_Wincc_vlv(grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Init_scada_ai_switch(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Init_platform_ai(grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Init_Wincc_ai(grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Init_scada_mot_switch(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Init_platform_mot(grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Init_Wincc_mot(grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Init_scada_pid_switch(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Init_platform_pid(grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Init_Wincc_pid(grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Init_scada_hc_switch(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Init_platform_hc(grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Init_Wincc_hc(grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}


// initialise grids for instances
void Instance_scada_init_grids(int AI_nr_max, int  VLV_nr_max, int HC_nr_max, int  FC_nr_max, int  PID_nr_max, int MOT_nr_max, IOlistautomation::ResultForm^ result_form)
{
	int collumns = 30;
	int indexas = 0;

	switch (parameters.SCADA)
	{
	case System_platform_index:
		collumns = 55;
		break;
	case WinCC_index:
		collumns = 20;
		break;
	default:
		collumns = 20;
		break;
	}
	
	if (AI_nr_max>0)
	{
		System::Windows::Forms::DataGridView^ grid = result_form->Grid_AI;
		indexas = 0;
		grid->ColumnCount = collumns;
		Init_scada_ai_switch(indexas, grid);
	}
	else
	{
		result_form->Grid_AI->ColumnCount = 0;
		result_form->Grid_AI->Rows->Clear();
	}

	if (VLV_nr_max>0)
	{
		System::Windows::Forms::DataGridView^ grid = result_form->Grid_VLV;
		indexas = 0;
		grid->ColumnCount = collumns;
		Init_scada_vlv_switch(indexas, grid);
	}
	else
	{
		result_form->Grid_VLV->ColumnCount = 0;
		result_form->Grid_VLV->Rows->Clear();
	}

	if (HC_nr_max>0)
	{
		System::Windows::Forms::DataGridView^ grid = result_form->Grid_HC;
		indexas = 0;
		grid->ColumnCount = collumns;
		Init_scada_hc_switch(indexas, grid);
	}
	else
	{
		result_form->Grid_HC->ColumnCount = 0;
		result_form->Grid_HC->Rows->Clear();
	}

	if (PID_nr_max>0)
	{
		System::Windows::Forms::DataGridView^ grid = result_form->Grid_PID;
		indexas = 0;
		grid->ColumnCount = collumns;
		Init_scada_pid_switch(indexas, grid);
	}
	else
	{
		result_form->Grid_PID->ColumnCount = 0;
		result_form->Grid_PID->Rows->Clear();
	}

	if (MOT_nr_max>0)
	{
		System::Windows::Forms::DataGridView^ grid = result_form->Grid_MOT;
		indexas = 0;
		grid->ColumnCount = collumns;
		Init_scada_mot_switch(indexas, grid);
	}
	else
	{
		result_form->Grid_MOT->ColumnCount = 0;
		result_form->Grid_MOT->Rows->Clear();
	}
}

// add one line to instance grid
void Instance_scada_grid_add_line(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	grid->Rows->Add();
	grid_row_index++;
}
// add data to instance grid
void Instance_scada_grid_write_cell(int &grid_row_index, int collumn,wstring cell_text, System::Windows::Forms::DataGridView^ grid)
{
	grid->Rows[grid_row_index-1]->Cells[collumn]->Value = wstring_to_system_string(cell_text);
}



int Instance_scada_vlv_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:	
		return_val =Instance_platform_vlv(index, grid_row_index, grid);
		break;
	case WinCC_index:	
		return_val = Instance_Wincc_vlv(index, grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Instance_scada_ai_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Instance_platform_ai(index, grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Instance_Wincc_ai(index, grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Instance_scada_mot_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;

	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Instance_platform_mot(index, grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Instance_Wincc_mot(index, grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Instance_scada_pid_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Instance_platform_pid(index, grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Instance_Wincc_pid(index, grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}

int Instance_scada_hc_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	int return_val = 0;
	switch (parameters.SCADA)
	{
	case System_platform_index:
		return_val = Instance_platform_hc(index, grid_row_index, grid);
		break;
	case WinCC_index:
		return_val = Instance_Wincc_hc(index, grid_row_index, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}
	return return_val;
}



int Instance_scada_gen(bool test_mode, wstring gen_test_mode)
{
	wstring texts;
	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.collumn_with, false);
	if (signals.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.signals_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		texts = str.Error.no_data_edit.s[lang];
		texts.append(error_separator);
		texts.append(str.General.objects_txt.s[lang]);
		err_write_show(texts);
		return 1;
	}

	int AI_nr_max = 0;
	int VLV_nr_max = 0;
	int HC_nr_max = 0;
	int FC_nr_max = 0;
	int PID_nr_max = 0;
	int MOT_nr_max = 0;

	IOlistautomation::ResultForm results_form;

	if (Declare_count_objects(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max) > 0)
	{
		return 1;
	}

	texts = str.Info.put_adresses.s[lang];
	texts.append(info_separator);
	texts.append(Global_get_scada_name(parameters.SCADA));
	info_write(texts);

	Instance_scada_init_grids(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max,%results_form);

	Show_progress(str.Progress.declare.s[lang], objects.valid_entries);


	int AI_grid_row = 1;
	int VLV_grid_row = 1;
	int HC_grid_row = 1;
	int FC_grid_row =1;
	int PID_grid_row = 1;
	int MOT_grid_row = 1;

	wstring object_type = L"";

	int object_init = 0;

	int return_val = 0;
	for (int index = object_init; index <= objects.valid_entries; ++index)
	{
		object_type = objects.data[index].Object_type;

		if (object_type.compare(AI_type) == 0)
		{
			return_val=Instance_scada_ai_switch(index, AI_grid_row, results_form.Grid_AI);
		}
		else if (object_type.compare(Vlv_type) == 0)
		{
			return_val=Instance_scada_vlv_switch(index, VLV_grid_row, results_form.Grid_VLV);
		}
		else if (object_type.compare(HC_type) == 0)
		{
			return_val =Instance_scada_hc_switch(index, HC_grid_row, results_form.Grid_HC);
		}
		else if (object_type.compare(PID_type) == 0)
		{
			return_val =Instance_scada_pid_switch(index, PID_grid_row, results_form.Grid_PID);
		}
		else if (object_type.compare(Mot_type) == 0)
		{
			return_val=Instance_scada_mot_switch(index, MOT_grid_row, results_form.Grid_MOT);
		}

		if (return_val != 0)
		{
			Hide_progress();
			return 1;
		}
		set_progress_value(index);
	}


	Hide_progress();

	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_AI, Dump_names.scada_decl_AI);
	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_FC, Dump_names.scada_decl_FC);
	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_HC, Dump_names.scada_decl_HC);
	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_MOT, Dump_names.scada_decl_MOT);
	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_PID, Dump_names.scada_decl_PID);
	Declare_dump_to_file(test_mode, gen_test_mode, results_form.Grid_VLV, Dump_names.scada_decl_VLV);

	if (test_mode == false)
	{
		results_form.ShowDialog();
		results_form.Update();
	}
	texts = str.Info.put_adresses.s[lang];
	texts.append(info_separator);
	texts.append(Global_get_scada_name(parameters.SCADA));
	texts.append(error_separator);
	texts.append(str.Info.put_adresses.s[lang]);
	info_write(texts);
	return 0;
}