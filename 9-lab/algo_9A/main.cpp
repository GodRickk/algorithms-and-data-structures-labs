#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs (int &vert, vector<int> *graph, vector<int> &color, int &mark, vector<int> &res) {
    //vector<int> a;
    if (color[vert] == 2) {
        return false;
    }
    color[vert] = 1;
    for (int i = 0; i < graph[vert].size(); ++i) {
        int next_vert = graph[vert][i];
        if (color[next_vert] == 0) {
            if (dfs(next_vert, graph, color, mark, res)) {
                return true;
            }
        }
        else if (color[next_vert] == 1) {
            mark = next_vert;
            return true;
        }
    }
    color[vert] = 2;
    res.push_back(vert);
    //a = res;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> graph[100001]; //100001
    //vector<bool> used (n + 1);
    vector<int> res;
    vector<int> color (n + 1,0); // 0 - белый; 1 - серый; 2 - черный
    //vector<bool> color (n + 1, false); // 0 - белый; 1 - серый; 2 - черный
    int mark = -1;
    //vector<int> *graph = new vector<int> [n];

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
    }

    /*for (int i = 1; i <= n; i++) {
        cout << '\n';
        cout << "vertex: " << i <<  " connected with: ";
        for(int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << ' ';
        }
    }
    cout << endl;*/

    /*for (int i = 1; i <= n; i++) {
        if (check_cycle(i, mark, graph, color)) {
            break;
        }
    }*/

    for (int i = 1; i <= n; i++) {
        if (dfs(i, graph, color, mark, res)) { // bool
            break;
        }
    }

    if (mark == -1) {
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }
    }
    else {
        cout << -1;
    }


    /*for (int i = 1; i <= n; i++) {
        if (dfs_vsit(n, i, graph, used, res, color)) { // bool
            break;
        }
    }
 
    if (mark == -1) {
        //cout << "Without cycle " << mark << endl;
        for (int i = 1; i <= n; i++) {
            dfs_vsit(n, i, graph, used, res, color);
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
    }
    else {
        cout << -1;
    }*/
    return 0;
}