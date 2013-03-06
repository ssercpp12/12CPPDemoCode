/* copyright (c) Jianhong Li. All rights reserved. */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 1001

struct Girl {
    string name;
    int value;
};

namespace py {
    void sort(Girl arr[], int N);
}

namespace afei {
    void sort(Girl arr[], int N);
}

void py::sort(Girl arr[], int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i].value > arr[j].value) {
                Girl tmp = arr[i];
                arr[i] = arr[j];
                arr[j]  = tmp;
            }
}

void afei::sort(Girl arr[], int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i].value < arr[j].value) {
                Girl tmp = arr[i];
                arr[i] = arr[j];
                arr[j]  = tmp;
            }
}

/*
 * this is the test framework
 */
int main() {
    int n;
    cin >> n;
    Girl arr[MAXN];
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].value;
    py::sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i].value << endl;
    afei::sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i].value << endl;
    return 0;
}
