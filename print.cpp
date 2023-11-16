#include "setOp.h"
#include "print.h"

void print_table(string** Table, int rowCounter, int columnsCounter) {

    int sumOfChars = 0;
    int* maxCharPerColumnArr = get_max_char_per_column(Table, rowCounter, columnsCounter);

    for (int i = 0; i < rowCounter; i++) {
        for (int j = 0; j < columnsCounter; j++) {
            cout << Table[i][j];
            if (Table[i][j].size() < maxCharPerColumnArr[j]) {
                int diff = (int)maxCharPerColumnArr[j] - (int)Table[i][j].size();
                while (diff != 0) {
                    cout << ' ';
                    sumOfChars = (i == 0) ? sumOfChars += 1 : sumOfChars;
                    diff--;
                }
            }
            cout << " |";
            sumOfChars = (i == 0) ? sumOfChars += 2 + (int)Table[i][j].size() : sumOfChars;
        }
        int minusCount = 0;
        cout << '\n';
        while (minusCount != sumOfChars)
        {
            cout << "-";
            minusCount++;
        }
        cout << endl;
    }

    delete[] maxCharPerColumnArr;
}
void print_columns_names(string** Table, int columnsCounter) {

    int sumOfChars = 0;

    for (int j = 0; j < columnsCounter; j++) {
        cout << Table[0][j] << " |";
        sumOfChars += (int)Table[0][j].size() + 2;
    }
    int minusCount = 0;
    cout << '\n';
    while (minusCount != sumOfChars)
    {
        cout << "-";
        minusCount++;
    }
}

