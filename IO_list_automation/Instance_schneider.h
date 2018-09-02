#pragma once

#ifndef _INSTANCE_SCHNEIDER_H_
#define _INSTANCE_SCHNEIDER_H_


int Instance_Schneider_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Schneider_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Schneider_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Schneider_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Schneider_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);

#endif