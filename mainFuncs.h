#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#define NOMINMAX
#include <windows.h>

using namespace std;

string** add_culomn_func(string** Table, int rowCounter, int columnsCounter);
string** insert_data_func(string** Table, int rowCounter, int columnsCounter);
string** remove_row_func(string** Table, int* rowCounterPointer, int columnsCounter);
string** remove_column_func(string** Table, int rowCounter, int* columnsCounterPointer);
void update_data(string** Table, int rowCounter, int columnsCounter);
void opening_message();
void print_table_to_cvs_file(string** Table, int rowCounter, int columnsCounter);