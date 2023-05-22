#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[30001];
vector<bool> used;
vector<int> dist;
queue<int> q;


void bfs () {
    while (!q.empty()) {
        int vert = q.front();
        q.pop();
        for (int i = 1; i <= graph[vert].size(); ++i) {
            int next_vert = graph[vert][i - 1];
            if (!used[next_vert]) {
                used[next_vert] = true;
                q.push(next_vert);
                dist[next_vert] = dist[vert] + 1;
            }
        }
    }
}


int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    used.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
        graph[eg_2].push_back(eg_1);
    }

    int start = 1;
    q.push(start); // 1
    used[start] = true;

    bfs();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}