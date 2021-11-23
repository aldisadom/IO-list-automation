#include "config.h"
#include "Instance_scada.h"

#include <stdio.h>
#include <stdlib.h>
#include "ResultForm.h"

#include "objects.h"
#include "signals.h"
#include "Declare.h"
#include "IO_declare.h"

#include "Instance_platform.h"
#include "Global_Functions.h"

void Platform_get_addr_siemens_data(long &Addres, wstring &Base_addres, wstring Obj_reference, wstring Adress_val)
{
	wstring Tmp_string = L"";
	Base_addres = Obj_reference;
	Base_addres.append(L".");
	Tmp_string = Adress_val;
	Tmp_string = Tmp_string.substr(0, Tmp_string.find(L".", 0));
	Base_addres.append(Tmp_string);
	Base_addres.append(L",");
	Tmp_string = Adress_val;
	Addres = Tmp_string.find(L" ", 0);
	Tmp_string = Tmp_string.substr(Addres + 1, Tmp_string.size() - Addres);
	Addres = wstring_to_long(Tmp_string);
}

void Platform_get_addr_beckhoff_data(long &Addres, wstring &Base_addres, wstring Obj_reference, wstring Adress_val)
{
	wstring Tmp_string = L"";
	Base_addres = Obj_reference;
	Base_addres.append(L".");
	Tmp_string = Adress_val;
	Addres = Tmp_string.find(L"W", 0);
	Tmp_string = Tmp_string.substr(Addres + 1, Tmp_string.size() - Addres);
	Addres = wstring_to_long(Tmp_string);
	Addres = Addres + 400001;
}

