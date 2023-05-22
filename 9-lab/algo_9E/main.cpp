#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    vector<int> graph[100001];
    int vert_in[100001] = { }; //100001
    int vert_out[100001] = { }; //100001
    vector<int> order;
    int n, m;
    int start;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int v_1, v_2;
        cin >> v_1 >> v_2;
        vert_out[v_1]++;
        vert_in[v_2]++;
        graph[v_1].push_back(v_2);
    }

    bool flag_in, flag_out;
    int count_in = 0;
    flag_in = false;
    flag_out = false;

    for (int i = 1; i <= n; i++) {
        if (vert_in[i] == 0) {
            start = i;
            if (flag_in) {
                cout << "NO";
                return 0;
            }
            flag_in = true;
        }
        if (vert_out[i] == 0) {
            if (flag_out) {
                cout << "NO";
                return 0;
            }
            flag_out = true;
        }
        count_in = 0;
        for (int j = 0; j < graph[i].size(); j++) {
            int neg_v = graph[i][j];
            if (vert_in[neg_v] == 1) {
                count_in++;
            }
        }
        if (count_in > 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}