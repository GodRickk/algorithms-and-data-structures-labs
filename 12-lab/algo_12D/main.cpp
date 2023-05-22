#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void solve (vector<vector<int>> &d, int &n, int &m, queue<pair <int, int>> &q) {
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if (row - 1 >= 0 && col + 2 < m) {
            if (row - 1 == n - 1 && col + 2 == m - 1) {
                d[n - 1][m - 1] += 0;
            }
            else {
                d[row - 1][col + 2] += d[row][col];
                q.push(make_pair(row - 1, col + 2));
            };
        }
        if (row + 1 < n && col + 2 < m) {
            if (row + 1 == n - 1 && col + 2 == m - 1) {
                d[n - 1][m - 1] += 0;
            }
            else {
                d[row + 1][col + 2] += d[row][col];
                q.push(make_pair(row + 1, col + 2));
            }
        }
        if (row + 2 < n && col - 1 >= 0) {
            if (row + 2 == n - 1 && col - 1 == m - 1) {
                d[n - 1][m - 1] += 0;
            }
            else {
                d[row + 2][col - 1] += d[row][col];
                q.push(make_pair(row + 2, col - 1));
            }
        }
        if (row + 2 < n && col + 1 < m) {
            if (row + 2 == n - 1 && col + 1 == m - 1) {
                d[n - 1][m - 1] += 0;
            }
            else {
                d[row + 2][col + 1] += d[row][col];
                q.push(make_pair(row + 2, col + 1));
            }
        }
    }
}


int dfs (vector<vector<int>> &d, int &n, int &m, int row, int col) {
    if (d[row][col] != 0) {
        return d[row][col];
    }
    else {
        if (row - 2 >= 0 && col - 1 >= 0) {
            d[row][col] += dfs(d, n, m, row - 2, col - 1);
        }
        if (row - 1 >= 0 && col - 2 >= 0) {
            d[row][col] += dfs(d, n, m, row - 1, col - 2);
        }
        if (row - 2 >= 0 && col + 1 < m) {
            d[row][col] += dfs(d, n, m, row - 2, col + 1);
        }
        if (row + 1 < n && col - 2 >= 0) {
            d[row][col] += dfs(d, n, m, row + 1, col - 2);
        }
    }
    return d[row][col];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);


    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, 0));
    d[0][0] = 1;
    dfs(d, n, m, n - 1, m - 1);
    cout << d[n - 1][m - 1] << '\n';
    /*for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < m; j++) {
            cout << d[i][j] << ' ';
        }
    }*/
    return 0;
}