int Init_platform_vlv(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";

	Instance_scada_grid_add_line(grid_row_index, grid);
	Instance_scada_grid_write_cell(grid_row_index, 0, L"ParamObjectName", grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, L"Id.KKS", grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, L"Id.OperId", grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, L"Id.Description.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 4, L"Id.Description.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 5, L"Id.Description.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 6, L"Id.Description.RU", grid);	
	Instance_scada_grid_write_cell(grid_row_index, 7, L"StatusAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 8, L"Status2Adress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 9, L"CMDAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 10, L"EigosLaik", grid);
	Instance_scada_grid_write_cell(grid_row_index, 11, L"Type", grid);
	Instance_scada_grid_write_cell(grid_row_index, 12, L"SPAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 13, L"PVAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 14, L"AASRotationAngle", grid);
	Instance_scada_grid_write_cell(grid_row_index, 15, L"CfgEquipType(4 - damper; 3 - vlv; 8 - vlv3, gal nereik)", grid);
	Instance_scada_grid_write_cell(grid_row_index, 16, L"HasReverse", grid);
	Instance_scada_grid_write_cell(grid_row_index, 17, L"DisableConsAlm", grid);
	Instance_scada_grid_write_cell(grid_row_index, 18, L"HasUserControl", grid);
	Instance_scada_grid_write_cell(grid_row_index, 19, L"Me.Cfg.EquipType2", grid);
	Instance_scada_grid_write_cell(grid_row_index, 20, L"Me.Cfg.EquipType3", grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"regStatus", grid);
	Instance_scada_grid_write_cell(grid_row_index, 22, L"regCMD", grid);
	Instance_scada_grid_write_cell(grid_row_index, 23, L"Kp", grid);
	Instance_scada_grid_write_cell(grid_row_index, 24, L"Ti", grid);
	Instance_scada_grid_write_cell(grid_row_index, 25, L"Td", grid);
	Instance_scada_grid_write_cell(grid_row_index, 26, L"Y", grid);
	Instance_scada_grid_write_cell(grid_row_index, 27, L"Ymax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 28, L"Ymin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 29, L"RegSP", grid);
	Instance_scada_grid_write_cell(grid_row_index, 30, L"RegSPmin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 31, L"RegSPmax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 32, L"Reg.SPExt", grid);
	Instance_scada_grid_write_cell(grid_row_index, 33, L"analogas", grid);
	Instance_scada_grid_write_cell(grid_row_index, 34, L"DeadB", grid);
	Instance_scada_grid_write_cell(grid_row_index, 35, L"Hyst", grid);
	Instance_scada_grid_write_cell(grid_row_index, 36, L"Status.Alm.Aux1.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 37, L"Status.Alm.Aux2.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 38, L"Status.Alm.Aux3.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 39, L"Status.Alm.Aux1.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 40, L"Status.Alm.Aux2.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 41, L"Status.Alm.Aux3.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 42, L"Status.Alm.Aux1.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 43, L"Status.Alm.Aux2.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 44, L"Status.Alm.Aux3.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 45, L"Status.Alm.Aux1.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 46, L"Status.Alm.Aux2.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 47, L"Status.Alm.Aux3.Desc.RU", grid);

	return 0;
}

int Init_platform_mot( int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";

	Instance_scada_grid_add_line(grid_row_index, grid);
	Instance_scada_grid_write_cell(grid_row_index, 0, L"ParamObjectName", grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, L"Id.KKS", grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, L"Id.OperId", grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, L"Id.Description.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 4, L"Id.Description.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 5, L"Id.Description.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 6, L"Id.Description.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 7, L"StatusAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 8, L"Status2Adress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 9, L"CMDAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 10, L"HWAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 11, L"Type", grid);
	Instance_scada_grid_write_cell(grid_row_index, 12, L"SPAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 13, L"Spmin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 14, L"Spmax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 15, L"PVAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 16, L"Srove", grid);
	Instance_scada_grid_write_cell(grid_row_index, 17, L"kW", grid);
	Instance_scada_grid_write_cell(grid_row_index, 18, L"kWh", grid);
	Instance_scada_grid_write_cell(grid_row_index, 19, L"AASRotationAngle", grid);
	Instance_scada_grid_write_cell(grid_row_index, 20, L"CfgEquipType(0 - mot, 1 - siurbl, 2 - vent", grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"HasReverse", grid);
	Instance_scada_grid_write_cell(grid_row_index, 22, L"DisableConsAlm", grid);
	Instance_scada_grid_write_cell(grid_row_index, 23, L"HasUserControl", grid);
	Instance_scada_grid_write_cell(grid_row_index, 24, L"Me.Cfg.EquipType2", grid);
	Instance_scada_grid_write_cell(grid_row_index, 25, L"Me.Cfg.EquipType3", grid);
	Instance_scada_grid_write_cell(grid_row_index, 26, L"regStatus", grid);
	Instance_scada_grid_write_cell(grid_row_index, 27, L"regCMD", grid);
	Instance_scada_grid_write_cell(grid_row_index, 28, L"Kp", grid);
	Instance_scada_grid_write_cell(grid_row_index, 29, L"Ti", grid);
	Instance_scada_grid_write_cell(grid_row_index, 30, L"Td", grid);
	Instance_scada_grid_write_cell(grid_row_index, 31, L"Y", grid);
	Instance_scada_grid_write_cell(grid_row_index, 32, L"Ymax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 33, L"Ymin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 34, L"RegSP", grid);
	Instance_scada_grid_write_cell(grid_row_index, 35, L"RegSPmin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 36, L"RegSPmax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 37, L"Reg.SPExt", grid);
	Instance_scada_grid_write_cell(grid_row_index, 38, L"analogas", grid);
	Instance_scada_grid_write_cell(grid_row_index, 39, L"DeadB", grid);
	Instance_scada_grid_write_cell(grid_row_index, 40, L"Hyst", grid);
	Instance_scada_grid_write_cell(grid_row_index, 41, L"Status.Alm.Aux1.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 42, L"Status.Alm.Aux2.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 43, L"Status.Alm.Aux3.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 44, L"Status.Alm.Aux1.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 45, L"Status.Alm.Aux2.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 46, L"Status.Alm.Aux3.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 47, L"Status.Alm.Aux1.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 48, L"Status.Alm.Aux2.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 49, L"Status.Alm.Aux3.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 50, L"Status.Alm.Aux1.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 51, L"Status.Alm.Aux2.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 52, L"Status.Alm.Aux3.Desc.RU", grid);

	return 0;
}

int Init_platform_pid( int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";

	Instance_scada_grid_add_line(grid_row_index, grid);
	Instance_scada_grid_write_cell(grid_row_index, 0, L"ParamObjectName", grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, L"Id.KKS", grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, L"Id.OperId", grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, L"Id.Description.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 4, L"Id.Description.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 5, L"Id.Description.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 6, L"Id.Description.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 7, L"regStatus", grid);
	Instance_scada_grid_write_cell(grid_row_index, 8, L"regCMD", grid);
	Instance_scada_grid_write_cell(grid_row_index, 9, L"Kp", grid);
	Instance_scada_grid_write_cell(grid_row_index, 10, L"Ti", grid);
	Instance_scada_grid_write_cell(grid_row_index, 11, L"Td", grid);
	Instance_scada_grid_write_cell(grid_row_index, 12, L"Y", grid);
	Instance_scada_grid_write_cell(grid_row_index, 13, L"Ymax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 14, L"Ymin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 15, L"RegSP", grid);
	Instance_scada_grid_write_cell(grid_row_index, 16, L"RegSPmin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 17, L"RegSPmax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 18, L"Reg.SPExt", grid);
	Instance_scada_grid_write_cell(grid_row_index, 19, L"analogas", grid);
	Instance_scada_grid_write_cell(grid_row_index, 20, L"DeadB", grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"Hyst", grid);
	return 0;
}

int Init_platform_hc(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";

	Instance_scada_grid_add_line(grid_row_index, grid);
	Instance_scada_grid_write_cell(grid_row_index, 0, L"ParamObjectName", grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, L"Id.KKS", grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, L"Id.OperId", grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, L"Id.Description.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 4, L"Id.Description.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 5, L"Id.Description.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 6, L"Id.Description.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 7, L"StatusAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 8, L"Status2Adress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 9, L"CMDAdress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 10, L"EigosLaik", grid);
	Instance_scada_grid_write_cell(grid_row_index, 11, L"Type", grid);
	Instance_scada_grid_write_cell(grid_row_index, 12, L"ReverseDelay", grid);
	Instance_scada_grid_write_cell(grid_row_index, 13, L"Cfg.DelayReverseSCADApv", grid);
	Instance_scada_grid_write_cell(grid_row_index, 14, L"Cfg.DelayReverseSCADAsp", grid);
	Instance_scada_grid_write_cell(grid_row_index, 15, L"GreitRevTime", grid);
	Instance_scada_grid_write_cell(grid_row_index, 16, L"AASRotationAngle", grid);
	Instance_scada_grid_write_cell(grid_row_index, 17, L"CfgEquipType", grid);
	Instance_scada_grid_write_cell(grid_row_index, 18, L"HasReverse", grid);
	Instance_scada_grid_write_cell(grid_row_index, 19, L"DisableConsAlm", grid);
	Instance_scada_grid_write_cell(grid_row_index, 20, L"HasUserControl", grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"Me.Cfg.EquipType2", grid);
	Instance_scada_grid_write_cell(grid_row_index, 22, L"Me.Cfg.EquipType3", grid);
	Instance_scada_grid_write_cell(grid_row_index, 23, L"Status.Alm.Aux1.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 24, L"Status.Alm.Aux2.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 25, L"Status.Alm.Aux3.Desc.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 26, L"Status.Alm.Aux1.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 27, L"Status.Alm.Aux2.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 28, L"Status.Alm.Aux3.Desc.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 29, L"Status.Alm.Aux1.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 30, L"Status.Alm.Aux2.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 31, L"Status.Alm.Aux3.Desc.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 32, L"Status.Alm.Aux1.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 33, L"Status.Alm.Aux2.Desc.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 34, L"Status.Alm.Aux3.Desc.RU", grid);

	return 0;
}


int Init_platform_ai(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";

	Instance_scada_grid_add_line(grid_row_index, grid);
	Instance_scada_grid_write_cell(grid_row_index, 0, L"ParamObjectName", grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, L"Id.KKS", grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, L"Id.OperId", grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, L"Id.Description.LT", grid);
	Instance_scada_grid_write_cell(grid_row_index, 4, L"Id.Description.EN", grid);
	Instance_scada_grid_write_cell(grid_row_index, 5, L"Id.Description.LV", grid);
	Instance_scada_grid_write_cell(grid_row_index, 6, L"Id.Description.RU", grid);
	Instance_scada_grid_write_cell(grid_row_index, 7, L"EngUnits", grid);
	Instance_scada_grid_write_cell(grid_row_index, 8, L"DI Obj", grid);
	Instance_scada_grid_write_cell(grid_row_index, 9, L"ScanGroup", grid);
	Instance_scada_grid_write_cell(grid_row_index, 10, L"PV Reference", grid);
	Instance_scada_grid_write_cell(grid_row_index, 11, L"AlarmByteAddress (Status)", grid);
	Instance_scada_grid_write_cell(grid_row_index, 12, L"CfgByteAddress (CMD)", grid);
	Instance_scada_grid_write_cell(grid_row_index, 13, L"RangeMinAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 14, L"RangeMaxAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 15, L"HystAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 16, L"LoLoLimitAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 17, L"LoLimitAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 18, L"HiLimitAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 19, L"HiHiLimitAddress", grid);
	Instance_scada_grid_write_cell(grid_row_index, 20, L"Dampher", grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"NUmericFormat", grid);
	Instance_scada_grid_write_cell(grid_row_index, 22, L"ScaleCoef", grid);
	Instance_scada_grid_write_cell(grid_row_index, 23, L"iScONFIGURABLE", grid);
	Instance_scada_grid_write_cell(grid_row_index, 24, L"SP Address", grid);
	Instance_scada_grid_write_cell(grid_row_index, 25, L"OptimalRangeMin", grid);
	Instance_scada_grid_write_cell(grid_row_index, 26, L"OptimaRangeMax", grid);
	Instance_scada_grid_write_cell(grid_row_index, 27, L"PV.IO", grid);
	return 0;
}



int Instance_platform_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";
	wstring Object = L"";
	wstring Obj_reference = L"";
	wstring Base_addres = L"";
	wstring Tmp_string = L"";
	long Addres = 0;

	Instance_scada_grid_add_line(grid_row_index, grid);
	Object = objects.data[index_object].CPU;
	if (Object.empty() != true)
		Object.append(L"_");
	else
		Object = L"";

	cell_text = Object;
	cell_text.append(objects.data[index_object].KKS);
	Instance_scada_grid_write_cell(grid_row_index, 0, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, objects.data[index_object].KKS, grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, objects.data[index_object].operatyv, grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, objects.data[index_object].Object_text, grid);


	cell_text = Object;
	cell_text.append(L"PLC");

	Obj_reference = cell_text;
	cell_text = L"sg.";
	cell_text.append(Obj_reference);
	Obj_reference.append(L".");
	Obj_reference.append(cell_text);

	switch (parameters.CPU)
	{
	case Siemens_index:
		Platform_get_addr_siemens_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//EigosLaik
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 6, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//SPAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 22, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//PVAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 26, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		break;
	case Beckhoff_index:
		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw1);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw2);
		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_pars);
		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//EigosLaik
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);


		//SPAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//PVAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 10, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}

	return 0;
}

int Instance_platform_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";
	wstring Object = L"";
	wstring Obj_reference = L"";
	wstring Base_addres = L"";
	wstring Tmp_string = L"";
	long Addres = 0;

	int index_object2 = 0;

	if (objects.data[index_object].Object_link != L"")
		index_object2 = Object_find_obj_link(index_object, false);

	if (index_object2 >= 0)
	{
		index_object2 = index_object2; // pritet kuo skirias kai zinai DK
	}


	Instance_scada_grid_add_line(grid_row_index, grid);
	Object = objects.data[index_object].CPU;
	if (Object.empty() != true)
		Object.append(L"_");
	else
		Object = L"";

	cell_text = Object;
	cell_text.append(objects.data[index_object].KKS);
	Instance_scada_grid_write_cell(grid_row_index, 0, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, objects.data[index_object].KKS, grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, objects.data[index_object].operatyv, grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, objects.data[index_object].Object_text, grid);


	cell_text = Object;
	cell_text.append(L"PLC");

	Obj_reference = cell_text;
	cell_text = L"sg.";
	cell_text.append(Obj_reference);
	Obj_reference.append(L".");
	Obj_reference.append(cell_text);

	switch (parameters.CPU)
	{
	case Siemens_index:
		Platform_get_addr_siemens_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//SPAdress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 22, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//PVAdress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 26, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		break;
	case Beckhoff_index:
		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw1);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw2);
		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_pars);
		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		break;
	default:
		err_prog();
		return -1;
		break;
	}

	return 0;
}

