#include <iostream>

using namespace std;

typedef struct parameters {
    int key = 0;
    int left;
    int right;
    int height = 1;
    parameters* parent = nullptr;
} parameters;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);

    int n;
    int maxheight = 0;
    cin >> n;
    parameters a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].key >> a[i].left >> a[i].right;
        a[a[i].left - 1].parent = &a[i];
        a[a[i].right - 1].parent = &a[i];

        if (a[i].parent != nullptr) {
            a[i].height = a[i].parent->height + 1;
        }

        if (a[i].height > maxheight)
            maxheight = a[i].height;
    }
    cout << maxheight;
    //_CrtSetDebugFillThreshold(0);
    return 0;
}