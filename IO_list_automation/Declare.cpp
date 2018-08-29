#include "config.h"
#include "Declare.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "Address_Form.h"
#include "ResultForm.h"

#include "objects.h"

#define max_objects  6
#define max_vars_in_object  5

#define new_row_offset 2
 
//return area meaning as string >0 DB[nr],  0 M, -1 MW, -2 QX, -3 QW;  -4 IX;  -5 IW; -99 ignore adressing
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
		return L"%M";
		break;
	case -1:
		return L"%MW";
		break;
	case -2:
		return L"%QX";
		break;
	case -3:
		return L"%QW";
		break;
	case -4:
		return L"%IX";
		break;
	case -5:
		return L"%IW";
		break;
	case -99:
		return L"";
		break;
	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return NULL;
		break;
	}
	return 0;
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


// count number of all diferent object types
int Declare_count_objects(int &AI_nr_max, int &VLV_nr_max, int &HC_nr_max, int &FC_nr_max, int &PID_nr_max, int &MOT_nr_max)
{
	wstring object_type = L"";
	AI_nr_max = 0;
	VLV_nr_max = 0;
	HC_nr_max = 0;
	FC_nr_max = 0;
	PID_nr_max = 0;
	MOT_nr_max = 0;

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
	}
	if ((AI_nr_max + VLV_nr_max + HC_nr_max + FC_nr_max + PID_nr_max + MOT_nr_max) == 0)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_object_types_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	return 0;
}
//check if there is indirect adress in objects
void Declare_count_indirects(int &ai_indirect_ats,int &hc_indirect_ats,int &fc_indirect_ats,int &pid_indirect_ats,int &mot_indirect_ats,int &vlv_indirect_ats)
{
	ai_indirect_ats = 0;
	hc_indirect_ats = 0;
	fc_indirect_ats = 0;
	pid_indirect_ats = 0;
	mot_indirect_ats = 0;
	vlv_indirect_ats = 0;

	wstring indirect_text = L"indirect";
	wstring test_text;
	int size_text = indirect_text.size();
	int indirect_ats = 0;

	for (int i = 0; i < max_objects; i++)
	{
		indirect_ats = objects.data[i].KKS.find(indirect_text);
		if (indirect_ats >= 0)
		{
			test_text = objects.data[i].KKS.substr(size_text + 1);

			if (test_text.find(AI_type) != -1)
			{
				ai_indirect_ats = 1;
			}

			if (test_text.find(Vlv_type) != -1)
			{
				vlv_indirect_ats = 1;
			}

			if (test_text.find(HC_type) != -1)
			{
				hc_indirect_ats = 1;
			}

			if (test_text.find(FC_type) != -1)
			{
				fc_indirect_ats = 1;
			}

			if (test_text.find(PID_type) != -1)
			{
				pid_indirect_ats = 1;
			}

			if (test_text.find(Mot_type) != -1)
			{
				mot_indirect_ats = 1;
			}
		}
	}
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
		for (int j = 1; j <= max_vars_in_object; j++)
		{
			// going through all variables
			switch (j)
			{
			case w1_index:
				test_in_1part = test_in_object.w1;
				break;
			case w2_index:
				test_in_1part = test_in_object.w2;
				break;
			case cmd_index:
				test_in_1part = test_in_object.cmd;
				break;
			case val_index:
				test_in_1part = test_in_object.val;
				break;
			case pars_index:
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
		for (int j = 1; j <= max_vars_in_object; j++)
		{			
			switch (j)
			{
			case w1_index:
				test_part1 = test.w1;
				break;
			case w2_index:
				test_part1 = test.w2;
				break;
			case cmd_index:
				test_part1 = test.cmd;
				break;
			case val_index:
				test_part1 = test.val;
				break;
			case pars_index:
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


// adress declaring for one object
void Declare_adresses_1object(int object_index, int &adress_index, addres_pars_str adress_parameters)
{
	// clear all data before adding
	objects.data[object_index].Adress_sw1 = L"";
	objects.data[object_index].Adress_sw2 = L"";
	objects.data[object_index].Adress_val = L"";
	objects.data[object_index].Adress_pars = L"";
	objects.data[object_index].Adress_cmd = L"";

	// area name + address
	wstring adress_text = L"";
	if (adress_parameters.w1.offset > 0)
	{
		adress_text = int_to_wstring(adress_parameters.w1.start_adr + adress_index * adress_parameters.w1.offset, 0);
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
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(parameters.CPU));	
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

	if (Declare_count_objects(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max) > 0)
	{
		return 1;
	}
	
	//check if there is indirects
	// if using indirects add one extra adress
	if (parameters.indirect == 1)
	{
		wstring indirect_text = L"indirect";

		int ai_indirect_ats = 0;
		int hc_indirect_ats = 0;
		int fc_indirect_ats = 0;
		int pid_indirect_ats = 0;
		int mot_indirect_ats = 0;
		int vlv_indirect_ats = 0;

		Declare_count_indirects(ai_indirect_ats, hc_indirect_ats, fc_indirect_ats, pid_indirect_ats, mot_indirect_ats, vlv_indirect_ats);

		object_data_str empty_element = {};
		if (AI_nr_max > 0 && ai_indirect_ats<=0)
		{
			AI_nr_max++;			
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = AI_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
		if (VLV_nr_max > 0 && vlv_indirect_ats<=0)
		{
			VLV_nr_max++;
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = Vlv_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
		if (HC_nr_max > 0 && hc_indirect_ats<=0)
		{
			HC_nr_max++;
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = HC_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
		if (FC_nr_max > 0 && fc_indirect_ats<=0)
		{
			FC_nr_max++;
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = FC_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
		if (PID_nr_max > 0 && pid_indirect_ats<=0)
		{
			PID_nr_max++;
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = PID_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
		if (MOT_nr_max > 0 && mot_indirect_ats<=0)
		{
			MOT_nr_max++;
			objects.data.insert(objects.data.begin(), empty_element);
			objects.data[0].number = L"0";
			objects.data[0].Object_type = Mot_type;
			objects.data[0].KKS = indirect_text;
			objects.data[0].KKS.append(L"_");
			objects.data[0].KKS.append(objects.data[0].Object_type);
		}
	}

	check_result_str result_ob;

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

	wstring object_type = L"";
	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		object_type = objects.data[index].Object_type;
		if (object_type.empty() == 0) // if found object type
		{
			if (object_type.compare(AI_type)==0)
			{
				Declare_adresses_1object(index, AI_nr, used_CPU.ai);
			}
			else if (object_type.compare(Vlv_type) == 0)
			{
				Declare_adresses_1object(index, VLV_nr, used_CPU.vlv);
			}
			else if (object_type.compare(HC_type) == 0)
			{
				Declare_adresses_1object(index, HC_nr, used_CPU.hc);
			}
			else if (object_type.compare(FC_type) == 0)
			{
				Declare_adresses_1object(index, FC_nr, used_CPU.fc);
			}
			else if (object_type.compare(PID_type) == 0)
			{
				Declare_adresses_1object(index, PID_nr, used_CPU.pid);
			}
			else if (object_type.compare(Mot_type) == 0)
			{
				Declare_adresses_1object(index, MOT_nr, used_CPU.mot);
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
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(parameters.CPU));
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);
	Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	return 0;
}

// check if there is any adress in object
int Declare_valid_adress(int row)
{
	if (objects.data[row].Adress_cmd.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Adress_pars.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Adress_sw1.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Adress_sw2.empty() == 0)
	{
		return 1;
	}
	if (objects.data[row].Adress_val.empty() == 0)
	{
		return 1;
	}

	return 0;
}

wstring Declare_Beckhoff(int index, int iCol, int variable_index,wstring object_type)
{
	if (iCol > 4)
	{
		return L"";
	}
	wstring texts;
	wstring KKS_suffix = L"";
	wstring KKS_prefix = L"";
	wstring adress = L"";
	wstring variable_type = L"";

			switch (variable_index)
			{
			case fb_index:
				KKS_prefix = L"fb_";
				KKS_suffix = L"";

				adress = L"";

				variable_type = L":FB_";
				variable_type.append(object_type);
				variable_type.append(L";");
				break;
			case w1_index:
				KKS_prefix = L"";
				KKS_suffix = L"_w1";

				adress = L"AT ";
				adress.append(objects.data[index].Adress_sw1);

				variable_type = L":WORD;";				
				break;
			case w2_index:
				KKS_prefix = L"";
				KKS_suffix = L"_w2";

				adress = L"AT ";
				adress.append(objects.data[index].Adress_sw2);

				variable_type = L":WORD;";				
				break;
			case cmd_index:
				KKS_prefix = L"";
				KKS_suffix = L"_cmd";

				adress = L"AT ";
				adress.append(objects.data[index].Adress_cmd);

				variable_type = L"";				
				break;
			case val_index:
				KKS_prefix = L"";
				KKS_suffix = L"";

				adress = L"AT ";
				adress.append(objects.data[index].Adress_val);

				variable_type = L":REAL;";				
				break;
			case pars_index:
				KKS_suffix = L"_pars";

				adress = L"AT ";
				adress.append(objects.data[index].Adress_pars);

				variable_type = L":";
				variable_type.append(object_type);
				variable_type.append(L"_pars;");				
				break;



			default:
				strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
				err_write_show(err_txt);
				return L"";
				break;
			}


			switch (iCol)
			{
			case 0:
				return L"";
				break;
			case 1:
				texts = KKS_prefix;
				texts.append(objects.data[index].KKS);
				texts.append(KKS_suffix);
				return texts;
				break;
			case 2:
				return adress;
				break;
			case 3:
				return variable_type;
				break;
			case 4:
				texts = L"(*";
				texts.append(objects.data[index].Object_text);
				texts.append(L"*)");
				return texts;
				break;
			}		
	
	return L"";
}

wstring Declare_ABB_800xA(int index, int iCol, int variable_index, wstring object_type)
{
	if (iCol > 6)
	{
		return L"";
	}
	wstring texts;
	wstring adress = L"";
	wstring KKS_suffix = L"";
	wstring KKS_prefix = L"";

	switch (variable_index)
	{
	case fb_index:
		KKS_prefix = L"fb_";
		KKS_suffix = L"";
		adress = L"";

		break;
	case w1_index:
		KKS_prefix = L"";
		KKS_suffix = L"_W1";

		adress = objects.data[index].Adress_sw1;
		break;
	case w2_index:
		KKS_prefix = L"";
		KKS_suffix = L"_w2";

		adress = objects.data[index].Adress_sw2;
		break;
	case cmd_index:
		KKS_prefix = L"";
		KKS_suffix = L"_cmd";

		adress = objects.data[index].Adress_cmd;
		break;
	case val_index:
		KKS_prefix = L"";
		KKS_suffix = L"";

		adress = objects.data[index].Adress_val;
		break;
	case pars_index:
		KKS_prefix = L"";
		KKS_suffix = L"_pars";

		adress = objects.data[index].Adress_pars;
		break;

	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return L"";
		break;
	}


	switch (iCol)
	{
	case 0:
		texts = KKS_prefix;
		texts.append(objects.data[index].KKS);
		texts.append(KKS_suffix);
		return texts;
		break;
	case 1:
		texts=object_type;
		texts.append(L"_str");
		return texts;
		break;
	case 2:
		return L"retain";
		break;
	case 3:
		return L"";
		break;
	case 4:
		return L"";
		break;
	case 5:
		return L"";
		break;
	case 6:
		return objects.data[index].Object_text;
		break;
	}

	return L"";
}

wstring Declare_Siemens(int index, int iCol, int variable_index, wstring object_type)
{
	if (iCol > 8)
	{
		return L"";
	}
	wstring texts;
	wstring adress = L"";
	wstring KKS_suffix = L"";
	wstring KKS_prefix = L"";

	switch (variable_index)
	{
	case fb_index:
		KKS_prefix = L"fb_";
		KKS_suffix = L"";
		adress = L"";

		break;
	case w1_index:
		KKS_prefix = L"";
		KKS_suffix = L"_W1";
		
		adress=objects.data[index].Adress_sw1;
		break;
	case w2_index:
		KKS_prefix = L"";
		KKS_suffix = L"_w2";

		adress=objects.data[index].Adress_sw2;
		break;
	case cmd_index:
		KKS_prefix = L"";
		KKS_suffix = L"_cmd";

		adress=objects.data[index].Adress_cmd;
		break;
	case val_index:
		KKS_prefix = L"";
		KKS_suffix = L"";

		adress=objects.data[index].Adress_val;
		break;
	case pars_index:
		KKS_prefix = L"";
		KKS_suffix = L"_pars";

		adress=objects.data[index].Adress_pars;
		break;

	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return L"";
		break;
	}


	switch (iCol)
	{
	case 0:
		texts = KKS_prefix;
		texts.append(objects.data[index].KKS);
		texts.append(KKS_suffix);
		return texts;
		break;
	case 1:
		texts = L"UDT_";
		texts.append(object_type);
		return texts;
		break;
	case 2:
//		return adress;
		return L"...";
		break;
	case 3:
		return L"";
		break;
	case 4:
		return L"";
		break;
	case 5:
		return L"TRUE";
		break;
	case 6:
		return L"TRUE";
		break;
	case 7:
		return L"FALSE";
		break;
	case 8:
		return objects.data[index].Object_text;
		break;
	}

	return L"";
}

wstring Declare_Schneider(int index, int iCol, int variable_index, wstring object_type)
{
	if (iCol > 4)
	{
		return L"";
	}
	wstring texts;
	wstring KKS_suffix = L"";
	wstring KKS_prefix = L"";
	wstring adress = L"";
	wstring variable_type = L"";

	switch (variable_index)
	{
	case fb_index:
		KKS_prefix = L"fb_";
		KKS_suffix = L"";

		adress = L"";

		variable_type = L":FB_";
		variable_type.append(object_type);
		variable_type.append(L";");
		break;
	case w1_index:
		KKS_prefix = L"";
		KKS_suffix = L"_w1";

		adress = L"AT ";
		adress.append(objects.data[index].Adress_sw1);

		variable_type = L":WORD;";
		break;
	case w2_index:
		KKS_prefix = L"";
		KKS_suffix = L"_w2";

		adress = L"AT ";
		adress.append(objects.data[index].Adress_sw2);

		variable_type = L":WORD;";
		break;
	case cmd_index:
		KKS_prefix = L"";
		KKS_suffix = L"_cmd";

		adress = L"AT ";
		adress.append(objects.data[index].Adress_cmd);

		variable_type = L"";
		break;
	case val_index:
		KKS_prefix = L"";
		KKS_suffix = L"";

		adress = L"AT ";
		adress.append(objects.data[index].Adress_val);

		variable_type = L":REAL;";
		break;
	case pars_index:
		KKS_suffix = L"_pars";

		adress = L"AT ";
		adress.append(objects.data[index].Adress_pars);

		variable_type = L":";
		variable_type.append(object_type);
		variable_type.append(L"_pars;");
		break;



	default:
		strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
		err_write_show(err_txt);
		return L"";
		break;
	}


	switch (iCol)
	{
	case 0:
		return L"";
		break;
	case 1:
		texts = KKS_prefix;
		texts.append(objects.data[index].KKS);
		texts.append(KKS_suffix);
		return texts;
		break;
	case 2:
		return adress;
		break;
	case 3:
		return variable_type;
		break;
	case 4:
		texts = L"(*";
		texts.append(objects.data[index].Object_text);
		texts.append(L"*)");
		return texts;
		break;
	}

	return L"";
}

void Declare_init_grids(int AI_nr_max,int  VLV_nr_max, int HC_nr_max,int  FC_nr_max,int  PID_nr_max,int MOT_nr_max,IOlistautomation::ResultForm^ result_form)
{
	int collumns = 11;
	int variable_count = 0;  
	int variable_count_init = 0;

	addres_pars_CPU_str used_CPU;
	switch (parameters.CPU)
	{
	case Beckhoff_index:
		used_CPU = adres.Beckhoff;
		variable_count_init = 1;
		break;
	case ABB_800xA_index:
		used_CPU = adres.ABB_800xA;
		break;
	case Schneider_index:
		used_CPU = adres.Schneider;
		variable_count_init = 1;
		break;
	case Siemens_index:
		used_CPU = adres.Siemens;
		break;
	}

	if (AI_nr_max>0)
	{
		result_form->Grid_AI->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.ai.cmd.offset > 0) + (used_CPU.ai.w1.offset > 0) + (used_CPU.ai.w2.offset > 0) + (used_CPU.ai.val.offset > 0) + (used_CPU.ai.pars.offset > 0);
		result_form->Grid_AI->RowCount = (AI_nr_max + new_row_offset)*variable_count+1;
	}
	else
	{
		result_form->Grid_AI->ColumnCount = 0;
		result_form->Grid_AI->Rows->Clear();
	}

	if (VLV_nr_max>0)
	{
		result_form->Grid_VLV->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.vlv.cmd.offset > 0) + (used_CPU.vlv.w1.offset > 0) + (used_CPU.vlv.w2.offset > 0) + (used_CPU.vlv.val.offset > 0) + (used_CPU.vlv.pars.offset > 0);
		result_form->Grid_VLV->RowCount = (VLV_nr_max + new_row_offset)*variable_count + 1;
	}
	else
	{
		result_form->Grid_VLV->ColumnCount = 0;
		result_form->Grid_VLV->Rows->Clear();
	}

	if (HC_nr_max>0)
	{
		result_form->Grid_HC->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.hc.cmd.offset > 0) + (used_CPU.hc.w1.offset > 0) + (used_CPU.hc.w2.offset > 0) + (used_CPU.hc.val.offset > 0) + (used_CPU.hc.pars.offset > 0);
		result_form->Grid_HC->RowCount = (HC_nr_max + new_row_offset)*variable_count + 1;
	}
	else
	{
		result_form->Grid_HC->ColumnCount = 0;
		result_form->Grid_HC->Rows->Clear();
	}

	if (FC_nr_max>0)
	{
		result_form->Grid_FC->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.fc.cmd.offset > 0) + (used_CPU.fc.w1.offset > 0) + (used_CPU.fc.w2.offset > 0) + (used_CPU.fc.val.offset > 0) + (used_CPU.fc.pars.offset > 0);
		result_form->Grid_FC->RowCount = (FC_nr_max + new_row_offset)*variable_count + 1;
	}
	else
	{
		result_form->Grid_FC->ColumnCount = 0;
		result_form->Grid_FC->Rows->Clear();
	}

	if (PID_nr_max>0)
	{
		result_form->Grid_PID->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.pid.cmd.offset > 0) + (used_CPU.pid.w1.offset > 0) + (used_CPU.pid.w2.offset > 0) + (used_CPU.pid.val.offset > 0) + (used_CPU.pid.pars.offset > 0);
		result_form->Grid_PID->RowCount = (PID_nr_max + new_row_offset)*variable_count + 1;
	}
	else
	{
		result_form->Grid_PID->ColumnCount = 0;
		result_form->Grid_PID->Rows->Clear();
	}

	if (MOT_nr_max>0)
	{
		result_form->Grid_MOT->ColumnCount = collumns;
		variable_count = variable_count_init + (used_CPU.mot.cmd.offset > 0) + (used_CPU.mot.w1.offset > 0) + (used_CPU.mot.w2.offset > 0) + (used_CPU.mot.val.offset > 0) + (used_CPU.mot.pars.offset > 0);
		result_form->Grid_MOT->RowCount = (MOT_nr_max + new_row_offset)*variable_count + 1;
	}
	else
	{
		result_form->Grid_MOT->ColumnCount = 0;
		result_form->Grid_MOT->Rows->Clear();
	}
}

// puting data to grids
int Declare_put_adres_grid()
{
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	int result_adress = 0;

	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(parameters.CPU));
	info_write(info_txt);

	Show_progress(prog_check_adress[lang], objects.valid_entries);
	for (int index = 0; index <= objects.valid_entries; ++index)
	{
		result_adress=Declare_valid_adress(index);
		if (result_adress == 1)
		{
			break;
		}
		set_progress_value(index);
	}
	Hide_progress();
	
	if (result_adress == 0)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_adress_object[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	Show_progress(prog_declare[lang], objects.valid_entries);


	check_result_str result_ob;
	wstring object_type = L"";
	IOlistautomation::ResultForm results_form;

	addres_pars_CPU_str CPU_adr;
	Declare_adress_get_CPU_switch(CPU_adr);

	int AI_nr_max = 0;
	int VLV_nr_max = 0;
	int HC_nr_max = 0;
	int FC_nr_max = 0;
	int PID_nr_max = 0;
	int MOT_nr_max = 0;

	int AI_row = -new_row_offset;
	int VLV_row = -new_row_offset;
	int HC_row = -new_row_offset;
	int FC_row = -new_row_offset;
	int PID_row = -new_row_offset;
	int MOT_row = -new_row_offset;

	int row = 0;

	if (Declare_count_objects(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max) > 0)
	{
		return 1;
	}
	Declare_init_grids(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max,%results_form);

	int iCol;
	wstring cell_text = L"";

	int start_param = 1;

	if ((parameters.CPU == Beckhoff_index) || (parameters.CPU == Schneider_index))
	{
		start_param = 0;
	}

	int AI_valid = 1;
	int VLV_valid = 1;
	int HC_valid = 1;
	int FC_valid = 1;
	int PID_valid = 1;
	int MOT_valid = 1;

	bool row_valid = 1;

	for (int variable_index = start_param; variable_index <= max_vars_in_object; ++variable_index)
	{
		switch (variable_index)
		{
		case fb_index:
			AI_valid = 1;
			VLV_valid = 1;
			HC_valid = 1;
			FC_valid = 1;
			PID_valid = 1;
			MOT_valid = 1;
			break;
		case w1_index:
			AI_valid = CPU_adr.ai.w1.offset>0;
			VLV_valid = CPU_adr.vlv.w1.offset>0;
			HC_valid = CPU_adr.hc.w1.offset>0;
			FC_valid = CPU_adr.fc.w1.offset>0;
			PID_valid = CPU_adr.pid.w1.offset>0;
			MOT_valid = CPU_adr.mot.w1.offset>0;
			break;
		case w2_index:
			AI_valid = CPU_adr.ai.w2.offset>0;
			VLV_valid = CPU_adr.vlv.w2.offset>0;
			HC_valid = CPU_adr.hc.w2.offset>0;
			FC_valid = CPU_adr.fc.w2.offset>0;
			PID_valid = CPU_adr.pid.w2.offset>0;
			MOT_valid = CPU_adr.mot.w2.offset>0;
			break;
		case cmd_index:
			AI_valid = CPU_adr.ai.cmd.offset>0;
			VLV_valid = CPU_adr.vlv.cmd.offset>0;
			HC_valid = CPU_adr.hc.cmd.offset>0;
			FC_valid = CPU_adr.fc.cmd.offset>0;
			PID_valid = CPU_adr.pid.cmd.offset>0;
			MOT_valid = CPU_adr.mot.cmd.offset>0;
			break;
		case val_index:
			AI_valid = CPU_adr.ai.val.offset>0;
			VLV_valid = CPU_adr.vlv.val.offset>0;
			HC_valid = CPU_adr.hc.val.offset>0;
			FC_valid = CPU_adr.fc.val.offset>0;
			PID_valid = CPU_adr.pid.val.offset>0;
			MOT_valid = CPU_adr.mot.val.offset>0;
			break;
		case pars_index:
			AI_valid = CPU_adr.ai.pars.offset>0;
			VLV_valid = CPU_adr.vlv.pars.offset>0;
			HC_valid = CPU_adr.hc.pars.offset>0;
			FC_valid = CPU_adr.fc.pars.offset>0;
			PID_valid = CPU_adr.pid.pars.offset>0;
			MOT_valid = CPU_adr.mot.pars.offset>0;
			break;
		default:
			strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
			err_write_show(err_txt);
			return 1;
			break;
		}
		AI_row += AI_valid* new_row_offset;
		VLV_row += VLV_valid* new_row_offset;
		HC_row += HC_valid* new_row_offset;
		FC_row += FC_valid* new_row_offset;
		PID_row += PID_valid* new_row_offset;
		MOT_row += MOT_valid* new_row_offset;
	//get number of each structure5
		for (int index = 0; index <= objects.valid_entries; ++index)
		{
			object_type = objects.data[index].Object_type;
			if (object_type.empty() == 0) // if found object type
			{
				if (Declare_valid_adress(index) == 1) // there is adress in line
				{
					System::Windows::Forms::DataGridView^ grid;

					if (object_type.compare(AI_type) == 0)
					{
						row = AI_row;
						grid = results_form.Grid_AI;
						row_valid = AI_valid;
						AI_row += row_valid;
					}
					else if (object_type.compare(Vlv_type) == 0)
					{
						row = VLV_row;
						grid = results_form.Grid_VLV;
						row_valid = VLV_valid;
						VLV_row += row_valid;
					}
					else if (object_type.compare(HC_type) == 0)
					{
						row = HC_row;
						grid = results_form.Grid_HC;
						row_valid = HC_valid;
						HC_row += row_valid;
					}
					else if (object_type.compare(FC_type) == 0)
					{
						row = FC_row;
						grid = results_form.Grid_FC;
						row_valid = FC_valid;
						FC_row += row_valid;
					}
					else if (object_type.compare(PID_type) == 0)
					{
						row = PID_row;
						grid = results_form.Grid_PID;
						row_valid = PID_valid;
						PID_row+= row_valid;
						
					}
					else if (object_type.compare(Mot_type) == 0)
					{
						row = MOT_row;
						grid = results_form.Grid_MOT;
						row_valid = MOT_valid;
						MOT_row += row_valid;
					}

					if (row_valid == 1)
					{
						// fill all cells with data
						for (iCol = 0; iCol <= 10; iCol++)
						{
							switch (parameters.CPU)
							{
							case Beckhoff_index:	cell_text = Declare_Beckhoff(index, iCol, variable_index, object_type);
								break;
							case Siemens_index:	cell_text = Declare_Siemens(index, iCol, variable_index, object_type);
								break;
							case Schneider_index:	cell_text = Declare_Schneider(index, iCol, variable_index, object_type);
								break;
							case ABB_800xA_index:	cell_text = Declare_ABB_800xA(index, iCol, variable_index, object_type);
								break;
							default:
								strcpy_s(err_txt, sizeof err_txt, err_cfg_parameter_programing_error[lang]);
								err_write_show(err_txt);
								return -1;
								break;
							}

							String^ textas = wstring_to_system_string(cell_text);

							// Insert items into the list.
							grid->Rows[row]->Cells[iCol]->Value = textas;
						}
					}

				}
			}
			set_progress_value(index);
		}
	}
	
	Hide_progress();
	
	results_form.ShowDialog();

	results_form.Update();

	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, Global_get_CPU_name(parameters.CPU));
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);	
	return 0;
}