#pragma once
#ifndef _DECLARE_H_
#define _DECLARE_H_

#include "config.h"

struct check_result_str
{
	int ai = 0;
	int vlv = 0;
	int hc = 0;
	int fc = 0;
	int pid = 0;
	int mot = 0;
};


struct adr_1test_str
{
	int area;
	int start_adr;
	int end_adress;
};

struct adr_test_str
{
	adr_1test_str w1 = { -99,-99,-99 };
	adr_1test_str w2 = { -99,-99,-99 };
	adr_1test_str cmd = { -99,-99,-99 };
	adr_1test_str val = { -99,-99,-99 };
	adr_1test_str pars = { -99,-99,-99 };
};

struct adr_cpu_test_str
{
	adr_test_str vlv;
	adr_test_str hc;
	adr_test_str mot;
	adr_test_str ai;
	adr_test_str fc;
	adr_test_str pid;
};

int Declare_adress_get_CPU_switch(addres_pars_CPU_str &CPU_adr);
int Declare_adress_put_CPU_switch(addres_pars_CPU_str &CPU_adr);

int Declare_addreses();
int Declare_adress_test(int AI_nr_max, int VLV_nr_max, int HC_nr_max, int FC_nr_max, int PID_nr_max, int MOT_nr_max, check_result_str &result_obj, adr_cpu_test_str &test_CPU_adr);

#endif