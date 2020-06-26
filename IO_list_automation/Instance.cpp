#include "config.h"
#include "Instance.h"

#include <stdio.h>
#include <stdlib.h>
#include "ResultForm.h"

#include "objects.h"
#include "signals.h"
#include "Declare.h"
#include "IO_declare.h"

#include "Global_Functions.h"

#include "Instance_beckhoff.h"
#include "Instance_siemens.h"
#include "Instance_schneider.h"


// initialise grids for instances
void Instance_init_grids(int AI_nr_max, int  VLV_nr_max, int HC_nr_max, int  FC_nr_max, int  PID_nr_max, int MOT_nr_max, IOlistautomation::ResultForm^ result_form)
{
	int collumns = 11;

	if (AI_nr_max>0)
	{
		result_form->Grid_AI->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_AI->ColumnCount = 0;
		result_form->Grid_AI->Rows->Clear();
	}

	if (VLV_nr_max>0)
	{
		result_form->Grid_VLV->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_VLV->ColumnCount = 0;
		result_form->Grid_VLV->Rows->Clear();
	}

	if (HC_nr_max>0)
	{
		result_form->Grid_HC->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_HC->ColumnCount = 0;
		result_form->Grid_HC->Rows->Clear();
	}

	if (FC_nr_max>0)
	{
		result_form->Grid_FC->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_FC->ColumnCount = 0;
		result_form->Grid_FC->Rows->Clear();
	}

	if (PID_nr_max>0)
	{
		result_form->Grid_PID->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_PID->ColumnCount = 0;
		result_form->Grid_PID->Rows->Clear();
	}

	if (MOT_nr_max>0)
	{
		result_form->Grid_MOT->ColumnCount = collumns;
	}
	else
	{
		result_form->Grid_MOT->ColumnCount = 0;
		result_form->Grid_MOT->Rows->Clear();
	}
}

// add one line to instance grid
void Instance_grid_add_line(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	grid->Rows->Add();
	grid_row_index++;
}
// add data to instance grid
void Instance_grid_write_cell(int &grid_row_index, int collumn,wstring cell_text, System::Windows::Forms::DataGridView^ grid)
{
	grid->Rows[grid_row_index-1]->Cells[collumn]->Value = wstring_to_system_string(cell_text);
}



int Instance_vlv_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid, int cpu_index)
{
	int return_val = 0;
	switch (cpu_index)
	{
	case Beckhoff_index:	
		return_val =Instance_Beckhoff_vlv(index, grid_row_index, grid);
		break;
	case Siemens_index:	
		return_val = Instance_Siemens_vlv(index, grid_row_index, grid);
		break;
	case Schneider_index:	
		return_val = Instance_Schneider_vlv(index, grid_row_index, grid);
		break;
	case ABB_800xA_index:	

		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return -1;
		break;
	}
	return return_val;
}

int Instance_ai_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid, int cpu_index)
{
	int return_val = 0;
	switch (cpu_index)
	{
	case Beckhoff_index:
		return_val = Instance_Beckhoff_ai(index, grid_row_index, grid);
		break;
	case Siemens_index:
		return_val = Instance_Siemens_ai(index, grid_row_index, grid);
		break;
	case Schneider_index:
		return_val = Instance_Schneider_ai(index, grid_row_index, grid);
		break;
	case ABB_800xA_index:

		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return -1;
		break;
	}
	return return_val;
}

int Instance_mot_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid, int cpu_index)
{
	int return_val = 0;
	switch (cpu_index)
	{
	case Beckhoff_index:
		return_val = Instance_Beckhoff_mot(index, grid_row_index, grid);
		break;
	case Siemens_index:
		return_val = Instance_Siemens_mot(index, grid_row_index, grid);
		break;
	case Schneider_index:
		return_val = Instance_Schneider_mot(index, grid_row_index, grid);
		break;
	case ABB_800xA_index:

		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return -1;
		break;
	}
	return return_val;
}

int Instance_pid_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid, int cpu_index)
{
	int return_val = 0;
	switch (cpu_index)
	{
	case Beckhoff_index:
		return_val = Instance_Beckhoff_pid(index, grid_row_index, grid);
		break;
	case Siemens_index:
		return_val = Instance_Siemens_pid(index, grid_row_index, grid);
		break;
	case Schneider_index:
		return_val = Instance_Schneider_pid(index, grid_row_index, grid);
		break;
	case ABB_800xA_index:

		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return -1;
		break;
	}
	return return_val;
}

