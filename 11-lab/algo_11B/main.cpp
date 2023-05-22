#include <iostream>
#include <vector>
using namespace std;

long long const intMax = INT64_MAX - 1000000000;

struct Edge {
    int vert_1;
    int vert_2;
    int weight;
};


/*void BellmanFord (int &n, int &countEdges, int &start, vector<long long> &minDist, vector<Edge> &listOfedges) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = 0; j < countEdges; j++) {
            if (minDist[listOfedges[j].vert_2] > minDist[listOfedges[j].vert_1] + listOfedges[j].weight) {
                minDist[listOfedges[j].vert_2] = minDist[listOfedges[j].vert_1] + listOfedges[j].weight;
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}*/




void BellmanFord (int n, int countEdges, int start, vector <long long> &minDist, vector<Edge> &listOfedges) {
    for (int i = 1; i <= n -1; i++) {
        for (int j = 0; j < countEdges; j++) {
            if (minDist[listOfedges[j].vert_2] > minDist[listOfedges[j].vert_1] + listOfedges[j].weight) {
                minDist[listOfedges[j].vert_2] = minDist[listOfedges[j].vert_1] + listOfedges[j].weight;
            }
        }
    }
}



int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);*/

    int n, m;
    cin >> n >> m;
    //vector<long> minDist (n + 1, intMax);
    //vector< vector<long>> minDist;
    //minDist.resize(n + 1, vector<long> (n + 1));

    vector<Edge> listOfedges;

    /*int countEdges = 0;
    for (int i = 1; i <= n; i++) {
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


    for (int i = 0; i < m; i++) {
        int v1, v2, wegh;
        Edge anotherEdge;
        cin >> v1 >> v2 >> wegh;
        anotherEdge.vert_1 = v1;
        anotherEdge.vert_2 = v2;
        anotherEdge.weight = wegh;
        listOfedges.push_back(anotherEdge);
    }



    /*for (int j = 0; j < m; j++) {
        cout << listOfedges[j].vert_1 << ' ' << listOfedges[j].vert_2 << ' ' << listOfedges[j].weight << ' ' << '\n';
    }*/


    vector<long long> minDist_const (n + 1, intMax);

    for (int i = 1; i <= n; i++) {
        vector<long long> minDist (n + 1);
        for (int j = 1; j <= n; j++) {
            minDist[j] = minDist_const[j];
        }
        minDist[i] = 0;
        BellmanFord(n, m, i, minDist, listOfedges);
        for (int j = 1; j <= n; j++) {
            cout << minDist[j] << ' ';
        }
        if (i != n){
            cout << '\n';
        }
    }

    return 0;
}