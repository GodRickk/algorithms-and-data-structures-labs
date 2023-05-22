#include <iostream>

using namespace std;


void MaxHeapify(int *a, int i, int n) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;
    int temp = 0;
    if (l <= n && a[l] > a[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if (r <= n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest, n);
    }
}

void BuildMaxHeap(int *a, int n) {
    int heapsize = n;
    for (int i = heapsize / 2; i >= 1; i--) {
        MaxHeapify(a, i, n);
    }
}

void HeapSort(int *a, int n) {
    BuildMaxHeap(a, n);
    int temp = 0;
    int size = n;
    for (int i = n; 0 < i; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        size = size - 1;
        MaxHeapify(a, 1, size);
    }
}


int main() {
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    int *a = new int[n + 1];

    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    HeapSort(a, n);

    for (int i = 1; i < n + 1; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}