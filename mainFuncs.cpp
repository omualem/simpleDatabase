#include "mainFuncs.h"
#include "tableOp.h"

extern int id;

string** add_culomn_func(string** Table, int rowCounter, int columnsCounter) {

    string newColumnName = "";
    string** newTable = add_culomn_to_table(Table, rowCounter, columnsCounter);

    cout << "Enter new column name: ";
    cin.ignore();
    getline(cin, newColumnName);
    if (newColumnName == "")
        newTable[0][columnsCounter] = "*";
    else
        newTable[0][columnsCounter] = newColumnName;

    return newTable;
}
string** insert_data_func(string** Table, int rowCounter, int columnsCounter) {

    string data = "";
    string** newTable = add_row_to_table(Table, rowCounter, columnsCounter);

    newTable[rowCounter][0] = to_string(id);
    id++;

    cout << "Insert data to each column: " << '\n';
    for (int i = 1; i < columnsCounter; i++)
    {
        cin.ignore();
        cout << "Culomn - " << newTable[0][i] << " : ";
        getline(cin, data);
        newTable[rowCounter][i] = data;
        data.clear();
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    }

    return newTable;
}
string** remove_row_func(string** Table, int* rowCounterPointer, int columnsCounter) {

    string** newTable;
    string id = "";
    int idIndex = 0;
    int rowCounter = *rowCounterPointer;


    if (rowCounter == 1) {
        cout << "There are no rows in the table" << '\n';
        return Table;
    }

    cout << "Enter the id of the row you want to remove: ";
    cin >> id;
    for (int i = 1; i < rowCounter; i++) {
        if (Table[i][0] == id) {
            id = Table[i][0];
            idIndex = i;
        }
    }

    if (id == "") {
        cout << "ID not found" << '\n';
        return Table;
    }

    if (id == "0") {
        cout << "Culomn's row cannot be removed, please use 'remove column' action" << '\n';
        return Table;
    }

    if (idIndex != 0) {
        newTable = remove_row_from_table(Table, rowCounter, columnsCounter, idIndex);
        (*rowCounterPointer)--;
        return newTable;
    }
    else {
        cout << "Input cannot be analyzed, please try again" << '\n';
        return Table;
    }


}
string** remove_column_func(string** Table, int rowCounter, int* columnsCounterPointer) {

    string** newTable;
    string columnName = "";
    int columnIndex = 0;
    int columnsCounter = *columnsCounterPointer;


    if (columnsCounter == 1) {
        cout << "There are no columns in the table" << '\n';
        return Table;
    }

    cout << "Enter the name of the column you want to remove: ";
    cin >> columnName;
    for (int i = 1; i < columnsCounter; i++) {
        if (Table[0][i] == columnName) {
            columnName = Table[0][i];
            columnIndex = i;
            break;
        }
    }

    if (columnName == "") {
        cout << "Column not found" << '\n';
        return Table;
    }

    if (columnName == "0" || columnName == "ID") {
        cout << "'ID' column cannot be removed" << '\n';
        return Table;
    }

    if (columnIndex != 0) {
        newTable = remove_column_from_table(Table, rowCounter, columnsCounter, columnIndex);
        (*columnsCounterPointer)--;
        return newTable;
    }
    else {
        cout << "Input cannot be analyzed, please try again" << '\n';
        return Table;
    }


}
void update_data(string** Table, int rowCounter, int columnsCounter) {
    int idIndex = -1, columnIndex = -1;
    string id = "", columnName = "", newData = "";

    if (rowCounter > 1) {
        cout << "Enter the ID of the cell you want to change:";
        cin >> id;
        for (int i = 1; i < rowCounter; i++) {
            if (Table[i][0] == id) {
                id = Table[i][0];
                idIndex = i;
            }
        }

        if (idIndex == -1) {
            cout << "ID not found" << '\n';
            return;
        }

        cout << "Enter the name of the column you want to change: ";
        cin >> columnName;
        for (int i = 1; i < columnsCounter; i++) {
            if (Table[0][i] == columnName) {
                columnName = Table[0][i];
                columnIndex = i;
                break;
            }
        }

        if (columnIndex == -1) {
            cout << "Column not found" << '\n';
            return;
        }

        cout << "previus data at id: " << id << ", at column: " << columnName << " is: " << Table[idIndex][columnIndex] << '\n';
        cout << "Enter the new data: ";
        cin >> newData;
        Table[idIndex][columnIndex] = newData;
        cout << '\n' << "previus data at id: " << id << ", at column: " << columnName << " is: " << Table[idIndex][columnIndex] << '\n';
        return;

    }
    else
    {
        cout << "There is no data to change" << '\n';
        return;
    }
}
void opening_message() {
    cout << '\n';
    cout << "********************************************************************" << '\n';
    cout << "*                                                                  *" << '\n';
    cout << "*      Welcome to table database managment (DTM)                   *" << '\n';
    cout << "*                                                                  *" << '\n';
    cout << "*              Please select an action:                            *" << '\n';
    cout << "*                  1: Print table                                  *" << '\n';
    cout << "*                  2: Add a new column                             *" << '\n';
    cout << "*                  3: Add a new row                                *" << '\n';
    cout << "*                  4: Update specific data                         *" << '\n';
    cout << "*                  5: Remove a column                              *" << '\n';
    cout << "*                  6: Remove a row                                 *" << '\n';
    cout << "*                  7: Print table to CVS file (an Excel file)      *" << '\n';
    cout << "*                  8: Return to the opening  screen page           *" << '\n';
    cout << "*                  9: Exit the program                             *" << '\n';
    cout << "*                                                                  *" << '\n';
    cout << "********************************************************************" << '\n';
}
void print_table_to_cvs_file(string** Table, int rowCounter, int columnsCounter) {

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ofstream csvFile(filename + ".csv");

    if (!csvFile.is_open()) {
        cerr << "Failed to open the file: " << "Table" << endl;
        return;
    }

    for (int i = 0; i < rowCounter; i++) {
        for (int j = 0; j < columnsCounter; j++) {
            csvFile << Table[i][j];
            if (j < columnsCounter - 1) {
                csvFile << ",";
            }
        }
        csvFile << "\n";
    }

    csvFile.close();
}