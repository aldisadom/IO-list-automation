#pragma once
#ifndef _INSTANCE_BECKHOFF_H_
#define _INSTANCE_BECKHOFF_H_

int Instance_Beckhoff_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Beckhoff_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Beckhoff_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Beckhoff_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Beckhoff_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);


#endif