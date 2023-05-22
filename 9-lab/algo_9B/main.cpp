#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int cycle_finish;
int cycle_start = -1;


bool dfs (int &vert, vector<int> *graph, vector<int> &color, vector<int> &parent) {
    color[vert] = 1;
    for (int i = 0; i < graph[vert].size(); ++i) {
        int next_vert = graph[vert][i];
        if (color[next_vert] == 0) {
            parent[next_vert] = vert;
            if (dfs(next_vert, graph, color,parent)) {
                return true;
            }
        }
        else if (color[next_vert] == 1) {
            cycle_finish = vert;
            cycle_start = next_vert;
            return true;
        }
    }
    color[vert] = 2;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> graph[100001];
    vector<int> color (n + 1, 0);
    vector<int> parent(n + 1);


    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
    }


    for (int i = 1; i <= n; i++) {
        if (dfs(i, graph, color, parent)) {
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "NO";
        return 0;
    }
    else {
        vector<int> our_cycle;
        our_cycle.push_back(cycle_start);
        for (int v = cycle_finish; v != cycle_start; v = parent[v]) {
            our_cycle.push_back (v);
        }
        reverse (our_cycle.begin(), our_cycle.end());
        cout << "YES" << '\n';
        for (int i = 0; i < our_cycle.size(); ++i)
            cout << our_cycle[i] << ' ';
    }
    return 0;
}