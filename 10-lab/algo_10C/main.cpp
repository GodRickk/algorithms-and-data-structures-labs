#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
using namespace std;


void makeSet (int vert, vector<int> &parent) {
    parent[vert] = vert;
}


int find (int vert, vector<int> &parent) {
    if (parent[vert] == vert) {
        return vert;
    }
    return parent[vert] = find(parent[vert], parent);
}


void unite (int vert1, int vert2, vector<int> &parent) {
    vert1 = find(vert1, parent);
    vert2 = find(vert2, parent);

    if (rand() & 1) {
        swap(vert1, vert2);
    }
    if (vert1 != vert2) {
        parent[vert1] = vert2;
    }
}


void MSTKruskul (int &m, vector<pair <unsigned long long, pair <int, int>>> &graph, vector<int> &parents, unsigned long long &sumWeight) {
    for (int i = 0; i < m; i++) {
        int vert1, vert2, weight;
        weight = graph[i].first;
        vert1 = graph[i].second.first;
        vert2 = graph[i].second.second;

        if (find(vert1, parents) != find(vert2, parents)) {
            sumWeight += weight;
            unite(vert1, vert2, parents);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair <unsigned long long, pair <int, int>>> graph; // 1 - вес ребра; 2.1 - первая вершина 2.2 вторая вершина
    vector<int> parents;
    parents.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int vert1, vert2, weight;
        cin >> vert1 >> vert2 >> weight;
        graph.push_back(make_pair(weight, make_pair(vert1, vert2)));
    }

    sort(graph.begin(), graph.end());

    /*for (int i = 0; i < m; i++) {
        cout << "Weight: " << graph[i].first << " First vertex: " << graph[i].second.first << " Second vertex: " << graph[i].second.second << '\n';
    }*/

    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }
    unsigned long long sumWeight = 0;

    MSTKruskul(m, graph, parents, sumWeight);

    cout << sumWeight;
    return 0;
}