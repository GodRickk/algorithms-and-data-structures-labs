#include <iostream>
#include <vector>
using namespace std;

long long const intMax = INT64_MAX;

void Dijkstra (int n, vector <vector <pair <int, int>>> &graph, vector<long long> &minDist, vector<bool> &used) {
    for (int i = 1; i <= n; ++i) {
        int vert = 0;
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && (vert == 0 || minDist[j] < minDist[vert])) {
                vert = j;
            }
        }
        used[vert] = true;
        for (int j = 0; j < graph[vert].size(); ++j) {
            int next_vert = graph[vert][j].first;
            int length = graph[vert][j].second;
            if (minDist[next_vert] > minDist[vert] + length) {
                if (minDist[vert] == intMax) {
                    minDist[next_vert] = length;
                }
                else {
                    minDist[next_vert] = minDist[vert] + length;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    // вывести кратчайшее растояние между start, final или вывести -1 если пути между ними не существует
    int n, start, final;
    cin >> n >> start >> final;
    // граф ориентированный, взвешенный

    vector <vector <pair <int, int>>> graph;
    graph.resize(n + 1);
    vector<long long> minDist (n + 1, intMax);
    vector <bool> used (n + 1, false);


    //vector<Edge> listOfedges;
    //vector<int> parents (n + 1);


    //int countEdges = 0;
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int edgeWeight;
            cin >> edgeWeight;
            Edge another_eg;
            if (edgeWeight == -1 || edgeWeight == 0) {
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
    }*/

    // в i - ой ячейке хранится список смежности состоящий из пар чисел: первое - вершина, куда ведет ребро из вершины i, а второе его вес
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int edgeWeight;
            cin >> edgeWeight;
            if (edgeWeight == -1 || edgeWeight == 0) {
                continue;
            }
            else {
                graph[i].push_back(make_pair(j, edgeWeight));
            }
        }
    }


    /*for (int i = 1; i <= n; i++) {
        cout << "\n";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].second << ' ';
        }
    }
    cout << '\n';*/

    minDist[start] = 0;
    Dijkstra(n, graph, minDist, used);
    //BellmanFord(n, countEdges, start, minDist, listOfedges);

    if (minDist[final] == intMax) {
        cout << -1;
    }
    else {
        cout << minDist[final];
    }
    return 0;
}