#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long const intMax = INT64_MAX;


void DijkstraSet (int n, vector <vector <pair <int, int>>> &graph, vector<long long> &minDist, set <pair <long long, int>> &s) {
    while (!s.empty()) {
        int vert = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i < graph[vert].size(); i++) {
            int nextVert = graph[vert][i].first;
            int length = graph[vert][i].second;
            if (minDist[nextVert] > minDist[vert] + length) {
                s.erase(make_pair(minDist[nextVert], nextVert));
                minDist[nextVert] = minDist[vert] + length;
                s.insert(make_pair(minDist[nextVert], nextVert));
            }
        }
    }
}


int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);*/
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> graph;
    graph.resize(n + 1);
    vector<long long> minDist (n + 1, intMax);
    vector <bool> used (n + 1, false);
    set <pair <long long, int>> s;

    // в i - ой ячейке хранится список смежности состоящий из пар чисел: первое - вершина, куда ведет ребро из вершины i, а второе его вес
    for (int i = 0; i < m; i++) {
        int v1, v2, edgeWeight;
        cin >> v1 >> v2 >> edgeWeight;
        graph[v1].push_back(make_pair(v2, edgeWeight));
        graph[v2].push_back(make_pair(v1, edgeWeight));
    }

    /*for (int i = 1; i <= n; i++) {
        cout << "\n";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].second << ' ';
        }
    }
    cout << '\n';*/

    minDist[1] = 0;
    s.insert(make_pair(minDist[1], 1));
    DijkstraSet(n, graph, minDist, s);

    for (int i = 1; i <= n; i++) {
        cout << minDist[i] << ' ';
    }
    return 0;
}