int Instance_platform_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";
	wstring Object = L"";
	wstring Obj_reference = L"";
	wstring Base_addres = L"";
	wstring Tmp_string = L"";
	long Addres = 0;

	int index_object2 = 0;

	if (objects.data[index_object].Object_link != L"")
		index_object2 = Object_find_obj_link(index_object, true);

	if (index_object2 >= 0)
	{
		index_object2 = index_object2; // pritet kuo skirias kai zinai DK
	}

	Instance_scada_grid_add_line(grid_row_index, grid);
	Object = objects.data[index_object].CPU;
	if (Object.empty() != true)
		Object.append(L"_");
	else
		Object = L"";

	cell_text = Object;
	cell_text.append(objects.data[index_object].KKS);
	Instance_scada_grid_write_cell(grid_row_index, 0, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, objects.data[index_object].KKS, grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, objects.data[index_object].operatyv, grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, objects.data[index_object].Object_text, grid);


	cell_text = Object;
	cell_text.append(L"PLC");

	Obj_reference = cell_text;
	cell_text = L"sg.";
	cell_text.append(Obj_reference);
	Obj_reference.append(L".");
	Obj_reference.append(cell_text);

	Instance_scada_grid_write_cell(grid_row_index, 21, L"HC", grid);

	switch (parameters.CPU)
	{
	case Siemens_index:
		Platform_get_addr_siemens_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);

		//regStatus
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		//regCMD
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		//Kp
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 8, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//Ti
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 12, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//Td
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 16, 0));
		Instance_scada_grid_write_cell(grid_row_index, 11, cell_text, grid);

		//Y
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//Ymax
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 28, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//Ymin
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 32, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//RegSP
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 72, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);

		//RegSPmin
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 44, 0));
		Instance_scada_grid_write_cell(grid_row_index, 16, cell_text, grid);

		//RegSPmax
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 40, 0));
		Instance_scada_grid_write_cell(grid_row_index, 17, cell_text, grid);

		//RegSPext
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 80, 0));
		Instance_scada_grid_write_cell(grid_row_index, 18, cell_text, grid);

		//analogas
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 76, 0));
		Instance_scada_grid_write_cell(grid_row_index, 19, cell_text, grid);

		//DeadB
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 24, 0));
		Instance_scada_grid_write_cell(grid_row_index, 20, cell_text, grid);

		//Hyst
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 68, 0));
		Instance_scada_grid_write_cell(grid_row_index, 21, cell_text, grid);

		break;
	case Beckhoff_index:
		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw1);

		//regStatus
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_pars);
		//regCMD
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		//Kp
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 8, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//Ti
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 12, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//Td
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 16, 0));
		Instance_scada_grid_write_cell(grid_row_index, 11, cell_text, grid);

		//Y
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//Ymax
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 28, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//Ymin
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 32, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//RegSP
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 72, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);

		//RegSPmin
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 44, 0));
		Instance_scada_grid_write_cell(grid_row_index, 16, cell_text, grid);

		//RegSPmax
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 40, 0));
		Instance_scada_grid_write_cell(grid_row_index, 17, cell_text, grid);

		//RegSPext
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 80, 0));
		Instance_scada_grid_write_cell(grid_row_index, 18, cell_text, grid);

		//analogas
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 76, 0));
		Instance_scada_grid_write_cell(grid_row_index, 19, cell_text, grid);

		//DeadB
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 24, 0));
		Instance_scada_grid_write_cell(grid_row_index, 20, cell_text, grid);

		//Hyst
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 68, 0));
		Instance_scada_grid_write_cell(grid_row_index, 21, cell_text, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}

	return 0;
}


