#pragma once
#ifndef _STRINGS_H_
#define _STRINGS_H_

#include "String_errors.h"
#include "String_info.h"
#include "String_progress.h"

#define separator (L"☣")

#define error_separator (" --- ")
#define info_separator (" - ")


extern const char * done_txt[];

extern const char * design_txt[];
extern const char * signals_txt[];
extern const char * objects_txt[];
extern const char * learning_txt[];

extern const char * ai_txt[];
extern const char * vlv_txt[];
extern const char * hc_txt[];
extern const char * fc_txt[];
extern const char * pid_txt[];
extern const char * mot_txt[];

extern const wchar_t * conf_design_overwrite[];
extern const wchar_t * conf_signal_overwrite[];
extern const wchar_t * conf_learn_overwrite[];
extern const wchar_t * conf_objects_overwrite[];
extern const wchar_t * conf_objects_type_overwrite[];
#endif