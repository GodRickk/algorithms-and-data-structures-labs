#include <iostream>
using namespace std;

long n = 0;
long a[100000000];
long b[100000000];


void siftDown(int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest;
    if (l <= n && a[l] < a[i]) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if (r <= n && a[r] < a[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(a[i], a[smallest]);
        swap(b[i], b[smallest]);
        siftDown(smallest);
    }
}

void siftUp(int i) {
    if (i != 1){
        if (a[i] < a[i / 2]){
            swap(a[i], a[i / 2]);
            swap(b[i], b[i / 2]);
            siftUp(i / 2);
        }
    }
}


int main() {
    //freopen("priorityqueue.in ", "r", stdin);
    //freopen("priorityqueue.out", "w", stdout);

    string command;
    int i = 0;
    while (cin >> command) {
        i++;
        if (command.length() == 0)
            break;
        if (command == "push") {
            long x;
            cin >> x;
            n++;
            a[n] = x;
            b[n] = i;
            siftUp(n);

        } else if (command == "extract-min") {

            if (n == 0) {
                cout << "*\n";
            } else {
                cout << a[1] << "\n";
                swap(a[1], a[n]);
                swap(b[1], b[n]);
                n--;
                siftDown(1);

            }

        } else if (command == "decrease-key") {
            long x, y, num;
            cin >> x >> y;
            for (int i = 1; i < n + 1; i++) {
                if (b[i] == x) {
                    num = i;
                    break;
                }
            }
            a[num] = y;
            if (num != 1 && a[num] < a[num  / 2])
                siftUp(num);
            else
                siftDown(num);

        } else {
            break;
        }
    }
    return 0;
}