int Instance_platform_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";
	wstring Object = L"";
	wstring Obj_reference = L"";
	wstring Base_addres = L"";
	wstring Tmp_string = L"";
	long Addres = 0;

	Instance_scada_grid_add_line(grid_row_index, grid);
	Object = objects.data[index_object].CPU;
	if (Object.empty() != true)
		Object.append(L"_");
	else
		Object = L"";

	cell_text = Object;
	cell_text.append(objects.data[index_object].KKS);
	Instance_scada_grid_write_cell(grid_row_index, 0, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, objects.data[index_object].KKS, grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, objects.data[index_object].operatyv, grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, objects.data[index_object].Object_text, grid);
	

	cell_text = Object;
	cell_text.append(L"PLC");

	Obj_reference = cell_text;
	cell_text = L"sg.";
	cell_text.append(Obj_reference);
	Obj_reference.append(L".");
	Obj_reference.append(cell_text);
	
	Instance_scada_grid_write_cell(grid_row_index, 21, L"HC", grid);

	switch (parameters.CPU)
	{
	case Siemens_index:
		Platform_get_addr_siemens_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//EigosLaik
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 8, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//ReverseDelay
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 10, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//Cfg.DelayReverseSCADApv
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 14, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//Cfg.DelayReverseSCADAsp
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 13, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//GreitRevTime
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 18, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);

		break;
	case Beckhoff_index:		
		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw1);

		//StatusAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 7, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw2);
		//Status2Adress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_pars);
		//CMDAdress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);

		//EigosLaik
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 2, 0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//ReverseDelay
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//Cfg.DelayReverseSCADApv
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 8, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//Cfg.DelayReverseSCADAsp
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 10, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//GreitRevTime
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 16, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}

	return 0;
}

