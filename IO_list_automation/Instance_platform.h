#pragma once
#ifndef _INSTANCE_PLATFORM_H_
#define _INSTANCE_PLATFORM_H_

int Init_platform_vlv(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_platform_mot(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_platform_pid(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_platform_hc(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_platform_ai(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);


int Instance_platform_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_platform_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_platform_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_platform_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_platform_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);

#endif