#include <iostream>
#include <vector>
using namespace std;


int number_comp = 0;
vector<int> list[100001];
bool used[100001];
vector<int> comp;
int count_comps[100001];


void dfs(int vert) {
    count_comps[vert] = number_comp;
    used[vert] = true;
    comp.push_back(vert);
    for (int i = 0; i < list[vert].size(); ++i) {
        int next_vert = list[vert][i];
        if (!used[next_vert])
            dfs(next_vert);
    }
}


void comps(int &n) {
    for (int i = 1; i <= n; ++i) {
        used[i] = false;
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            number_comp++;
            comp.clear();
            dfs(i);
        }
}


int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    //vector<int> comp;
    //vector<int> g[101];
    //bool used[100000];

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        list[eg_1].push_back(eg_2);
        list[eg_2].push_back(eg_1);
    }

    /*for (int i = 1; i <= n; i++) {
        cout << '\n';
        cout << "vertex: " << i <<  " connected with: ";
        for(int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << ' ';
        }
    }
    cout << endl;*/
    //find_comps(n, *g, comp, used);


    comps(n);
    cout << number_comp << '\n';
    for (int i = 1; i <= n; i++) {
        cout << count_comps[i] << ' ';
    }

    return 0;
}