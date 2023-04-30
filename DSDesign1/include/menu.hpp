#pragma once

#include "head.h"

static void menu() {

    srand(time(0));
    int opt;
    vector<int> last_data;
    while (true) {
        cout << "1: generate random number\n2: sort random number\n3: print last data\n4: save last data\n5: quit"
             << endl;
        cin >> opt;
        switch (opt) {
            case 1: {
                cout << "Input the length of the data." << endl;
                int length;
                cin >> length;
                vector<int> random_data(length);
                for (int i = 0; i < length; i++) random_data[i] = rand() % 0x7f7f7f7f;
                last_data = random_data;
                cout << "Generate completed." << endl;
                break;
            }
            case 2: {
                cout << "The data you want to sort 0.last data 1.from file" << endl;
                cin >> opt;
                if (opt) IOTools<int>::I(last_data);
                int move_count = 0;
                SortTools<int>::menu(last_data, move_count);
                cout << "Sort completed, move count " << move_count << "." << endl;
                break;
            }
            case 3:
                IOTools<int>::output(last_data);
                break;
            case 4:
                IOTools<int>::O(last_data);
                break;
            case 5:
                return;
        }

    }
}