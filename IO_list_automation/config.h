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


#define unstable_release 1

#define AI_type		L"AI"
#define Vlv_type	L"VLV"
#define HC_type		L"HC"
#define FC_type		L"FC"
#define PID_type	L"PID"
#define Mot_type	L"MOT"

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
	int auto_column_with = 1;
	int indirect = 1;
};
struct project_data_str
{
	wstring number;			//collumn 0, in excel no
	wstring Cabinet;		//collumn 1, in excel 1
	wstring Module;			//collumn 2, in excel 2
	wstring Pin;			//collumn 3, in excel 3
	wstring Channel;		//collumn 4, in excel 4
	wstring IO_text;		//collumn 5, in excel 5
	wstring Page;			//collumn 6, in excel 6
};

struct project_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums =6;
	const vector<wstring> column_name =	{
		L"Nr.",
		L"Spinta",
		L"Modulis",		
		L"Pinas",
		L"Kanalas",
		L"IO tekstas",		
		L"Projekto reference",
	};
	vector <project_data_str> data;
};

struct Signal_data_str
{
	wstring number;					//collumn 0
	wstring Cabinet;				//collumn 1	
	wstring operatyv;				//collumn 2	
	KKS_str KKS;					//collumn 3		KKS.Full
									//collumn 4		KKS.Part1
									//collumn 5		KKS.Part2
	wstring Used;					//collumn 6
	wstring Object_type;			//collumn 7
	wstring Object_text;			//collumn 8
	wstring Extendet_object_text;	//collumn 9
	wstring Function_text;			//collumn 10
	wstring Function;				//collumn 11
	wstring IO_text;				//collumn 12	
	wstring Module;					//collumn 13
	wstring Channel;				//collumn 14	
	wstring Pin;					//collumn 15			
	wstring Page;					//collumn 16
};
struct signal_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums = 16;
	const vector<wstring> column_name = {
		L"Nr.",
		L"Spinta",
		L"Operatyv",
		L"KKS",
		L"KKS1",
		L"KKS2",
		L"Used",
		L"Type",
		L"Objectas",
		L"objekto patikslinimas",
		L"Funkcinis tekstas",
		L"Funkcija",
		L"IO tekstas",
		L"Modulis",
		L"Kanalas",
		L"Pinas",
		L"Projekto reference",
	};
	vector <Signal_data_str> data;
};

struct learning_str
{
	bool done = false;
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
	wstring operatyv;				//collumn 1	
	wstring KKS;					//collumn 2	
	wstring Object_type;			//collumn 3
	wstring Object_text;			//collumn 4
	wstring Adress_val;				//collumn 5
	wstring Adress_sw1;				//collumn 6
	wstring Adress_sw2;				//collumn 7
	wstring Adress_cmd;				//collumn 8
	wstring Adress_pars;			//collumn 9
};

struct object_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums = 9;
	const vector<wstring> column_name = { 
		L"Nr.",
		L"Operatyv",
		L"KKS",
		L"Type",
		L"Objectas",
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

extern struct test_str test;
extern struct parameters_str parameters;
extern struct project_str project;
extern struct signal_str signals;
extern struct object_str objects;
extern struct learning_str learn;
extern struct addres_str adres;


extern int lang;

extern char err_txt[255];
extern char info_txt[255];

int GetNumberOfDigits(int i);
String^ string_to_system_string(string text);
String^ wstring_to_system_string(wstring text);
wstring system_string_to_wstring(System::String^ text);
string system_string_to_string(System::String^ text);

string wstring_to_string(wstring text);
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
int show_confirm_window(LPCWSTR tekstas);

#endif