#include <iostream>
#include <vector>
using namespace std;


void game (int start, vector<int> *graph, vector<int> &color, vector<bool> &win_vert) {
    int cur_vert;
    bool win_flag;
    vector<int> order;
    order.push_back(start);

    while (!order.empty()) {
        cur_vert = order.back();
        if (color[cur_vert] == 0) {
            color[cur_vert] = 1;
            for (int i = 0; i < graph[cur_vert].size(); i++) {
                int next_vert = graph[cur_vert][i];
                if (color[next_vert] == 0) {
                    order.push_back(next_vert);
                }
            }
        }

        else if (color[cur_vert] == 1) {
            win_flag = false;
            for (int i = 0; i < graph[cur_vert].size(); i++) {
                int next_vert = graph[cur_vert][i];
                if (win_vert[next_vert] == false) {
                    win_flag = true;
                }
            }
            win_vert[cur_vert] = win_flag;
            color[cur_vert] = 2;
            order.pop_back();
        }

        else if (color[cur_vert] == 2) {
            order.pop_back();
        }
    }

    if (win_vert[start] == true) {
        cout << "First player wins";
    }
    else {
        cout << "Second player wins";
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m, start;
    cin >> n >> m >> start;
    vector<int> graph[100001];
    // 0 - белый (вершина не просмотрена) 1 - серая (кандидат на провекру соседей на выигрышную вершину) 2 - черная (вершина просмотрена)
    vector<int> color(n + 1, 0);
    vector<bool> win_vert (n + 1, false);

    for (int i = 0; i < m; i++) {
        int eg_1, eg_2;
        cin >> eg_1 >> eg_2;
        graph[eg_1].push_back(eg_2);
    }

    game(start, graph, color, win_vert);

    return 0;
}