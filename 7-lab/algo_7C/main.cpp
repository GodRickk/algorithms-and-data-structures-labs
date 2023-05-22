#include <iostream>

using namespace std;

typedef struct Node {
    int key = 0;
    //int left;
    //int right;
    int number;
    int height = 1;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    Node* parent = nullptr;
} Node;


int string_number = 0;


int HeightOfTree(Node* Tree)
{
    if (Tree == nullptr) {
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
    Tree->parent = temp->parent;
    if (Tree->parent != nullptr) {
        if (Tree->key > Tree->parent->key) {
            Tree->parent->right_child = Tree;
        }
        else {
            Tree->parent->left_child = Tree;
        }
    }

    temp->right_child = Tree->left_child;

    if (temp->right_child != nullptr) {
        temp->right_child->parent = temp;
    }


    Tree->left_child = temp;
    Tree->left_child->parent = Tree;
    return Tree;
}


Node* SmallRightRotate (Node *Tree) {
    Node* temp = Tree;

    Tree = Tree->left_child;
    Tree->parent = temp->parent;
    if (Tree->parent != nullptr) {
        if (Tree->key > Tree->parent->key) {
            Tree->parent->right_child = Tree;
        }
        else {
            Tree->parent->left_child = Tree;
        }
    }

    temp->left_child = Tree->right_child;

    if (temp-> right_child != nullptr) {
        temp->left_child->parent = temp;
    }


    Tree->right_child = temp;
    Tree->right_child->parent = Tree;
    return Tree;
}


Node* BigLeftRotate (Node *Tree) {
    Node* temp = Tree;
    Node* left_temp;
    Node* right_temp;

    Tree = Tree->right_child->left_child;
    Tree->parent = temp->parent;
    if (Tree->parent != nullptr) {
        if (Tree->key > Tree->parent->key) {
            Tree->parent->right_child = Tree;
        }
        else {
            Tree->parent->left_child = Tree;
        }
    }


    left_temp = Tree->left_child;
    right_temp = Tree->right_child;

    Tree->left_child = temp;
    Tree->right_child = temp->right_child;

    Tree->left_child->right_child = left_temp;
    Tree->right_child->left_child = right_temp;

    Tree->left_child->parent = Tree;
    Tree->right_child->parent = Tree;
    if (Tree->left_child->right_child != nullptr) {
        Tree->left_child->right_child->parent = Tree->left_child;
    }
    if (Tree->right_child->left_child != nullptr) {
        Tree->right_child->left_child->parent = Tree->right_child;
    }
    return Tree;
}

Node* BigRightRotate (Node *Tree) {
    Node* temp = Tree;
    Node* left_temp;
    Node* right_temp;

    Tree = Tree->left_child->right_child;
    Tree->parent = temp->parent;
    if (Tree->parent != nullptr) {
        if (Tree->key > Tree->parent->key) {
            Tree->parent->right_child = Tree;
        }
        else {
            Tree->parent->left_child = Tree;
        }
    }

    left_temp = Tree->right_child;
    right_temp = Tree->left_child;

    Tree->right_child = temp;
    Tree->left_child = temp->left_child;

    Tree->right_child->left_child = left_temp;
    Tree->left_child->right_child = right_temp;

    Tree->right_child->parent = Tree;
    Tree->left_child->parent = Tree;

    if (Tree->right_child->left_child != nullptr) {
        Tree->right_child->left_child->parent = Tree->right_child;
    }
    if (Tree->left_child->right_child != nullptr) {
        Tree->left_child->right_child->parent = Tree->left_child;
    }
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



Node* Insert(Node *Tree, Node *Select) {
    if (Tree == nullptr) {
        return Select;
    }
    if (Select->key < Tree->key) {
        if (Tree->left_child != nullptr) {
            Tree->left_child = Insert(Tree->left_child, Select);
        }
        else {
            Tree->left_child = Select;
            Tree->left_child->parent = Tree;
            return Tree;
        }
    }
    else if (Select->key > Tree->key) {
        if (Tree->right_child != nullptr) {
            Tree->right_child = Insert(Tree->right_child, Select);
        }
        else {
            Tree->right_child = Select;
            Tree->right_child->parent = Tree;
            return Tree;
        }
    }
    return Tree;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);

    int n, our_key, left, right;
    cin >> n;
    Node *a = new Node[n + 3];


    /*for (int i = 1; i <= n; i++) {
        cin >> a[i].key >> a[i].left >> a[i].right;

        if (a[i].left != 0) {
            a[i].left_child = &a[a[i].left];
            a[a[i].left].parent = &a[i];
        }
        if (a[i].right != 0) {
            a[i].right_child = &a[a[i].right];
            a[a[i].right].parent = &a[i];
        }
    }*/

    for (int i = 1; i <= n; i++) {
        cin >> a[i].key >> left >> right;

        if (left != 0) {
            a[i].left_child = &a[left];
            a[left].parent = &a[i];
        }
        if (right != 0) {
            a[i].right_child = &a[right];
            a[right].parent = &a[i];
        }
    }


    cin >> our_key;
    if (n == 0) {
        cout << n + 1 << "\n";
        cout << our_key << " 0 0";
        return 0;
    }

    Node *root;
    Node* saved_root;
    Node *Select = new Node;
    Select->key = our_key;

    root = Insert(&a[1], Select);

    //root = BigLeftRotate(root);
    //root = SmallRightRotate(root);
    //root = BigRightRotate(root);

    a[n + 2] = *Select;
    HeightOfTree(root);
    Node *current_node = Select->parent;

    while (current_node != nullptr) {
        int height_right_node = 0;
        int height_left_node = 0;
        int bal;
        HeightOfTree(current_node);
        if (current_node->right_child != nullptr) {
            height_right_node = current_node->right_child->height;
        }
        if (current_node->left_child != nullptr) {
            height_left_node = current_node->left_child->height;
        }
        //int height_right_node = current_node->right_child->height;
        //int height_left_node = current_node->left_child->height;

        bal = height_right_node - height_left_node;
        int balance_left_node_for_big_right_rotate;
        int balance_right_node_for_big_left_rotate;

        int heigh_of_right_tree_big_left_rotate = 0;
        int heigh_of_left_tree_big_left_rotate = 0;

        int heigh_of_right_tree_big_right_rotate = 0;
        int heigh_of_left_tree_big_right_rotate = 0;

        if (bal > 1) {
            if (current_node->right_child->right_child != nullptr) {
                heigh_of_right_tree_big_left_rotate = current_node->right_child->right_child->height;
            }
            if (current_node->right_child->left_child != nullptr) {
                heigh_of_left_tree_big_left_rotate = current_node->right_child->left_child->height;
            }
            balance_right_node_for_big_left_rotate = heigh_of_right_tree_big_left_rotate - heigh_of_left_tree_big_left_rotate;

        }
        if (bal < -1) {
            if (current_node->left_child->right_child != nullptr) {
                heigh_of_right_tree_big_right_rotate = current_node->left_child->right_child->height;
            }
            if (current_node->left_child->left_child != nullptr) {
                heigh_of_left_tree_big_right_rotate = current_node->left_child->left_child->height;
            }
            balance_left_node_for_big_right_rotate = heigh_of_right_tree_big_right_rotate - heigh_of_left_tree_big_right_rotate;
        }

        if (bal > 1) {

            if (balance_right_node_for_big_left_rotate == -1) {
                current_node = BigLeftRotate(current_node);
            }
            else {
                current_node = SmallLeftRotate(current_node);
            }
        }
        else if (bal < -1) {

            if (balance_left_node_for_big_right_rotate == 1) {
                current_node = BigRightRotate(current_node);
            }
            else {
                current_node = SmallRightRotate(current_node);
            }
        }
        saved_root = current_node;
        current_node = current_node->parent;

    }

    Node *b = new Node[n + 3];
    b = SetNumbers(saved_root, b);

    cout << n + 1 << "\n";
    for (int i = 1; i <= n + 1; i++) {
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
    delete Select;
    return 0;
}