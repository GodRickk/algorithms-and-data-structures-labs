#include <iostream>

using namespace std;

typedef struct Node {
    int key = 0;
    int left;
    int right;
    int height = 1;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    Node* parent = nullptr;
} Node;

int HeightOfTree(Node * Tree)
{
    if (Tree == 0) {
        return 0;
    }
    int left, right;
    if (Tree->left_child != nullptr) {
        left = HeightOfTree(Tree->left_child);
    } else
        left = 0;
    if (Tree->right_child != nullptr) {
        right = HeightOfTree(Tree->right_child);
    } else
        right = 0;

    int max = 0;
    if (left > right) {
        max = left;
    }
    else {
        max = right;
    }
    Tree->height = max + 1;
    return max + 1;
}

/*int sumHeight(Node * Tree) {
    if (Tree == 0) {
        return 0;
    }
    int left, right;
    if (Tree->left_child != nullptr) {
        left = sumHeight(Tree->left_child);

}*/


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);

    int n;
    cin >> n;
    Node *a = new Node[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i].key >> a[i].left >> a[i].right;

        if (a[i].left != 0) {
            a[i].left_child = &a[a[i].left];
            a[a[i].left].parent = &a[i];
        }
        if (a[i].right != 0) {
            a[i].right_child = &a[a[i].right];
            a[a[i].right].parent = &a[i];
        }
    }

    HeightOfTree(&a[1]);
    int balance;
    for (int i = 1; i <= n; i++) {
        int rightHeight = 0;
        int leftHeight = 0;
        //balance = HeightOfTree(a[i].right_child) - HeightOfTree(a[i].left_child);
        if (a[i].right_child != nullptr)
            rightHeight = a[i].right_child->height;
        if (a[i].left_child != nullptr)
            leftHeight = a[i].left_child->height;
        balance = rightHeight - leftHeight;
        cout << balance << "\n";
    }

    delete[] a;
    return 0;
}