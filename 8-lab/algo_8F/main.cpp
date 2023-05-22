#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Coords {
    int x, y;
    //char letter;
};


/*class Coords {
public:
    int x, y;
    bool operator != (const Coords &c) {
        if (this->x != c.x || this->y != c.y) {
            return false;
        }
        return true;
    };

};*/


/*vector<Coords> graph [10000][10000];
int dist [10000][10000];
bool used [10000][10000];*/

vector<Coords> graph [100][100];// 10000 10000
int dist [100][100]; // 10000 10000
bool used [100][100]; // 10000 10000
queue<Coords> q;
//vector<Coords> parents[10][10]; // 10000 10000
//vector<> pth





void bfs (vector<Coords> (&parents)[100][100]) {
    while (!q.empty()) {
        Coords vert = q.front();
        q.pop();
        for (int i = 0; i < graph[vert.y][vert.x].size(); i++) {
            Coords next_vert = graph[vert.y][vert.x][i];
            if (!used[next_vert.y][next_vert.x]) {
                used[next_vert.y][next_vert.x] = true;
                q.push(next_vert);
                dist[next_vert.y][next_vert.x] = dist[vert.y][vert.x] + 1;

                parents[next_vert.y][next_vert.x].push_back(vert);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    /*vector<Coords> graph [100][100];// 10000 10000
    int dist [100][100]; // 10000 10000
    bool used [100][100]; // 10000 10000
    queue<Coords> q;*/
    vector<Coords> parents[100][100];
    Coords start;
    start.x = 0;
    start.y = 0;
    Coords finish;
    finish.x = 0;
    finish.y = 0;
    int n, m;
    cin >> n >> m;

    char **matrix = new char* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new char [m];
    }

    //char matrix[5][5];

    // считывание символов игрового поля
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];

        }
    }

    // задание графа
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '#') {
                continue;
            }
            else {
                if (matrix[i][j] == 'S') {
                    start.x = j;
                    start.y = i;
                }
                if (matrix[i][j] == 'T') {
                    finish.x = j;
                    finish.y = i;
                }
                if (j + 1 != m) {
                    if (matrix[i][j + 1] != '#') { // != '#'
                        Coords node;
                        node.x = j + 1;
                        node.y = i;
                        graph[i][j].push_back(node);
                    }
                }
                if (i + 1 != n) {
                    if (matrix[i + 1][j] != '#') { // != '#'
                        Coords node;
                        node.x = j;
                        node.y = i + 1;
                        graph[i][j].push_back(node);
                    }
                }
                if (j - 1 != -1) {
                    if (matrix[i][j - 1] != '#') { // != '#'
                        Coords node;
                        node.x = j - 1;
                        node.y = i;
                        graph[i][j].push_back(node);
                    }
                }
                if (i - 1 != -1) {
                    if (matrix[i - 1][j] != '#') { // != '#'
                        Coords node;
                        node.x = j;
                        node.y = i - 1;
                        graph[i][j].push_back(node);
                    }
                }
            }
        }
    }

    // координата x это j,  а y это i
    /*for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < m; j++) {
            cout << '\n' << "Vertex: " << j << ' ' << i << '\n';
            for (int k = 0; k < graph[i][j].size(); k++) {
                cout << "x: " << graph[i][j][k].x << " y: " << graph[i][j][k].y << ' ';
            }
        }
    }*/

    q.push(start);
    used[start.y][start.x] = true; // i == y, j == x

    bfs(parents);
    vector<Coords> path;
    /*cout << '\n' << "=================================================" << '\n';
    cout << dist[finish.y][finish.x] << '\n';
    cout << "=================================================" << '\n';*/
    vector<string> pth_str;
    if (dist[finish.y][finish.x] == 0) {
        cout << -1;
        return 0;
    }
    else {
        int sz_vect = parents[finish.y][finish.x].size();
        /*int i = finish.y, j = finish.x;
        while ((i != start.y) && (j != start.x)) {
            i = parents[i][j][0].y;
            j = parents[i][j][0].x;
            path.push_back(parents[i][j][0]);
        }*/

        for (int i = finish.y, j = finish.x; ((i != start.y) || (j != start.x));) {
            path.push_back(parents[i][j][0]);
            int i_temp = parents[i][j][0].y;
            int j_temp = parents[i][j][0].x;
            if (i != i_temp) {
                if (i_temp - i == -1)
                    pth_str.push_back("D");
                else
                    pth_str.push_back("U");
            }
            else {
                if (j_temp - j == -1)
                    pth_str.push_back("R");
                else
                    pth_str.push_back("L");
            }
            i = i_temp;
            j = j_temp;
        }
    }
    reverse(pth_str.begin(), pth_str.end());


    cout << dist[finish.y][finish.x] << '\n';
    for (int i = 0; i < pth_str.size(); i++) {
        //cout << "x: " << path[i].x << " y: " << path[i].y << '\n';
        cout << pth_str[i];
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}