int Instance_platform_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	wstring cell_text = L"";
	wstring Object = L"";
	wstring Obj_reference = L"";
	wstring Base_addres = L"";
	wstring Tmp_string = L"";
	long Addres = 0;

	Instance_scada_grid_add_line(grid_row_index, grid);
	Object = objects.data[index_object].CPU;
	if (Object.empty() != true)
		Object.append(L"_");
	else
		Object = L"";

	cell_text = Object;
	cell_text.append(objects.data[index_object].KKS);
	Instance_scada_grid_write_cell(grid_row_index, 0, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 1, objects.data[index_object].KKS, grid);
	Instance_scada_grid_write_cell(grid_row_index, 2, objects.data[index_object].operatyv, grid);
	Instance_scada_grid_write_cell(grid_row_index, 3, objects.data[index_object].Object_text, grid);
	cell_text = Object;
	cell_text.append(L"PLC");
	Instance_scada_grid_write_cell(grid_row_index, 8, cell_text, grid);

	Obj_reference = cell_text;
	cell_text = L"sg.";
	cell_text.append(Obj_reference);
	Obj_reference.append(L".");
	Obj_reference.append(cell_text);

	Instance_scada_grid_write_cell(grid_row_index, 9, cell_text, grid);
	Instance_scada_grid_write_cell(grid_row_index, 21, L"F1", grid);
	Instance_scada_grid_write_cell(grid_row_index, 22, L"1", grid);
	Instance_scada_grid_write_cell(grid_row_index, 23, L"1", grid);
	Instance_scada_grid_write_cell(grid_row_index, 25, L"0", grid);
	Instance_scada_grid_write_cell(grid_row_index, 26, L"100", grid);

	switch (parameters.CPU)
	{
	case Siemens_index:		
		Platform_get_addr_siemens_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);

		//PV Reference
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 0,0));
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		//AlarmByteAddress (Status)
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 8, 0));
		Instance_scada_grid_write_cell(grid_row_index, 11, cell_text, grid);

		//CfgByteAddress (CMD)
		cell_text = Base_addres;
		cell_text.append(L"Word");
		cell_text.append(int_to_wstring(Addres + 10, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//RangeMinAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 12, 0));
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//RangeMaxAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 16, 0));
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//HystAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 24, 0));
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);

		//LoLoLimitAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 28, 0));
		Instance_scada_grid_write_cell(grid_row_index, 16, cell_text, grid);

		//LoLimitAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 32, 0));
		Instance_scada_grid_write_cell(grid_row_index, 17, cell_text, grid);

		//HiLimitAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 34, 0));
		Instance_scada_grid_write_cell(grid_row_index, 18, cell_text, grid);

		//HiHiLimitAddress
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 38, 0));
		Instance_scada_grid_write_cell(grid_row_index, 19, cell_text, grid);

		//Dampher
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 20, 0));
		Instance_scada_grid_write_cell(grid_row_index, 20, cell_text, grid);

		//PV.IO
		cell_text = Base_addres;
		cell_text.append(L"Real");
		cell_text.append(int_to_wstring(Addres + 4, 0));
		Instance_scada_grid_write_cell(grid_row_index, 27, cell_text, grid);

		break;
	case Beckhoff_index:
		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_val);
		
		//PV Reference
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 10, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_sw1);
		//AlarmByteAddress (Status)
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 11, cell_text, grid);

		Platform_get_addr_beckhoff_data(Addres, Base_addres, Obj_reference, objects.data[index_object].Adress_pars);
		//CfgByteAddress (CMD)
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		Instance_scada_grid_write_cell(grid_row_index, 12, cell_text, grid);

		//RangeMinAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 4, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 13, cell_text, grid);

		//RangeMaxAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 8, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 14, cell_text, grid);

		//HystAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 16, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 15, cell_text, grid);

		//LoLoLimitAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 20, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 16, cell_text, grid);

		//LoLimitAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 24, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 17, cell_text, grid);

		//HiLimitAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 28, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 18, cell_text, grid);

		//HiHiLimitAddress
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 32, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 19, cell_text, grid);

		//Dampher
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 12, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 20, cell_text, grid);

		//PV.IO
		cell_text = Base_addres;
		cell_text.append(int_to_wstring(Addres + 0, 0));
		cell_text.append(L" F");
		Instance_scada_grid_write_cell(grid_row_index, 27, cell_text, grid);
		break;

	default:
		err_prog();
		return -1;
		break;
	}

	return 0;
}
