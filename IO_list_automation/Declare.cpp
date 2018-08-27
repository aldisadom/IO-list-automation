#include "config.h"
#include "Declare.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "Address_Form.h"

#include "objects.h"

#define max_objects  6
#define max_vars_in_object  5
 
//return area meaning as string >0 DB[nr],  0 MQ, -1 MW, -2 QX, -3 QW;  -4 IX;  -5 IW; 
wstring Declare_area_switch(int area)
{
	wstring text;
	int db_nr = 0;
	if (area > 0)
	{
		db_nr = area;
		area = 1;
	}
	// 
	switch (area)
	{
	case 1:
		text = L"DB";
		text.append(int_to_wstring(db_nr, 0));
		text.append(L".DBB ");
		return text;
		break;
	case 0:
		return L"%MQ ";
		break;
	case -1:
		return L"%MW ";
		break;
	case -2:
		return L"%QX ";
		break;
	case -3:
		return L"%QW ";
		break;
	case -4:
		return L"%IX ";
		break;
	case -5:
		return L"%IW ";
		break;

	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return NULL;
		break;
	}
	return 0;
}

// adress declaring
void Declare_adresses(int object_index, int &adress_index, addres_pars_str adress_parameters)
{
	// area name + address
	wstring adress_text = L"";
	if (adress_parameters.w1.offset > 0)
	{
		adress_text= int_to_wstring(adress_parameters.w1.start_adr + adress_index * adress_parameters.w1.offset,0);
		objects.data[object_index].Adress_sw1 = Declare_area_switch(adress_parameters.w1.area);
		objects.data[object_index].Adress_sw1.append(adress_text);
	}
	if (adress_parameters.w2.offset > 0)
	{
		adress_text = int_to_wstring(adress_parameters.w2.start_adr + adress_index * adress_parameters.w2.offset, 0);
		objects.data[object_index].Adress_sw2 = Declare_area_switch(adress_parameters.w2.area);
		objects.data[object_index].Adress_sw2.append(adress_text);
	}
	if (adress_parameters.cmd.offset > 0)
	{
		adress_text = int_to_wstring(adress_parameters.cmd.start_adr + adress_index * adress_parameters.cmd.offset, 0);
		objects.data[object_index].Adress_cmd = Declare_area_switch(adress_parameters.cmd.area);
		objects.data[object_index].Adress_cmd.append(adress_text);
	}
	if (adress_parameters.val.offset > 0)
	{
		adress_text = int_to_wstring(adress_parameters.val.start_adr + adress_index * adress_parameters.val.offset, 0);
		objects.data[object_index].Adress_val = Declare_area_switch(adress_parameters.val.area);
		objects.data[object_index].Adress_val.append(adress_text);
	}
	if (adress_parameters.pars.offset > 0)
	{
		adress_text = int_to_wstring(adress_parameters.pars.start_adr + adress_index * adress_parameters.pars.offset, 0);
		objects.data[object_index].Adress_pars = Declare_area_switch(adress_parameters.pars.area);
		objects.data[object_index].Adress_pars.append(adress_text);
	}
	adress_index++;
}

// check if ranges overlap
int overlap(int x_min, int x_max, int y_min, int y_max)
{
	return (x_max > y_min) && (x_min < y_max);	
}

