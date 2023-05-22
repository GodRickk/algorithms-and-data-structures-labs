#include <iostream>

using namespace std;

const long int NUMBERMAX = 30000000;//30000000
const int M = 10;

int Order(long int a[], long int n, long int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (right <= left + 1) {
            if (right == left + 1 && a[right] < a[left])
                swap (a[left], a[right]);
            return a[k];
        }

        int mid  = (left + right) / 2;
        swap (a[mid], a[left + 1]);
        if (a[left] > a[right])
            swap (a[left], a[right]);
        if (a[left + 1] > a[right])
            swap (a[left + 1], a[right]);
        if (a[left] > a[left + 1])
            swap (a[left], a[left + 1]);
        int pivot = a[left + 1];

        int i = left + 1;
        int j = right;

        while (i <= j) {
            while (a[++i] < pivot);
            while (a[--j] > pivot);
            if (i > j) break;
            swap(a[i], a[j]);
        }

        swap(a[j], a[left + 1]);

        if (j >= k) right = j - 1;
        if (i <= k) left = i;
    }
}


int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    long int n;
    long int k;
    long int a[NUMBERMAX];
    long int A, B, C, a1, a2;

    cin >> n >> k;
    cin >> A >> B >> C >> a1 >> a2;
    a[0] = a1;
    a[1] = a2;
    for (int i = 2; i < n; i++) {
        a[i] = A * a[i-2] + B * a[i-1] + C;
    }

//    QSort(a, 0, n - 1);

    cout << Order(a, n, k - 1);
    return 0;
}

/*void insertionSort(long a[], long int left, long int right) {
    int j;
    for(int i = left; i < right; i++) {
        j = i - 1;
        while (j >= 0 && a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            j--;
        }
    }
}


long int median(long int a, long int b, long int c) {
    long int auxmas[3] = {a, b, c};
    insertionSort(auxmas, 0, 3);
    return auxmas[1];
}


int partitional(long int a[], long int left, long int right) {
    int v = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (a[i] < v) {
            i++;
        }
        while (a[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(a[i++], a[j--]);
    }

    return j;
}


void QSort(long int a[], long int left, long int right) {
    long int q;
    if (right - left <= M) {
        insertionSort(a, left, right);
        return;
    }
    int med = median(a[left], a[(left + right) / 2], a[right]);
    swap(a[med], a[((left + right) / 2)]);
    q = partitional(a, left, right);
    QSort(a, left, q);
    QSort(a, q + 1, right);

}*/