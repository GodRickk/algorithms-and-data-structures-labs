#include <iostream>
using namespace std;

string chek(int *matrix[], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i && matrix[i][j] == 1) {
                return "NO";
            }
            else if (matrix[i][j] != matrix[j][i]) {
                return "NO";
            }
        }
    }
    return "YES";
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    int **matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [n];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    /*for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
    }*/

    cout << chek(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}