#pragma once
#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdio.h>
#include <stdlib.h>

#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>
#include <locale>

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#include <vector>
#include <CommCtrl.h>
#include "Strings.h"

#define Result_Undefined	0
#define Result_Exit			1
#define Result_Yes			2
#define Result_Yes_all		3
#define Result_No			4
#define Result_No_all		5




#define unstable_release 1

#define AI_type		L"AI"
#define Vlv_type	L"VLV"
#define HC_type		L"HC"
#define FC_type		L"FC"
#define PID_type	L"PID"
#define Mot_type	L"MOT"

#define default_DI_size 16
#define default_AI_size 8
#define default_DO_size 16
#define default_AO_size 8

#define Filter_Count 20

using namespace std;
using namespace System;


struct KKS_str
{
	wstring Full;
	wstring Part1;
	wstring Part2;
};

struct test_str
{
	wstring test_KKS;
	struct KKS_str KKS;

	wstring IO_text;
	wstring Object_text;
	wstring text_to_copy;
};

enum Languge_index {
	LT_index = 0,
	EN_index = 1,
	LV_index = 2,
	RU_index = 3,
};

enum Module_index {
	DI_index = 1,
	DO_index = 2,
	AI_index = 3,
	AO_index = 4,
};

enum Grid_index {
	Design_grid_index = 0,
	Signals_grid_index = 1,
	Objects_grid_index = 2,
};

enum CPU_index {
	Beckhoff_index = 0,
	Siemens_index = 1,
	Schneider_index = 2,
	ABB_800xA_index = 3,
};

enum SCADA_index {
	System_platform = 0,
	WinCC = 1,
};

enum Variable_index {
	fb_index = 0,
	w1_index = 1,
	w2_index = 2,
	cmd_index = 3,
	val_index = 4,
	pars_index =5,
};

struct project_data_column // -1 data is not writen from excel
{
	int Number = -1;
	int KKS = -1;
	int Section = -1;
	int Range_min = -1;
	int Range_max = -1;
	int Units = -1;
	int False_text = -1;
	int True_text = -1;
	int Revision = -1;
	int Cable = -1;
	int Cabinet = -1;
	int Module_name = -1;
	int Pin = -1;
	int Channel = -1;
	int IO_text = -1;
	int Page = -1;
	int Changed = -1;
	int CPU = -1;
};

struct parameters_str
{
	int width = 640;
	int height = 480;
	int debug = 0;
	int clr_logs_on_start = 0;
	int excel_row_nr_with_name = 2;
	int CPU = Beckhoff_index;
	int Language = LT_index;
	int SCADA = System_platform;
	int KKS_del1 = 0;
	int KKS_del2 = 0;
	int KKS_underscore = 1;
	int KKS_delete_from_underscore = 1;
	int auto_column_with = 1;
	int indirect = 1;
	int try_import_if_corupt = 0;
	int paste_sel_match = 1;
	int adresing_from_1 = 1;
	int search_function_in_IO_text = 0;
	project_data_column column_in_import;
	wstring ABB_800xA_app_name = L"VK";
	wstring separator_function = L":";
	wstring separator_detailed = L";";
	int Delete_if_no_module = 1;
	int Compare_by_IO = 1;
};
struct project_data_str
{
	wstring number;			
	wstring CPU;
	wstring KKS;
	wstring Section;	
	wstring Range_min;
	wstring Range_max;
	wstring Units;
	wstring False_text;
	wstring True_text;
	wstring Revision;
	wstring Cable;
	wstring Cabinet;		
	wstring Module_name;	
	wstring Pin;			
	wstring Channel;		
	wstring IO_text;		
	wstring Page;			
	wstring Changed;	
};


#define design_column_number		0
#define design_column_CPU			1
#define design_column_KKS			2
#define design_column_Section		3
#define design_column_Range_min		4
#define design_column_Range_max		5
#define design_column_Units			6
#define design_column_False_text	7
#define design_column_True_text		8
#define design_column_Revision		9
#define design_column_Cable			10
#define design_column_Cabinet		11
#define design_column_Module_name	12
#define design_column_Pin			13
#define design_column_Channel		14
#define design_column_IO_text		15
#define design_column_Page			16
#define design_column_Changed		17


