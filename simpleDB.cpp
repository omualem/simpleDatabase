#include <iostream>
#include "mainFuncs.h"
#include "setOp.h"
#include "print.h"

int id = 1;

int main()
{
    int choose = -1;
    int rowCounter = 1;
    int columnsCounter = 1;
    string** Table = setup_table(rowCounter, columnsCounter);

    opening_message();

    while (true)
    {
        cout << "Please enter the action: ";
        cin >> choose;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choose) {
        case 1:
            print_table(Table, rowCounter, columnsCounter);
            break;
        case 2:
            Table = add_culomn_func(Table, rowCounter, columnsCounter);
            columnsCounter++;
            break;
        case 3:
            Table = insert_data_func(Table, rowCounter, columnsCounter);
            rowCounter++;
            break;
        case 4:
            update_data(Table, rowCounter, columnsCounter);
            break;
        case 5:
            Table = remove_column_func(Table, rowCounter, &columnsCounter);
            break;
        case 6:
            Table = remove_row_func(Table, &rowCounter, columnsCounter);
            break;
        case 7:
            print_table_to_cvs_file(Table, rowCounter, columnsCounter);
            break;
        case 8:
            opening_message();
            break;
        case 9:
            realese_allocated_memory(Table, rowCounter);
            exit(0);
            break;
        default:
            cout << "Your input is not valid, please enter only valid input" << '\n';
            break;
        }
        cout << '\n';
    }
}
