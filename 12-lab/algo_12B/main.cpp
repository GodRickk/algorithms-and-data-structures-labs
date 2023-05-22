#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <int> d (n + 1);
    vector <int> pos (n + 1);
    vector <int> prev (n);
    vector <int> path;
    int len = 0;
    pos[0] = -1;
    d[0] = -INT32_MAX;
    for (int i = 1; i <= n; i++) {
        d[i] = INT32_MAX;
    }

    for (int i = 0; i < n; i++) {
        int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            len = max(len, j);
        }
    }

    cout << len << '\n';
    int p = pos[len];
    while (p != -1) {
        path.push_back(a[p]);
        p = prev[p];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    return 0;
}