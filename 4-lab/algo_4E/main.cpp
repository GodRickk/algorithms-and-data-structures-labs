#include <iostream>

using namespace std;
int n, a[100000];

int BinsearchUp(int x) {
    int left = -1, right = n, mid;

    while (right - left > 1) {
        mid = (left + right) / 2;
        if (a[mid] <= x) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    if (a[left] != x) {
        return -1;
    }
    else {
        return left + 1;
    }
}

int BinsearchDown(int x) {
    int left = -1, right = n, mid;

    while (right - left > 1) {
        mid = (left + right) / 2;
        if (a[mid] < x) {
            left = mid;
        }
        else right = mid;
    }
    if (a[right] != x) {
        return -1;
    }
    else {
        return right + 1;
    }
}

int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int m, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << BinsearchDown(x) << " " << BinsearchUp(x) << "\n";
    }
    return 0;
}