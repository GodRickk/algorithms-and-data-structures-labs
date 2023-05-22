#include <iostream>

using namespace std;
const int N = 70000;

int main() {
    //freopen("kth.in", "r", stdin);
    //freopen("kth.out", "w", stdout);
    int n;
    cin >> n;
    int a[N];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = a[i / 2];
        a[i / 2] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}