// test one variable range if it overlaps with all other variable ranges
int Declare_adress_1test(int obj_type, int obj_var, adr_1test_str test_for_1part, adr_cpu_test_str test_CPU)
{
	int result = 0;

	adr_1test_str test_in_1part;
	adr_test_str test_in_object;
	if (test_for_1part.area == -99)
	{
		return 0;
	}

	// going through all objects
	for (int i = 0; i < max_objects; i++)
	{
		switch (i)
		{
		case 0:
			test_in_object = test_CPU.ai;
			break;
		case 1:
			test_in_object = test_CPU.vlv;
			break;
		case 2:
			test_in_object = test_CPU.hc;
			break;
		case 3:
			test_in_object = test_CPU.fc;
			break;
		case 4:
			test_in_object = test_CPU.pid;
			break;
		case 5:
			test_in_object = test_CPU.mot;
			break;

		default:
			strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
			err_write_show(err_txt);
			return -1;
			break;
		}

		for (int j = 0; j < max_vars_in_object; j++)
		{
			// going through all variables
			switch (j)
			{
			case 0:
				test_in_1part = test_in_object.w1;
				break;
			case 1:
				test_in_1part = test_in_object.w2;
				break;
			case 2:
				test_in_1part = test_in_object.cmd;
				break;
			case 3:
				test_in_1part = test_in_object.val;
				break;
			case 4:
				test_in_1part = test_in_object.pars;
				break;
			}
			// ignoring check object
			if ((j != obj_var) || (i != obj_type))
			{
				if (test_for_1part.area == test_in_1part.area)
				{
					result = overlap(test_for_1part.start_adr, test_for_1part.end_adress, test_in_1part.start_adr, test_in_1part.end_adress);
					if (result > 0)
					{
						return 1;
					}
				}
			}			
		}
	}
	return 0;
}

// get objects all variables adresses
void Declare_adress_get1_values(int nr_max, adr_test_str &adr_test, addres_pars_str adres_info)
{
	// if there is at least one object
	if (nr_max > 0)
	{
		//calculate it start adress, end adress and transfr area for testing
		if (adres_info.w1.offset > 0)
		{
			adr_test.w1.start_adr = adres_info.w1.start_adr;
			adr_test.w1.end_adress = adres_info.w1.start_adr + adres_info.w1.offset*nr_max;
			adr_test.w1.area = adres_info.w1.area;

		}
		if (adres_info.w2.offset > 0)
		{
			adr_test.w2.start_adr = adres_info.w2.start_adr;
			adr_test.w2.end_adress = adres_info.w2.start_adr + adres_info.w2.offset*nr_max;
			adr_test.w2.area = adres_info.w2.area;
		}
		if (adres_info.cmd.offset > 0)
		{
			adr_test.cmd.start_adr = adres_info.cmd.start_adr;
			adr_test.cmd.end_adress = adres_info.cmd.start_adr + adres_info.cmd.offset*nr_max;
			adr_test.cmd.area = adres_info.cmd.area;
		}
		if (adres_info.val.offset > 0)
		{
			adr_test.val.start_adr = adres_info.val.start_adr;
			adr_test.val.end_adress = adres_info.val.start_adr + adres_info.val.offset*nr_max;
			adr_test.val.area = adres_info.val.area;
		}
		if (adres_info.pars.offset > 0)
		{
			adr_test.pars.start_adr = adres_info.pars.start_adr;
			adr_test.pars.end_adress = adres_info.pars.start_adr + adres_info.pars.offset*nr_max;
			adr_test.pars.area = adres_info.pars.area;
		}
	}
}
//get all objects adresses
void Declare_adress_get_values(int AI_nr_max, int VLV_nr_max, int HC_nr_max, int FC_nr_max, int PID_nr_max, int MOT_nr_max, adr_cpu_test_str &adr_test, addres_pars_CPU_str adres_info)
{
	Declare_adress_get1_values(AI_nr_max, adr_test.ai, adres_info.ai);
	Declare_adress_get1_values(VLV_nr_max, adr_test.vlv, adres_info.vlv);
	Declare_adress_get1_values(HC_nr_max, adr_test.hc, adres_info.hc);
	Declare_adress_get1_values(FC_nr_max, adr_test.fc, adres_info.fc);
	Declare_adress_get1_values(PID_nr_max, adr_test.pid, adres_info.pid);
	Declare_adress_get1_values(MOT_nr_max, adr_test.mot, adres_info.mot);
}

