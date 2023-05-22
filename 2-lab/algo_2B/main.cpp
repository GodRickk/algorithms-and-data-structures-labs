#include <iostream>

using namespace std;


struct CountryPeople {
    string Country;
    string Name;
};

CountryPeople result[100000];

void merge(CountryPeople a[], int left, int mid, int right) {

    int i = 0;
    int j = 0;

    while (left + i < mid && mid + j < right) {
        if (a[left + i].Country <= a[mid + j].Country) {
            result[i + j] = a[left + i];
            i++;
        }
        else {
            result[i + j] = a[mid + j];
            j++;
        }
    }

    while (left + i < mid) {
        result[i + j] = a[left + i];
        i++;
    }

    while (mid + j < right) {
        result[i + j] = a[mid + j];
        j++;
    }

    for (int k = 0; k < i + j; k++) {
        a[left + k] = result[k];
    }

}


int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}


void mergeSort(CountryPeople a[], int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n - i; j += 2 * i) {
            merge(a, j, j + i, min(j + 2 * i, n));
        }
    }
}



int main() {
    //freopen("race.in", "r", stdin);
    //freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    CountryPeople a[100000];

    for (int i = 0; i < n; i++) {
        cin >> a[i].Country >> a[i].Name;
    }
    mergeSort(a, n);

    string last;
    for (int i = 0; i < n; i++) {
        if (last != a[i].Country) {
            cout << "=== " << a[i].Country << " ===\n";
            last = a[i].Country;
        }
        cout << a[i].Name << "\n";
    }
    return 0;
}