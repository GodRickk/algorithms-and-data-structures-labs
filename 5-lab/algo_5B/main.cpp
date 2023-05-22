#include <iostream>
#include <vector>

using namespace std;

typedef struct parameters {
    int key = 0;
    int minimum;
    int maximum;
    parameters* left = nullptr;
    parameters* right = nullptr;
    parameters* parent = nullptr;
} parameters;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    int n, left, right;
    cin >> n;
    parameters tree[n];

    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> left >> right;
        if (left != 0) {
            tree[i].left = &tree[left - 1];
            tree[i].left->parent = &tree[i];
        }
        if (right != 0) {
            tree[i].right = &tree[right - 1];
            tree[i].right->parent = &tree[i];
        }
        if (i != 0) {
            if (tree[i].parent == nullptr) {
                cout << "NO";
                return 0;
            }
            if (tree[i].parent->key == tree[i].key) {
                cout << "NO";
                return 0;
            }
            else if (tree[i].parent->key > tree[i].key && tree[i].parent->left != &tree[i]) {
                cout << "NO";
                return 0;
            }
            else if (tree[i].parent->key < tree[i].key && tree[i].parent->right != &tree[i]) {
                cout << "NO";
                return 0;
            }
            else if (tree[i].parent->key > tree[i].key && tree[i].key <= tree[i].parent->minimum) {
                cout << "NO";
                return 0;
            }
            else if (tree[i].parent->key < tree[i].key && tree[i].key >= tree[i].parent->maximum) {
                cout << "NO";
                return 0;
            }
            if (tree[i].parent->key > tree[i].key) {
                tree[i].maximum = tree[i].parent->key;
                tree[i].minimum = tree[i].parent->minimum;
            } else if (tree[i].parent->key < tree[i].key) {
                tree[i].minimum = tree[i].parent->key;
                tree[i].maximum = tree[i].parent->maximum;
            }

        }
        else {
            tree[i].minimum = -2147483648;
            tree[i].maximum = 2147483647;
        }
    }
    cout << "YES";
    //_CrtSetDebugFillThreshold(0);
    return 0;
}