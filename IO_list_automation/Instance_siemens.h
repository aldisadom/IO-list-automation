#pragma once
#ifndef _INSTANCE_SIEMENS_H_
#define _INSTANCE_SIEMENS_H_

int Instance_Siemens_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Siemens_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Siemens_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Siemens_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Siemens_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);


#endif