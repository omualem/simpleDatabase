#include "setOp.h"

string** setup_table(int rowCounter, int columnsCounter) {

    string** Table = new string * [rowCounter];
    for (int i = 0; i < rowCounter; i++)
        Table[i] = new string[columnsCounter];

    Table[0][0] = "ID";

    return Table;
}
int* get_max_char_per_column(string** Table, int rowCounter, int columnsCounter) {

    int* maxCharPerColumnArr = (int*)malloc(columnsCounter * sizeof(int));

    for (int i = 0; i < columnsCounter; i++)
    {
        int max = 0;
        for (int j = 0; j < rowCounter; j++)
        {
            if (Table[j][i].size() >= max) {
                max = (int)Table[j][i].size();
                maxCharPerColumnArr[i] = max;
            }
        }
    }

    return maxCharPerColumnArr;
}
void realese_allocated_memory(string** Table, int rowCounter) {
    for (int i = 0; i < rowCounter; i++)
        delete[] Table[i];
    delete[] Table;
}