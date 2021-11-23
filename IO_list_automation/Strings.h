#pragma once
#ifndef _STRINGS_H_
#define _STRINGS_H_

#include "Config.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define separator (L"☣")
//#define separator (L"*")

#define error_separator (L" --- ")
#define info_separator (L" - ")

struct Strings_str
{
	wstring s[4] = { L"", L"",L"",L"", };
};

struct Strings_general_str
{
	Strings_str language;
	Strings_str done_txt;
	Strings_str cancel_txt;
	Strings_str design_txt;
	Strings_str signals_txt;
	Strings_str objects_txt;
	Strings_str ai_txt;
	Strings_str vlv_txt;
	Strings_str hc_txt;
	Strings_str fc_txt;
	Strings_str pid_txt;
	Strings_str mot_txt;
};

struct Strings_conf_str
{
	Strings_str design_overwrite;
	Strings_str signal_overwrite;
	Strings_str objects_overwrite;
	Strings_str objects_type_overwrite;
	Strings_str signal_TAG_overwrite;
};

struct Strings_info_str
{
	Strings_str button_press;
	Strings_str color_grid;
	Strings_str compare_project;
	Strings_str dump_declare;
	Strings_str dump_instance;
	Strings_str erase_data;
	Strings_str excel_read_data;
	Strings_str exit_aplication;
	Strings_str extract_data;
	Strings_str extract_from_grid;
	Strings_str find_function;
	Strings_str find_objects;
	Strings_str find_operatyv;
	Strings_str find_uniques;
	Strings_str generate_IO_adress;
	Strings_str generate_IO_tags;
	Strings_str get_adresses;
	Strings_str KKS_edit;
	Strings_str learning;
	Strings_str lenght;
	Strings_str load_data;
	Strings_str multi_CPU;
	Strings_str no_function;
	Strings_str overlap_adresses;
	Strings_str paste_data;
	Strings_str put_adresses;
	Strings_str put_to_grid;
	Strings_str save_data;
	Strings_str show_trend;
	Strings_str transfer_data;
};

struct Strings_progres_str
{
	Strings_str adress;
	Strings_str check_adress;
	Strings_str declare;
	Strings_str dump_data;
	Strings_str generate_IO;
	Strings_str generate_IO_adress;
	Strings_str grid_color;
	Strings_str grid_put;
	Strings_str grid_take;
	Strings_str learning_data;
	Strings_str lenght;
	Strings_str load;
	Strings_str multi_cpu;
	Strings_str operatyv;
	Strings_str overlap;
	Strings_str paste;
	Strings_str process_data;
	Strings_str read_data;
	Strings_str save;
	Strings_str search_diference;
	Strings_str transfer_data;
	Strings_str trend_polynom;
	Strings_str uniques_find;
	Strings_str uniques_object_type;
};
struct Strings_error_str
{
	Strings_str bad_link;
	Strings_str canceled_selection;
	Strings_str cant_open;
	Strings_str cfg_bad_parameter;
	Strings_str cfg_bad_value;
	Strings_str cfg_empty_parameter;
	Strings_str cfg_empty_value;
	Strings_str cfg_parameter_programing_error;
	Strings_str clickboard_no_data;
	Strings_str clickboard_no_match;
	Strings_str clickboard_overrange;
	Strings_str corrupted_file;
	Strings_str corrupted_file_continue;
	Strings_str excel_cant_open;
	Strings_str excel_no_sheet;
	Strings_str no_adress_object;
	Strings_str no_cfg_file;
	Strings_str no_data_edit;
	Strings_str no_data_save;
	Strings_str no_file_save;
	Strings_str no_function_for_this;
	Strings_str no_learn_file;
	Strings_str no_object_types_edit;
	Strings_str no_tag;
	Strings_str show_trend;
	Strings_str string;
	Strings_str test_fail;
	Strings_str unstable;
	Strings_str wrong_file;
	Strings_str wrong_object_type;
	Strings_str Create_memory_map_obj;
	Strings_str Create_memory_map_view;
	Strings_str Open_memory_map_view;
};

struct Strings_all_str
{
	Strings_general_str General;
	Strings_conf_str Confirm;
	Strings_progres_str Progress;
	Strings_error_str Error;
	Strings_info_str Info;
};

extern Strings_all_str str;
void init_strings();

#endif