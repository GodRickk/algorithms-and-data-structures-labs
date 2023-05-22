#include <iostream>
#include <string>

using namespace std;

struct Oursrings {
    string str;
};

void CountingSort(string *a, int n, int k) {
    int c[26];
    string b[1000]; // Отсортированный
    char helpsymbol = 'a';

    for (int number = 0; number < 26; number++) {
        c[number] = 0;
    }
    //
    int num;
    char t;
    for (int i = 0; i < n; i++) {
        t = a[i][k];
        num = (int)t;
        c[num - 97] = c[num - 97] + 1;
    }
    int carry = 0;
    int tmp;
    for (int i = 0; i < 26; i++) {
        tmp = c[i];
        c[i] = carry;
        carry = carry + tmp;
    }
    for (int i = 0; i < n; i++) {
        num = (int)a[i][k] - 97;
        b[c[num]] = a[i];
        c[num] = c[num] + 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}


int main() {
    //freopen("radixsort.in", "r", stdin);
    //freopen("radixsort.out", "w", stdout);
    int n, m, k;
    string a[1000]; // Неотсортированный массив
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // RadixSort
    // От последнего элемента (m-1)
    // k фаз (до (m-1)-k)
    for(int i = m-1; i > m-1-k; i--) {
        CountingSort(a, n, i);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }

    /*for (int i = 0; i < 26; i++) {
        cout << (char)(i + 97) << ": " <<c[i] << "\n";
    }*/

    return 0;
}