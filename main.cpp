#include <iostream>
#include <vector>

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

int main() {
    vector<int> values = {
            20, 40, 17, 5,
            22, 9, 10, 3,
            51, 30, 42, 33,
            19, 7, 27
    };

    for (const int a: values)
        cout << a << " ";

    bruteForceOrdening(values);

    cout << endl;

    for (const int a: values)
        cout << a << " ";

    return 0;
}
