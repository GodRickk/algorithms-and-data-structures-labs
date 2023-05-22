#include <iostream>

using namespace std;

typedef struct Node {
    int key = 0;
    int left;
    int right;
    int number;
    int height = 1;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    Node* parent = nullptr;
} Node;

int string_number = 0;


int HeightOfTree(Node* Tree)
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


Node* SmallLeftRotate (Node *Tree) {
    Node* temp = Tree;
    Tree = Tree->right_child;
    temp->right_child = Tree->left_child;
    Tree->left_child = temp;
    return Tree;
}


Node* BigLeftRotate (Node *Tree) {
    Node* temp = Tree;
    Node* left_temp;
    Node* right_temp;

    Tree = Tree->right_child->left_child;
    left_temp = Tree->left_child;
    right_temp = Tree->right_child;

    Tree->left_child = temp;
    Tree->right_child = temp->right_child;

    Tree->left_child->right_child = left_temp;
    Tree->right_child->left_child = right_temp;
    return Tree;
}

Node* SetNumbers(Node *Tree, Node* b) {
    string_number += 1;
    Tree->number = string_number;
    b[string_number] = *Tree;

    if (Tree->left_child != nullptr) {
        SetNumbers(Tree->left_child, b);
    }
    if (Tree->right_child != nullptr ) {
        SetNumbers(Tree->right_child, b);
    }
    return b;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);

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

    Node *root;
    int heigh_of_right_tree = HeightOfTree(a[1].right_child->right_child);
    int heigh_of_left_tree = HeightOfTree(a[1].right_child->left_child);

    int balance_right_node = heigh_of_right_tree - heigh_of_left_tree;

    if (balance_right_node == -1) {
        root = BigLeftRotate(&a[1]);
    }
    else {
        root = SmallLeftRotate(&a[1]);
    }

    Node *b = new Node[n + 1];
    b = SetNumbers(root, b);

    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i].key << " ";
        if (b[i].left_child != nullptr) {
            cout << b[i].left_child->number << " ";
        }
        else {
            cout << 0 << " ";
        }
        if (b[i].right_child != nullptr) {
            cout << b[i].right_child->number << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    delete[] a;
    delete[] b;
    return 0;
}