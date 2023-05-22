#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    //freopen("sortland.in", "r", stdin);
    //freopen("sortland.out", "w", stdout);
    cin >> n;
    vector <float> m(n);
    vector <float> aux_mas(n);
    for (int i = 0; i < n; i += 1 ) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i += 1) {
        aux_mas[i] = m[i]; }

    for (int j = 0; j < n; j += 1) {
        int number_min = j;
        for (int i = j; i < n; i += 1) {
            if (aux_mas[i] < aux_mas[number_min]) {
                number_min = i;
            }
        }
        float t;
        t = aux_mas[j];
        aux_mas[j] = aux_mas[number_min];
        aux_mas[number_min] = t;
    }

    float money_poor = aux_mas[0], money_middle = aux_mas[n / 2], money_rich = aux_mas[n - 1];
    int index_money_poor = 0, index_money_middle = 0, index_money_rich = 0;

    for (int i = 0; i < n; i += 1) {
        if (money_poor == m[i]) {
            index_money_poor = i + 1;
        }
        if (money_middle == m[i]) {
            index_money_middle = i + 1;
        }
        if (money_rich == m[i]) {
            index_money_rich = i + 1;
        }
    }
    cout << index_money_poor << " " << index_money_middle << " " << index_money_rich;
    return 0;
}