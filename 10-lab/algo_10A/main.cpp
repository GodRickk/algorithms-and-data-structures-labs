#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int degree_vertexes[101] = { };

    for (int i = 0; i < m; i++) {
        int vert_1, vert_2;
        cin >> vert_1 >> vert_2;
        degree_vertexes[vert_1]++;
        degree_vertexes[vert_2]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << degree_vertexes[i] << ' ';
    }
    return 0;
}