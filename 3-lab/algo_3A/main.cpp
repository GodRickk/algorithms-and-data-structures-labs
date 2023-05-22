#include <iostream>

using namespace std;


int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    cin >> n;
    int *a = new int [n + 1];
    //int a[100001];
    //for (int i = 1; i < 100001; i++) {
    //    a[i] = 2 * 1000000000;
    //}

    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    int flag = 1;

    for (int i = 1; i < n + 1; i++) {
        if (2 * i <= n) {
            if (a[i] > a[2 * i]) {
                flag = 0;
            }
        }
        if (2 * i + 1 <= n) {
            if (a[i] > a[2 * i + 1]) {
                flag = 0;
            }
        }
    }

    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }


    delete[] a;
    return 0;
}