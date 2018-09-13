#pragma once
#ifndef _IO_DECLARE_H_
#define _IO_DECLARE_H_

int IO_generate_signal(wstring cabinet, wstring module, wstring channel, std::wstring &text);
int IO_generate_module(wstring cabinet, wstring module, std::wstring &text);

int IO_generate();

int IO_show();

void IO_show_modules(System::Windows::Forms::DataGridView^ grid);
#endif