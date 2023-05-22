#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> a (n); // long?
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <int> d (n);
    vector <int> pr (n);
    vector <int> path;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        pr[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (d[j] + 1 > d[i]) {
                    d[i] = 1 + d[j];
                    pr[i] = j;
                }
            }
        }
    }

    int res = d[0];
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > res) {
            res = d[i];
            flag = i;
        }
    }
    cout << res << '\n';
    for (flag;; flag = pr[flag]) {
        if (flag == -1) {
            break;
        }
        path.push_back(a[flag]);
    }

    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    return 0;
}