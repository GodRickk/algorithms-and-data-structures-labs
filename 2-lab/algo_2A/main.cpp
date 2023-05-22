#include <iostream>

using namespace std;

const int NUMBERMAX = 300000;

void Merge(int arr[], int begin, int end) {
    int i = begin;
    int k = 0;
    int mid = begin + (end - begin) / 2;
    int j = mid + 1;
    int auxmas[NUMBERMAX];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            auxmas[k] = arr[i];
            i++;
        }
        else {
            auxmas[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        auxmas[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end) {
        auxmas[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++) {
        arr[begin + i] = auxmas[i];
    }
}

void MergeSort(int *arr, int left, int right) {
    int temp;
    if (left < right) {
        if (right - left == 1) {
            if (arr[right] < arr[left]) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }

        else {
            MergeSort(arr, left, left + (right - left) / 2);
            MergeSort(arr, left + (right - left) / 2 + 1, right);
            Merge(arr, left, right);
        }
    }
}


int main() {
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    int n;
    int a[NUMBERMAX];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}