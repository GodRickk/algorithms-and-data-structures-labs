#include <iostream>
using namespace std;

bool Stack_Empty(int *arr, int arr_top) {
    if (arr_top == -1) {
        return true;
    }
    else return false;
}

void Push(int *arr, int arr_top, int x) {
    //arr_top = arr_top + 1;
    arr[arr_top] = x;
}

int Pop(int *arr, int arr_top) {
    /*int m = 0;
    if (Stack_Empty(arr, arr_top)) {
        m = -1;
    }
    else {
        //arr_top = arr_top - 1;
        return arr[arr_top];
    }*/
    return arr[arr_top];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    string command;
    int n, tail, number, head;
    head = 0;
    tail = -1;
    cin >> n;
    int *q = new int[n];
    for (int i = n; i > 0; i--) {
        cin >> command;
        if (command == "-") {
            //head++;
            cout << q[head];
            if(i != 1) {
                cout << "\n";
            }
            Pop(q, head);
            head++;
        }
        else {
            tail++;
            cin >> number;
            Push(q, tail, number);
        }
    }
    delete[] q;
    return 0;
}