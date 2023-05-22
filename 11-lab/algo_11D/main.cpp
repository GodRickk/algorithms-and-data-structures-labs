#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//long long intMax = INT64_MAX;
const long long intMax = 2 * 1e18;
//const long long intMax = 100000000000000000000;


struct Edge {
    int vert_1;
    int vert_2;
    long long weight;
};



void BellmanFord (int n, int countEdges, vector <long long> &minDist, vector<Edge> &listOfedges) {
    for (int i = 1; i <= n-1 ; i++) { //n-1
        for (int j = 0; j < countEdges; j++) {
            if (minDist[listOfedges[j].vert_1] < intMax) {
                if (minDist[listOfedges[j].vert_2] > (minDist[listOfedges[j].vert_1] + listOfedges[j].weight)) {
                    minDist[listOfedges[j].vert_2] = max(-intMax, minDist[listOfedges[j].vert_1] + listOfedges[j].weight);
                }
            }
        }
    }
}


void dfs (int vert, vector<Edge> &listOfedges, vector<bool> &used) {
    used[vert] = true;
    for (int i = 0; i < listOfedges.size(); i++) {
        if (listOfedges[i].vert_1 == vert && !used[listOfedges[i].vert_2]) {
            dfs(listOfedges[i].vert_2, listOfedges, used);
        }
    }
}


int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);*/

    int n, m, s;
    //vector<vector <Node>> graph;
    vector <Edge> listOfedges;
    cin >> n >> m >> s;

    vector<bool> used (n + 1, false);
    //graph.resize(n + 1);
    vector<long long> minDist (n + 1, intMax);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        long long weight;
        cin >> v1 >> v2 >> weight;
        Edge anotherEdge;
        anotherEdge.vert_1 = v1;
        anotherEdge.vert_2 = v2;
        anotherEdge.weight = weight;
        listOfedges.push_back(anotherEdge);
    }

    /*for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        Node vert;
        cin >> v1 >> v2 >> weight;
        vert.to = v2;
        vert.weight = weight;
        graph[v1].push_back(vert);
    }*/

    minDist[s] = 0;
    BellmanFord(n, listOfedges.size(), minDist, listOfedges);

    for (int j = 0; j < m; j++) {
        if (minDist[listOfedges[j].vert_1] < intMax) {
            if (minDist[listOfedges[j].vert_2] > minDist[listOfedges[j].vert_1] + listOfedges[j].weight) {
                if (!used[listOfedges[j].vert_2]) {
                    dfs(listOfedges[j].vert_2, listOfedges, used);
                }
            }
        }
    }




    //BelmanFord(n, minDist, graph, used);

    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next_vert = graph[i][j].to;
            long long dist = graph[i][j].weight;
            if ((minDist[i] < intMax) && (minDist[next_vert] > minDist[i] + dist) && (!used[next_vert])) { //&& (!used[next_vert])
                dfs(next_vert, graph, used);
            }
        }
    }*/


    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            cout << '-';
        }
        else if (minDist[i] == intMax) {
            cout << '*';
        }
        else {
            cout << minDist[i];
        }
        if (i != n) {
            cout << '\n';
        }
    }
    return 0;
}