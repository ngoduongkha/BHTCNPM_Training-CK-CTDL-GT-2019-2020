#include <iostream>

using namespace std;

void down_heap(int* a, int n, int i) {
    while (i < n) {
        int con = 2 * i + 1;
        if (con >= n) break;
        if (con + 1 < n && a[con] < a[con + 1]) con++;
        if (a[con] > a[i]) {
            swap(a[con], a[i]);
            i = con;
        }
        else break;
    }
}

int main() {
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n / 2 - 1; i >= 0; i--) down_heap(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        down_heap(a, i, 0);
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}