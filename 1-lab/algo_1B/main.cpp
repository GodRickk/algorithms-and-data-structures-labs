#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    //freopen("smallsort.in", "r", stdin); // smallsortin.txt работает
    //freopen("smallsort.out", "w", stdout);      // smallsortout.txt работает
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i += 1 ) {
        cin >> a[i];
    }

    for (int j = 0; j < n; j += 1) {
        int number_min = j;
        for (int i = j; i < n; i += 1) {
            if (a[i] < a[number_min]) {
                number_min = i;
            }
        }
        int t;
        t = a[j];
        a[j] = a[number_min];
        a[number_min] = t;
    }
    for (int i = 0; i < n; i += 1) {
        cout << a[i] << " ";
    }
}