#include <iostream>
#include <vector>
using namespace std;

int count_comp = 0;
int help_mas[20001];

void dfs_first (int vert, vector<int> *graph, vector<int> &order, vector<bool> &used) {
    used[vert] = true;
    for (int i = 0; i < graph[vert].size(); i++) {
        int next_vert = graph[vert][i];
        if (!used[next_vert]) {
            dfs_first(next_vert, graph, order, used);
        }
    }
    order.push_back(vert);
}


void dfs_second (int vert, vector<int> *transpon, vector<int> &comp, vector<bool> &used) {
    used[vert] = true;
    comp.push_back(vert);
    help_mas[vert] = count_comp;
    for (int i = 0; i < transpon[vert].size(); i++) {
        int next_vert = transpon[vert][i];
        if (!used[next_vert]) {
            dfs_second(next_vert, transpon, comp, used);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> graph[20001];
    vector<int> transpon[20001];
    vector<int> order;
    vector<int> comp;
    vector<bool> used (n + 1, false);
    vector<int> res;
    //vector<int> color_mas (n + 1, 0); // 0 - вершина не посещена 1 - белая -1 - черная

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
        transpon[eg_2].push_back(eg_1);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs_first(i, graph, order, used);
        }
    }


    used.assign(n + 1, false);
    for (int i = 0; i < n; i++) {
        //cout << endl;
        int vert = order[n - 1 - i];
        if (!used[vert]) {
            count_comp++;
            dfs_second(vert, transpon, comp, used);
            /*for (int j = 0; j < comp.size(); j++) {
                //cout << comp[j] << ' ';
                //cout << count << ' ';
                //res.push_back(count);
            }*/
            comp.clear();
        }
    }

    cout << count_comp << '\n';
    for (int i = 1; i <= n; i++) {
        cout << help_mas[i] << ' ';
    }

    return 0;
}