struct project_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums =17;
	const vector<wstring> column_name =	{
		L"Nr.",						//collumn 0
		L"CPU",						//collumn 1
		L"KKS",						//collumn 2	
		L"Sekcija",					//collumn 3	
		L"Range Min",				//collumn 4	
		L"Range Max",				//collumn 5	
		L"Units",					//collumn 6	
		L"False text",				//collumn 7	
		L"True text",				//collumn 8	
		L"Revision",				//collumn 9	
		L"Cable",					//collumn 10	
		L"Spinta",					//collumn 11	
		L"Modulis",					//collumn 12
		L"Pinas",					//collumn 13
		L"Kanalas",					//collumn 14
		L"IO tekstas",				//collumn 15	
		L"Projekto reference",		//collumn 16	
		L"Changed",					//collumn 17	
	};
	vector <project_data_str> data;
};
/* missing in siglal str
struct project_data_str
{	wstring Section;
	wstring Range_min;
	wstring Range_max;
	wstring Units;
	wstring False_text;
	wstring True_text;
	wstring Revision;
	wstring Cable;
};
*/

#define signal_column_number		0
#define signal_column_CPU			1
#define signal_column_KKS			2
#define signal_column_Section		3
#define signal_column_Range_min		4
#define signal_column_Range_max		5
#define signal_column_Units			6
#define signal_column_False_text	7
#define signal_column_True_text		8
#define signal_column_Revision		9
#define signal_column_Cable			10
#define signal_column_Cabinet		11
#define signal_column_Module_name	12
#define signal_column_Pin			13
#define signal_column_Channel		14
#define signal_column_IO_text		15
#define signal_column_Page			16
#define signal_column_Changed		17
struct Signal_data_str
{
	wstring number;					//collumn 0				
	wstring CPU;					//collumn 1
	wstring Cabinet;				//collumn 2	
	wstring operatyv;				//collumn 3	
	KKS_str KKS;					//collumn 4		KKS.Full
									//collumn 5		KKS.Part1
									//collumn 6		KKS.Part2
	wstring Used;					//collumn 7
	wstring Object_type;			//collumn 8
	wstring Object_text;			//collumn 9
	wstring Extendet_object_text;	//collumn 10
	wstring Function_text;			//collumn 11
	wstring Function;				//collumn 12
	wstring IO_text;				//collumn 13	
	wstring Module_name;			//collumn 14
	wstring Module_type;			//collumn 15
	wstring Channel;				//collumn 16	
	wstring Pin;					//collumn 17
	wstring Tag;					//collumn 18
	wstring Page;					//collumn 19
};
struct signal_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums = 19;
	const vector<wstring> column_name = {
		L"Nr.",
		L"CPU",
		L"Spinta",
		L"Operatyv",
		L"KKS",
		L"KKS1",
		L"KKS2",
		L"Used",
		L"Type",
		L"Objektas",
		L"objekto patikslinimas",
		L"Funkcinis tekstas",
		L"Funkcija",
		L"IO tekstas",
		L"Modulis",
		L"Type",
		L"Kanalas",
		L"Pinas",
		L"Tag",
		L"Projekto reference",
	};
	vector <Signal_data_str> data;
};

struct learning_str
{
	vector<wstring> Valve_name;					//collumn 0
	vector<wstring> Motor_name;					//collumn 1
	vector<wstring> Analog_name;				//collumn 2
	vector<wstring> Cilinder_name;				//collumn 3

	vector<wstring> Function_txt1;				//collumn 5
	vector<wstring> Function_txt1_meaning;		//collumn 6

	vector<wstring> Function_txt2_part1;		//collumn 8
	vector<wstring> Function_txt2_part2;		//collumn 9
	vector<wstring> Function_txt2_meaning;		//collumn 10
};

struct object_data_str
{
	wstring number;					//collumn 0
	wstring CPU;					//collumn 1
	wstring operatyv;				//collumn 2	
	wstring KKS;					//collumn 3	
	wstring Object_type;			//collumn 4
	wstring Object_text;			//collumn 5
	wstring Adress_val;				//collumn 6
	wstring Adress_sw1;				//collumn 7
	wstring Adress_sw2;				//collumn 8
	wstring Adress_cmd;				//collumn 9
	wstring Adress_pars;			//collumn 10
};

struct object_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums = 10;
	const vector<wstring> column_name = { 
		L"Nr.",
		L"CPU",
		L"Operatyv",
		L"KKS",
		L"Type",
		L"Objektas",
		L"Val",
		L"SW1",
		L"SW2",
		L"CMD",
		L"Pars",
	};
	vector <object_data_str> data;	
};


struct addres_1par_str
{
	int area;				// >0 DB[nr],  0 M, -1 MW, -2 QX, -3 QW;  -4 IX;  -5 IW; -99 ignore adressing
	int start_adr;
	int offset;
};

struct addres_pars_str
{
	addres_1par_str w1;
	addres_1par_str w2;
	addres_1par_str cmd;
	addres_1par_str val;
	addres_1par_str pars;
};

