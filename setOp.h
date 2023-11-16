#pragma once
#include <string>
#include <iostream>

using namespace std;

string** setup_table(int rowCounter, int columnsCounter);
int* get_max_char_per_column(string** Table, int rowCounter, int columnsCounter);
void realese_allocated_memory(string** Table, int rowCounter);