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
};

struct object_str
{
	vector <int> collumn_with;
	int valid_entries;
	const int number_collums = 4;
	const vector<wstring> column_name = { 
		L"Nr.",
		L"Operatyv",
		L"KKS",
		L"Type",
		L"Objectas",
	};
	vector <object_data_str> data;	
};

extern struct test_str test;
extern struct parameters_str parameters;
extern struct project_str project;
extern struct signal_str signals;
extern struct object_str objects;
extern struct learning_str learn;

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