#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int const intMax = 1000000000;

struct Edge {
    int vert_1;
    int vert_2;
    int weight;
};


bool BellmanFord (int n, int countEdges, vector <int> &minDist, vector<Edge> &listOfedges, vector <int> &parents, vector <int> &path) {
    int flag;
    for (int i = 1; i <= n; i++) {
        flag = -1;
        for (int j = 0; j < countEdges; j++) {
            if (minDist[listOfedges[j].vert_2] > minDist[listOfedges[j].vert_1] + listOfedges[j].weight) {
                minDist[listOfedges[j].vert_2] = max(-intMax, minDist[listOfedges[j].vert_1] + listOfedges[j].weight);
                parents[listOfedges[j].vert_2] = listOfedges[j].vert_1;
                flag = listOfedges[j].vert_2;
            }
        }
    }
    if (flag < 0) {
        return false;
    }
    else {
        int vert = flag;
        for (int i = 1; i <= n; ++i) {
            vert = parents[vert];
        }
        for (int next_vert = vert;; next_vert = parents[next_vert]) {
            path.push_back(next_vert);
            if (next_vert == vert && path.size() > 1) {
                break;
            }
        }
        reverse(path.begin(), path.end());
        return true;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    int n;
    cin >> n;
    vector<Edge> listOfedges;
    int countEdges = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int edgeWeight;
            cin >> edgeWeight;
            Edge another_eg;
            if (edgeWeight == 1000000000) {
                continue;
            }
            else {
                another_eg.vert_1 = i;
                another_eg.vert_2 = j;
                another_eg.weight = edgeWeight;
                listOfedges.push_back(another_eg);
                countEdges++;
            }
        }
    }

    vector <int> minDist (n + 1, 0);
    vector <int> parents (n + 1, -1);
    vector <int> path;
    bool flag;
    minDist[1] = 0;

    flag = BellmanFord(n, listOfedges.size(), minDist, listOfedges, parents, path);

    if (!flag) {
        cout << "NO";
    }
    else {
        cout << "YES" << '\n';
        cout << path.size() << '\n';
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << ' ';
        }
    }
    return 0;
}