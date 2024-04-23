#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void bruteForceOrdening(vector<int> &values) {
    for (int i = 0; i < values.size(); ++i)
        for (int j = 1 + i; j < values.size(); ++j)
            if (values[i] > values[j]) {
                int tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
}

void bubbleSort(vector<int> &value) {
    for (int i = value.size() - 1; i > 0; --i) {
        bool ordened = true;
        for (int j = 0; j < i; ++j) {
            if (value[j] > value[j + 1]) {
                int aux = value[j];
                value[j] = value[j + 1];
                value[j + 1] = aux;
                ordened = false;
            }
        }
        if (ordened)break;
    }
}

int main() {
    vector<int> values = {
            20, 40, 17, 5,
            22, 9, 10, 3,
            51, 30, 42, 33,
            19, 7, 27
    };

    auto start = chrono::high_resolution_clock::now();

    for (const int value: values)
        cout << value << " ";

    bubbleSort(values);

    cout << endl;

    for (const int value: values)
        cout << value << " ";

    cout << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;

    return 0;
}
