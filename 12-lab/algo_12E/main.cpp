#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void dfs (int vert, vector<vector <int>> &dp, vector<vector <int>> &graph) {
    dp[vert][0] = 0;
    dp[vert][1] = 1;
    for (int i = 0; i < graph[vert].size(); i++) {
        dfs(graph[vert][i], dp, graph);
    }
    for (int i = 0; i < graph[vert].size(); i++) {
        dp[vert][1] += dp[graph[vert][i]][0];
        dp[vert][0] += max(dp[graph[vert][i]][0], dp[graph[vert][i]][1]);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> parents (n + 1);
    vector<vector <int>> graph (n + 1);
    // вектор в котором индекс - нормер вершины (корень поддерева), значение - максимальное количество вершин, которое можно получить из данного поддерева
    vector<vector <int>> dp (n + 1, vector<int> (2));

    int root;
    for (int i = 1; i <= n; i++) {
        int pr;
        cin >> pr;
        if (pr == 0) {
            root = i;
            continue;
        }
        graph[pr].push_back(i);   // связь родители -> дети
        //graph[i].push_back(pr); // связь дети -> родители
    }

    /*for (int i = 1; i <= n; i++) {
        cout  << '\n' << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << ' ';
        }
    }*/

    dfs(root, dp, graph);
    int res = max(dp[root][0], dp[root][1]);
    cout << '\n' << res;
    return 0;
}