#include <iostream>

using namespace std;
int n;
double height[100000];

double garland() {
    double left = height[0], right = 0;

    while (left - right > 0.000001) {
        height[1] = (left + right) / 2;
        bool d = true;
        for (int i = 2; i < n; i++) {
            height[i] = 2 * height[i - 1] - height[i - 2] + 2;
            if (height[i] < 0) {
                d = false;
                break;
            }
        }
        if (d)
            left = height[1];
        else
            right = height[1];
    }
    return height[n - 1];
}

int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);

    cin >> n;
    cin >> height[0];

    cout << fixed;
    cout.precision(2);
    cout << garland() << endl;
    return 0;
}