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
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    string command;
    int n, top, number, count;
    count = -1;
    top = -1;
    cin >> n;
    int *s = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "-") {
            cout << s[count];
            if(i != n - 1) {
                cout << "\n";
            }
            Pop(s, count);
            count--;
        }
        else {
            count++;
            cin >> number;
            Push(s, count, number);
        }
    }
    delete[] s;
    return 0;
}