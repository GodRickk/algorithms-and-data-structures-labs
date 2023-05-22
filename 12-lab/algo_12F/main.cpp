#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int vert, vector<vector <int>> &graph, vector<vector <int>> &dp, vector<int> &cost) {
    dp[vert][0] = 0;
    dp[vert][1] = cost[vert];
    for (int i = 0; i < graph[vert].size(); i++) {
        dfs(graph[vert][i], graph, dp, cost);
    }
    for (int i = 0; i < graph[vert].size(); i++) {
        dp[vert][1] += dp[graph[vert][i]][0];
        dp[vert][0] += max(dp[graph[vert][i]][0], dp[graph[vert][i]][1]);
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector <int>> graph (n + 1);
    // вектор в котором индекс - нормер вершины (корень поддерева), значение - максимальное количество вершин, которое можно получить из данного поддерева
    vector<vector <int>> dp (n + 1, vector<int> (2));
    vector<int> cost (n + 1);
    int root;
    for (int i = 1; i <= n; i++) {
        int pr, cur_cost;
        cin >> pr >> cur_cost;
        if (pr == 0) {
            cost[i] = cur_cost;
            root = i;
            continue;
        }
        graph[pr].push_back(i); // связь родители -> дети
        cost[i] = cur_cost;
    }

    /*for (int i = 1; i <= n; i++) {
        cout  << '\n' << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << ' ';
        }
        cout << cost[i];
    }*/

    dfs(root, graph, dp, cost);

    int res = max(dp[root][0], dp[root][1]);
    cout << res;


    return 0;
}