#include "tableOp.h"

string** add_culomn_to_table(string** Table, int rowCounter, int columnsCounter) {

    string** newTable = new string * [rowCounter];
    int i = 0;

    for (i = 0; i < rowCounter; i++)
        newTable[i] = new string[columnsCounter + 1];

    for (int i = 0; i < rowCounter; i++)
    {
        for (int j = 0; j < columnsCounter; j++)
            newTable[i][j] = Table[i][j];
    }

    for (int i = 0; i < rowCounter; i++)
        delete[] Table[i];

    delete[] Table;

    return newTable;
}
string** add_row_to_table(string** Table, int rowCounter, int columnsCounter) {

    string** newTable = new string * [rowCounter + 1];
    int i = 0;

    for (i = 0; i < rowCounter + 1; i++)
        newTable[i] = new string[columnsCounter];

    for (int i = 0; i < rowCounter; i++)
    {
        for (int j = 0; j < columnsCounter; j++)
            newTable[i][j] = Table[i][j];
    }

    for (int i = 0; i < rowCounter; i++) {
        delete[] Table[i];
    }
    delete[] Table;

    return newTable;
}
string** remove_row_from_table(string** Table, int rowCounter, int columnsCounter, int idIndex) {

    string** newTable = new string * [rowCounter - 1];
    int i = 0, newRow = 0;

    for (i = 0; i < rowCounter - 1; i++)
        newTable[i] = new string[columnsCounter];

    for (int i = 0; i < rowCounter; i++)
    {
        if (idIndex != i) {
            for (int j = 0; j < columnsCounter; j++)
                newTable[newRow][j] = Table[i][j];
            newRow++;
        }
    }

    for (int i = 0; i < rowCounter; i++)
        delete[] Table[i];

    delete[] Table;

    return newTable;
}
string** remove_column_from_table(string** Table, int rowCounter, int columnsCounter, int colIndex) {

    string** newTable = new string * [rowCounter];
    int i = 0, newCol = 0;

    for (i = 0; i < rowCounter; i++)
        newTable[i] = new string[columnsCounter - 1];

    for (int i = 0; i < rowCounter; i++)
    {
        newCol = 0;
        for (int j = 0; j < columnsCounter; j++) {
            if (colIndex != j) {
                newTable[i][newCol] = Table[i][j];
                newCol++;
            }
        }
    }

    for (int i = 0; i < rowCounter; i++)
        delete[] Table[i];

    delete[] Table;

    return newTable;
}