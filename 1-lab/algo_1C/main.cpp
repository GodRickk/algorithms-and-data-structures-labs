#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, h;
    //freopen("turtle.in", "r", stdin);
    //freopen("turtle.out", "w", stdout);
    cin >> h >> w;

    int **mas = new int* [h];
    for (int i = 0; i < h; i += 1) {
        mas[i] = new int[w];
    }

    int **aux_mas = new int* [h];
    for (int i = 0; i < h; i += 1) {
        aux_mas[i] = new int[w];
    }
    for (int i = 0; i < h; i += 1) {
        for (int j = 0; j < w; j += 1) {
            aux_mas[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i += 1) {
        for (int j = 0; j < w; j += 1) {
            cin >> mas[i][j];
        }
    }
    aux_mas[0][w - 1] = mas[0][w - 1];
    int t, down, left;
    for (int i = 0; i < h; i += 1) {
        for (int j = w - 1; j >= 0; j -= 1) {
            //aux_mas[i][j-1] = mas[i][j-1] + aux_mas[i][j];  left
            //aux_mas[i+1][j] = mas[i+1][j] + aux_mas[i][j]; down
            if (i+1 < h) {
                down = mas[i + 1][j] + aux_mas[i][j];
                if (down > aux_mas[i + 1][j]) {
                    aux_mas[i + 1][j] = down; // down - сумма нижней ячейки и ячейки
                }
            }
            if (j - 1 >= 0) {
                left = mas[i][j - 1] + aux_mas[i][j];
                if (left > aux_mas[i][j - 1]){
                    aux_mas[i][j - 1] = left;
                }
            }
        }
    }
    cout << aux_mas[h - 1][0];

    for (int i = 0; i < h; i += 1) {
        delete[] mas[i];
    }
    for (int i = 0; i < h; i += 1) {
        delete[] aux_mas[i];
    }
    delete[] aux_mas;
    delete[] mas;
    return 0;
}