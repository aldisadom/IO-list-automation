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

#include <vector>
#include <CommCtrl.h>

#define separator (L"☣")
#define unstable_release 1

using namespace std;
using namespace System;


struct parameters_str
{
	int width = 10;
	int height = 10;
	int debug = 0;
	int clr_logs_on_start = 0;
	int excel_row_nr_with_name = 2;
};

struct project_str
{
	int valid_entries;
	int number_collums;

	vector<wstring> column_name	;
	vector<wstring> number;
	vector<wstring> Cabinet		;				//collumn 2
	vector<wstring> Module		;				//collumn 3
	vector<wstring> Pin			;				//collumn 4
	vector<wstring> Channel		;				//collumn 5
	vector<wstring> IO_text;				//collumn 6
	vector<wstring> Page		;				//collumn 7
};

struct signal_str
{
	int valid_entries;
	vector<wstring> column_name;
	vector<wstring> number;
	vector<wstring> Cabinet;				
	vector<wstring> Module;				
	vector<wstring> Pin;				
	vector<wstring> Channel;				
	vector<wstring> IO_text;				
	vector<wstring> Page;
	vector<wstring> Object_text;
	vector<wstring> Extendet_object_text;
	vector<wstring> Function_text;
	vector<wstring> KKS;
	vector<wstring> KKS1;
	vector<wstring> KKS2;
	vector<int> Object_type;
};

struct object_str
{
	vector<wstring> column_name;
	int valid_entries;
	vector<int> number;
};

extern struct parameters_str parameters;
extern struct project_str project;
extern struct signal_str signals;
extern struct object_str objects;

extern bool progress_bar_100ms;

extern char err_txt[255];
extern char info_txt[255];

int GetNumberOfDigits(int i);
String^ wstring_to_system_string(wstring text);
wstring system_string_to_wstring(System::String^ text);
string system_string_to_string(System::String^ text);
wstring int_to_wstring(int number, int nr_of_digits);


void err_write_show(char *tekstas);
void info_write(char *tekstas);

int cfg_puts(char *tekstas, struct parameters_str *pars);
int cfg_reads(struct parameters_str *pars);

int Display_no_function(System::String^ buttonName);

void Show_progress(wstring text, int max);
void Hide_progress();
void set_progress_value(int value);

void reset_logs();
int show_confirm_window(LPCWSTR tekstas);

void Delete_list();
#endif


