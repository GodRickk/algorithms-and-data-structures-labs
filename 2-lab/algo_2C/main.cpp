#include <iostream>

using namespace std;

const int NUMBERMAX = 100000;
long long int g_count(0);

void Merge(long int arr[], long int begin, long int end,long long int *count) {
    long int i = begin;
    long int k = 0;
    long int mid = begin + (end - begin) / 2;
    long int j = mid + 1;
    long int auxmas[NUMBERMAX];
    //int length = end - begin + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            auxmas[k] = arr[i];
            i++;
        }
        else {
            auxmas[k] = arr[j];
            j++;
            *count = *count + mid + 1 - i;
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

void MergeSort(long int *arr, long int left, long int right,long long int *count) {
    int temp;
    //int length = right - left + 1;
    if (left < right) {
        if (right - left == 1) {
            if (arr[right] < arr[left]) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                *count = *count + 1;
            }
        }
        else {
            MergeSort(arr, left, left + (right - left) / 2, count);
            MergeSort(arr, left + (right - left) / 2 + 1, right, count);
            Merge(arr, left, right, count);
        }
    }
}

int main() {
    //freopen("inversions.in", "r", stdin);
    //freopen("inversions.out", "w", stdout);
    long int n;
    long int a[NUMBERMAX];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MergeSort(a, 0, n - 1, &g_count);

    //for (int i = 0; i < n; i++) {
    //    cout << a[i] << " ";
    //}
    cout << g_count;
    return 0;
}