int Instance_hc_switch(int index, int &grid_row_index, System::Windows::Forms::DataGridView^ grid, int cpu_index)
{
	int return_val = 0;
	switch (cpu_index)
	{
	case Beckhoff_index:
		return_val = Instance_Beckhoff_hc(index, grid_row_index, grid);
		break;
	case Siemens_index:
		return_val = Instance_Siemens_hc(index, grid_row_index, grid);
		break;
	case Schneider_index:
		return_val = Instance_Schneider_hc(index, grid_row_index, grid);
		break;
	case ABB_800xA_index:

		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return -1;
		break;
	}
	return return_val;
}



int Instance_gen(bool test_mode, int cpu_index)
{
	if (cpu_index == ABB_800xA_index)
	{
		if (test_mode == true)
			return 0;
		strcpy_s(err_txt, sizeof err_txt, err_no_function_for_this[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, Global_get_CPU_name(cpu_index));
		err_write_show(err_txt);
		return 0;
	}

	Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with, false);
	if (signals.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, signals_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with, false);
	if (objects.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
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

	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(cpu_index));
	info_write(info_txt);

	Instance_init_grids(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max,%results_form);


	Show_progress(prog_declare[lang], objects.valid_entries);

	int AI_grid_row = 0;
	int VLV_grid_row = 0;
	int HC_grid_row = 0;
	int FC_grid_row = 0;
	int PID_grid_row = 0;
	int MOT_grid_row = 0;

	wstring object_type = L"";

	int ai_indirect_ats = 0;
	int hc_indirect_ats = 0;
	int fc_indirect_ats = 0;
	int pid_indirect_ats = 0;
	int mot_indirect_ats = 0;
	int vlv_indirect_ats = 0;

	int object_init = 0;

	Declare_count_indirects(ai_indirect_ats, hc_indirect_ats, fc_indirect_ats, pid_indirect_ats, mot_indirect_ats, vlv_indirect_ats);

	if(ai_indirect_ats>0)
	{
		object_init++;
	}
	if (hc_indirect_ats>0)
	{
		object_init++;
	}
	if (fc_indirect_ats>0)
	{
		object_init++;
	}
	if (pid_indirect_ats>0)
	{
		object_init++;
	}
	if (mot_indirect_ats>0)
	{
		object_init++;
	}
	if (vlv_indirect_ats>0)
	{
		object_init++;
	}

	int return_val = 0;
	for (int index = object_init; index <= objects.valid_entries; ++index)
	{
		object_type = objects.data[index].Object_type;

		if (object_type.compare(AI_type) == 0)
		{
			return_val=Instance_ai_switch(index, AI_grid_row, results_form.Grid_AI, cpu_index);
		}
		else if (object_type.compare(Vlv_type) == 0)
		{
			return_val=Instance_vlv_switch(index, VLV_grid_row, results_form.Grid_VLV, cpu_index);
		}
		else if (object_type.compare(HC_type) == 0)
		{
			return_val =Instance_hc_switch(index, HC_grid_row, results_form.Grid_HC, cpu_index);
		}
		else if (object_type.compare(PID_type) == 0)
		{
			return_val =Instance_pid_switch(index, PID_grid_row, results_form.Grid_PID, cpu_index);
		}
		else if (object_type.compare(Mot_type) == 0)
		{
			return_val=Instance_mot_switch(index, MOT_grid_row, results_form.Grid_MOT, cpu_index);
		}

		if (return_val != 0)
		{
			Hide_progress();
			return 1;
		}
		set_progress_value(index);
	}


	Hide_progress();

	Declare_dump_to_file(test_mode, results_form.Grid_AI, "inst_AI");
	Declare_dump_to_file(test_mode, results_form.Grid_FC, "inst_FC");
	Declare_dump_to_file(test_mode, results_form.Grid_HC, "inst_HC");
	Declare_dump_to_file(test_mode, results_form.Grid_MOT, "inst_MOT");
	Declare_dump_to_file(test_mode, results_form.Grid_PID, "inst_PID");
	Declare_dump_to_file(test_mode, results_form.Grid_VLV, "inst_VLV");
	Declare_dump_to_file(test_mode, results_form.Grid_SCADA, "inst_SCADA");

	if (test_mode == false)
	{
		results_form.ShowDialog();
		results_form.Update();
	}

	// after succesful instance generation update where used IO is
	Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);

	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(cpu_index));
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}