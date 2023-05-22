#include <iostream>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int **matrix = new int* [n]; // n
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [n];
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }


    for(int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        matrix[eg_1 - 1][eg_2 - 1] = 1;
    }

    /*cout << "Task matrix" << "\n";
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << "\n";
        }
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j != n - 1) {
                cout << " ";
            }
        }
    }*/


    //cout << "\n" << "All matrix" << "\n";
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << "\n";
        }
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j != n - 1) {
                cout << " ";
            }
        }
    }

    for(int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}