// get what cpu is used
int Declare_adress_get_CPU_switch(addres_pars_CPU_str &CPU_adr)
{
	switch (parameters.CPU)
	{
	case Beckhoff_index:
		CPU_adr = adres.Beckhoff;
		break;
	case ABB_800xA_index:
		CPU_adr = adres.ABB_800xA;
		break;
	case Schneider_index:
		CPU_adr = adres.Schneider;
		break;
	case Siemens_index:
		CPU_adr = adres.Siemens;
		break;

	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return 1;
		break;
	}
	return 0;
}

// put cpu data to global memory
int Declare_adress_put_CPU_switch(addres_pars_CPU_str &CPU_adr)
{
	switch (parameters.CPU)
	{
	case Beckhoff_index:
		adres.Beckhoff = CPU_adr;
		break;
	case ABB_800xA_index:
		adres.ABB_800xA = CPU_adr;
		break;
	case Schneider_index:
		adres.Schneider = CPU_adr;
		break;
	case Siemens_index:
		adres.Schneider = CPU_adr;
		break;

	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return 1;
		break;
	}
	return 0;
}

//test if there is at least one overlap in all adresses
int Declare_adress_test(int AI_nr_max, int VLV_nr_max, int HC_nr_max, int FC_nr_max, int PID_nr_max, int MOT_nr_max,  check_result_str &result_obj, adr_cpu_test_str &test_CPU_adr)
{
	addres_pars_CPU_str CPU_adr;
	
	if (Declare_adress_get_CPU_switch(CPU_adr) == 1)
	{
		return -1;
	}


	Show_progress(prog_overlap[lang], objects.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_overlap_adresses[lang]);
	info_write(info_txt);

	Declare_adress_get_values(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max, test_CPU_adr, CPU_adr);


	adr_test_str test;
	adr_1test_str test_part1;

	int result = 0;
	int overlap = 0;

	// going through all objects
	for (int i = 0; i < max_objects; i++)
	{
		switch (i)
		{
		case 0:
			test = test_CPU_adr.ai;
			break;
		case 1:
			test = test_CPU_adr.vlv;
			break;
		case 2:
			test = test_CPU_adr.hc;
			break;
		case 3:
			test = test_CPU_adr.fc;
			break;
		case 4:
			test = test_CPU_adr.pid;
			break;
		case 5:
			test = test_CPU_adr.mot;
			break;

		default:
			strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
			err_write_show(err_txt);
			return -1;
			break;
		}
		overlap = 0;
		//going through all variables
		for (int j = 0; j < max_vars_in_object; j++)
		{
			switch (j)
			{
			case 0:
				test_part1 = test.w1;
				break;
			case 1:
				test_part1 = test.w2;
				break;
			case 2:
				test_part1 = test.cmd;
				break;
			case 3:
				test_part1 = test.val;
				break;
			case 4:
				test_part1 = test.pars;
				break;
			}
			result = Declare_adress_1test(i, j, test_part1, test_CPU_adr);
			overlap |= result << j; // each variable has its bit

			//put overlap in coresponding integer
			switch (i)
			{
			case 0:
				result_obj.ai = overlap;
				break;
			case 1:
				result_obj.vlv = overlap;
				break;
			case 2:
				result_obj.hc = overlap;
				break;
			case 3:
				result_obj.fc = overlap;
				break;
			case 4:
				result_obj.pid = overlap;
				break;
			case 5:
				result_obj.mot = overlap;
				break;
			}
		}
	}

	strcpy_s(info_txt, sizeof info_txt, info_overlap_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	result = result_obj.ai + result_obj.vlv + result_obj.hc + result_obj.fc + result_obj.pid + result_obj.mot;
	return (result>0);
}

// Declare adreses
int Declare_addreses()
{
	GlobalForm::forma->tabControl1->SelectedIndex = Objects_grid_index;

	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	Show_progress(prog_adress[lang], objects.valid_entries);
	strcpy_s(info_txt, sizeof info_txt, info_get_adresses[lang]);
	info_write(info_txt);

	int AI_nr = 0;
	int VLV_nr = 0;
	int HC_nr = 0;
	int FC_nr = 0;
	int PID_nr = 0;
	int MOT_nr = 0;

	int AI_nr_max = 0;
	int VLV_nr_max = 0;
	int HC_nr_max = 0;
	int FC_nr_max = 0;
	int PID_nr_max = 0;
	int MOT_nr_max = 0;

	check_result_str result_ob;
	wstring object_type = L"";

	//get number of each structure
	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		object_type = objects.data[index].Object_type;
		if (object_type.empty() == 0) // if found object type
		{
			if (object_type.compare(AI_type) == 0)
			{
				AI_nr_max++;
			}
			else if (object_type.compare(Vlv_type) == 0)
			{
				VLV_nr_max++;
			}
			else if (object_type.compare(HC_type) == 0)
			{
				HC_nr_max++;
			}
			else if (object_type.compare(FC_type) == 0)
			{
				FC_nr_max++;
			}
			else if (object_type.compare(PID_type) == 0)
			{
				PID_nr_max++;
			}
			else if (object_type.compare(Mot_type) == 0)
			{
				MOT_nr_max++;
			}
		}
		set_progress_value(index);
	}
	// if using indirects add one extra adress
	if (parameters.indirect == 1)
	{
		if (AI_nr_max > 0)
		{
			AI_nr_max++;
		}
		if (VLV_nr_max > 0)
		{
			VLV_nr_max++;
		}
		if (HC_nr_max > 0)
		{
			HC_nr_max++;
		}
		if (FC_nr_max > 0)
		{
			FC_nr_max++;
		}
		if (PID_nr_max > 0)
		{
			PID_nr_max++;
		}
		if (MOT_nr_max > 0)
		{
			MOT_nr_max++;
		}
	}
	
	IOlistautomation::Address_Form forma;
	adr_cpu_test_str test_CPU_adr;

	int result =Declare_adress_test(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max, result_ob, test_CPU_adr);

	forma.AI_nr_max =  AI_nr_max;
	forma.VLV_nr_max = VLV_nr_max;
	forma.HC_nr_max = HC_nr_max;
	forma.FC_nr_max = FC_nr_max;
	forma.PID_nr_max = PID_nr_max;
	forma.MOT_nr_max = MOT_nr_max;

	while (result != 0)
	{
		if (result < 0)
		{
			Hide_progress();
			return 1;
		}
		else
		{
			forma.Adress_init(result_ob, test_CPU_adr, AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max);
			forma.ShowDialog();

			if (forma.return_value == -1)
			{
				Hide_progress();
				return 1;
			}
			result = Declare_adress_test(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max, result_ob, test_CPU_adr);
		}
	}
	addres_pars_CPU_str used_CPU;
	Declare_adress_get_CPU_switch(used_CPU);

	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		object_type = objects.data[index].Object_type;
		if (object_type.empty() == 0) // if found object type
		{
			if (object_type.compare(AI_type)==0)
			{
				Declare_adresses(index, AI_nr, used_CPU.ai);
			}
			else if (object_type.compare(Vlv_type) == 0)
			{
				Declare_adresses(index, VLV_nr, used_CPU.vlv);
			}
			else if (object_type.compare(HC_type) == 0)
			{
				Declare_adresses(index, HC_nr, used_CPU.hc);
			}
			else if (object_type.compare(FC_type) == 0)
			{
				Declare_adresses(index, FC_nr, used_CPU.fc);
			}
			else if (object_type.compare(PID_type) == 0)
			{
				Declare_adresses(index, PID_nr, used_CPU.pid);
			}
			else if (object_type.compare(Mot_type) == 0)
			{
				Declare_adresses(index, MOT_nr, used_CPU.mot);
			}
			else
			{
				string string_tmp = wstring_to_string(object_type);

				strcpy_s(err_txt, sizeof err_txt, err_wrong_object_type[lang]);
				strcat_s(err_txt, sizeof err_txt, error_separator);
				strcat_s(err_txt, sizeof err_txt, string_tmp.c_str());
				err_write_show(err_txt);
			}			
		}
		set_progress_value(index);
	}
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_get_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	return 0;
}
