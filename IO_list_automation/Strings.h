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

extern const wchar_t * conf_design_overwrite[];
extern const wchar_t * conf_signal_overwrite[];
extern const wchar_t * conf_learn_overwrite[];
extern const wchar_t * conf_objects_overwrite[];
extern const wchar_t * conf_objects_type_overwrite[];
#endif