struct addres_pars_CPU_str
{
	addres_pars_str vlv;
	addres_pars_str hc;
	addres_pars_str mot;
	addres_pars_str ai;
	addres_pars_str fc;
	addres_pars_str pid;
};



struct addres_str
	// >0 DB[nr],  0 MQ, -1 M, -2 QX, -3 QW;  -4 IX;  -5 IW; -99 ignore adressing

{								//	DB,start, ofs
	addres_pars_CPU_str Beckhoff = {//w1			w2				cmd				val				pars
						/*vlv*/		-3,2000,2,		-3,2100,2,		0,0,0,			0,0,0,			-3,2200,20,
						/*hc*/		-3,3000,2,		-3,3100,2,		0,0,0,			0,0,0,			-3,3200,20,
						/*mot*/		-3,4000,2,		-3,4100,2,		0,0,0,			0,0,0,			-3,4200,20,
						/*ai*/		-3,5000,2,		0,0,0,			0,0,0,			-3,5100,4,		-3,5300,60,
						/*fc*/		0,0,0,			0,0,0,			0,0,0,			0,0,0,			-3,8000,20,
						/*pid*/		-3,9500,2,		0,0,0,			0,0,0,			0,0,0,			-3,10000,100 };

								//	DB,start, ofs
	addres_pars_CPU_str Siemens =  {//w1			w2				cmd				val				pars
						/*vlv*/		 0,0,0,			0,0,0,			0,0,0,			30,0,40,		0,0,0,
						/*hc*/		 0,0,0,			0,0,0,			0,0,0,			31,0,40,		0,0,0,
						/*mot*/		 0,0,0,			0,0,0,			0,0,0,			32,0,40,		0,0,0,
						/*ai*/		 0,0,0,			0,0,0,			0,0,0,			33,0,80,		0,0,0,
						/*fc*/		 0,0,0,			0,0,0,			0,0,0,			34,0,60,		0,0,0,
						/*pid*/		 0,0,0,			0,0,0,			0,0,0,			35,0,120,		0,0,0 };

								//	DB,start, ofs
	addres_pars_CPU_str ABB_800xA = {//w1			w2				cmd				val				pars
						/*vlv*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0,
						/*hc*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0,
						/*mot*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0,
						/*ai*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0,
						/*fc*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0,
						/*pid*/		0,0,0,			0,0,0,			0,0,0,			-99,0,1,		0,0,0 };

								//	DB,start, ofs								
	addres_pars_CPU_str Schneider = {//w1			w2				cmd				val				pars
						/*vlv*/		-3,2000,2,		-3,2100,2,		0,0,0,			0,0,0,			-3,2200,20,
						/*hc*/		-3,3000,2,		-3,3100,2,		0,0,0,			0,0,0,			-3,3200,20,
						/*mot*/		-3,4000,2,		-3,4100,2,		0,0,0,			0,0,0,			-3,4200,20,
						/*ai*/		-3,5000,2,		0,0,0,			0,0,0,			-3,5100,4,		-3,5300,60,
						/*fc*/		0,0,0,			0,0,0,			0,0,0,			0,0,0,			-3,8000,20,
						/*pid*/		-3,9500,2,		0,0,0,			0,0,0,			0,0,0,			-3,10000,100 };
};

struct filter_str
{
	wstring Filter_text[Filter_Count] = { L"" };
};

extern struct test_str test;
extern struct parameters_str parameters;
extern struct project_str project;
extern struct signal_str signals;
extern struct object_str objects;
extern struct learning_str learn;
extern struct addres_str adres;
extern int IO_form_result;
extern struct filter_str design_filter;
extern struct filter_str signal_filter;
extern struct filter_str object_filter;


extern int lang;

extern char err_txt[255];
extern char info_txt[255];

int GetNumberOfDigits(int i);
String^ string_to_system_string(string text);
String^ wstring_to_system_string(wstring text);
wstring system_string_to_wstring(System::String^ text);
string system_string_to_string(System::String^ text);

string wstring_to_string(wstring text);
wstring string_to_wstring(const std::string &s);

wstring int_to_wstring(int number, int nr_of_digits);

void err_write(char *tekstas);
void err_write_show(char *tekstas);
void info_write(char *tekstas);

int cfg_puts(char *tekstas, struct parameters_str *pars);
int cfg_reads(struct parameters_str *pars);

string button_press_name_write(String^ buttonName);
int Display_no_function(System::String^ buttonName);

void Show_progress(wstring text, int max);
void Hide_progress();
void set_progress_value(int value);

void reset_logs();
int show_confirm_window(LPCWSTR tekstas); // IDYES; IDNO; IDCANCEL

#endif