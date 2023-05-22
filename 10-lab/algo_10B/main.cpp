#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;


const float maxFloat = numeric_limits<float>::max();
struct coordVert {
    float x;
    float y;
};


// 1D - minDist vector
void MSTPrim(int const &n, vector<bool> &inMST, vector<float> &minDist, vector<vector<float>> &dist) {
    for (int i = 1; i <= n; i++) {
        int vert = 0;
        for (int j = 1; j <= n; j++) {
            if ((!inMST[j]) && (vert == 0 || minDist[j] < minDist[vert])) {
                vert = j;
            }
        }
        inMST[vert] = true;
        for (int nextVert = 1; nextVert <= n; nextVert++) {
            if (vert != nextVert) {
                if (!inMST[nextVert]) {
                    if (dist[vert][nextVert] < minDist[nextVert]) {
                        minDist[nextVert] = dist[vert][nextVert];
                    }
                }
            }
        }
    }
}


// 2D - minDist vector
/*void MSTPrim (int const &n, vector<bool> &inMST, vector< vector<float>> &minDist, vector< vector<float>> &dist) {
    for (int i = 1; i <= n; i++) {
        int vert = 0;
        for (int j = 1; j <= n; j++) {
            if ((!inMST[j]) &&  (vert == 0 || minDist[j] < minDist[vert])) {
                vert = j;
            }
        }
        inMST[vert] = true;
        for (int nextVert = 1; nextVert <= n; nextVert++) {
            if (vert != nextVert) {
                if (dist[vert][nextVert] < minDist[vert][nextVert]) {
                    minDist[vert][nextVert] = dist[vert][nextVert];
                    minDist[nextVert][vert] = dist[vert][nextVert];
                }
            }
        }
    }
}*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    int n;
    cin >> n;
    vector<bool> inMST(n + 1, false);

    //2D - minDist vector
    /*vector<vector <float>> minDist;
    minDist.resize(n + 1, vector<float>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            minDist[i][j] = maxFloat;
        }
    }*/

    // 1D - minDist vector
    vector<float> minDist;
    minDist.resize(n + 1, maxFloat);

    vector<vector<float>> dist;
    dist.resize(n + 1, vector<float>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dist[i][j] = 0;
        }
    }

    vector<coordVert> coords;
    coords.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        float x, y;
        cin >> x >> y;
        coords[i].x = x;
        coords[i].y = y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = sqrtf(powf((coords[j].x - coords[i].x), 2) + powf((coords[j].y - coords[i].y), 2));
            dist[j][i] = dist[i][j];
        }
    }

    coords.clear();

    MSTPrim(n, inMST, minDist, dist);

    float res = 0;
    float minEg = maxFloat;

    // 1D - minDist vector
    for (int i = 1; i <= n; i++) {
        if (minDist[i] != maxFloat) {
            if (minDist[i] < minEg) {
                minEg = minDist[i];
            }
            res += minDist[i];
        }
    }

    // 2D - minDist vector
    /*for (int i = 1; i <= n; i++) {
        temp = maxFloat;
        for (int j = 1; j <= n; j++) {
            if (minDist[i][j] < temp) {
                temp = minDist[i][j];
                continue;
            }
            if (minDist[i][j] < minEg) {
                minEg = minDist[i][j];
            }
            //res += minDist[i][j];
            //minDist[i][j] = 0;
            //minDist[j][i] = 0;
        }
        res += temp;
    }*/

    cout << setprecision(15) << res;

    return 0;
}