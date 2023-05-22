#include <iostream>
#include <vector>
using namespace std;


string res;


void dfs (int &vert, vector<int> *graph, vector<int> &color_mas, int cur_cl) {
    color_mas[vert] = cur_cl;
    for (int i = 0; i < graph[vert].size(); i++) {
        int next_vert = graph[vert][i];
        if (color_mas[next_vert] == 0) {
            dfs(next_vert, graph, color_mas, -cur_cl);
        }
        else if (color_mas[next_vert] == cur_cl) {
            res = "NO";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> graph[100001];
    vector<int> color_mas (n + 1, 0); // 0 - вершина не посещена 1 - белая -1 - черная

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
        graph[eg_2].push_back(eg_1);
    }

    /*for (int i = 1; i <= n; i++) {
            cout << '\n';
            cout << "vertex: " << i <<  " connected with: ";
            for(int j = 0; j < graph[i].size(); j++) {
                cout << graph[i][j] << ' ';
            }
        }
        cout << endl;*/

    int first_color = 1;
    for (int i = 1; i <= n; i++) {
        if (color_mas[i] == 0) {
            dfs(i, graph, color_mas, first_color);
        }
    }

    if (res == "NO") {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}