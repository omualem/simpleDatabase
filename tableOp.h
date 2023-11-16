#pragma once
#include <string>
#include <iostream>

using namespace std;

string** add_culomn_to_table(string** Table, int rowCounter, int columnsCounter);
string** add_row_to_table(string** Table, int rowCounter, int columnsCounter);
string** remove_row_from_table(string** Table, int rowCounter, int columnsCounter, int idIndex);
string** remove_column_from_table(string** Table, int rowCounter, int columnsCounter, int colIndex);