#include <fstream>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* parent;
    Node* left;
    Node* right;
    explicit Node(int el){
        value = el;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};


Node* Insert(Node* Tree, Node* Select) {

    if (Tree == nullptr) {
        return Select;
    }
    if (Select->value < Tree->value) {
        Tree->left = Insert(Tree->left, Select);
        Tree->left->parent = Tree;
    }
    else if (Select->value > Tree->value) {
        Tree->right = Insert(Tree->right, Select);
        Tree->right->parent = Tree;
    }
    return Tree;
}


string Exsists(Node* Tree, int value) {
    Node* Cur = Tree;
    while (Cur != nullptr && Cur->value != value) {
        if (value > Cur->value)
            Cur = Cur->right;
        else
            Cur = Cur->left;
    }

    if (Cur == nullptr || Cur->value != value) {
        return "false";
    }
    else return "true";
}

Node* Minimum(Node* Tree) {
    while (Tree->left != nullptr) {
        Tree = Tree->left;
    }
    return Tree;
}


Node* Maximum(Node* Tree) {
    while (Tree->right != nullptr) {
        Tree = Tree->right;
    }
    return Tree;
}

Node* Next(Node* Tree, int value) {
    if (Tree == nullptr)
        return Tree;
    int flag;
    Node* Cur = Tree,* Prev = Tree;
    while (Cur != nullptr && Cur->value != value) {
        Prev = Cur;
        if (value > Cur->value) {
            Cur = Cur->right;
            flag = 1;
        }
        else {
            Cur = Cur->left;
            flag = 0;
        }
    }
    if (Cur != nullptr) {
        if (Cur->right != nullptr)
            return Minimum(Cur->right);
        while (Cur->parent != nullptr && Cur->parent->right == Cur)
            Cur = Cur->parent;
        return Cur->parent;
    }
    if (flag) {
        while (Prev->parent != nullptr && Prev->parent->right == Prev)
            Prev = Prev->parent;
        return Prev->parent;
    }
    else
        return Prev;
}

Node* Prev(Node* Tree, int value) {
    if (Tree == nullptr)
        return Tree;
    int flag;
    Node* Cur = Tree,* Prev = Tree;
    while (Cur != nullptr && Cur->value != value) {
        Prev = Cur;
        if (value > Cur->value) {
            Cur = Cur->right;
            flag = 0;
        }
        else {
            Cur = Cur->left;
            flag = 1;
        }
    }
    if (Cur != nullptr) {
        if (Cur->left != nullptr)
            return Maximum(Cur->left);
        while (Cur->parent != nullptr && Cur->parent->left == Cur)
            Cur = Cur->parent;
        return Cur->parent;
    }
    if (flag) {
        while (Prev->parent != nullptr && Prev->parent->left == Prev)
            Prev = Prev->parent;
        return Prev->parent;
    }
    else
        return Prev;
}


Node* Transplant(Node* Tree, Node* u, Node* v) {
    if (u->parent == nullptr)
        Tree = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
    return Tree;
}

Node* Delete(Node* Tree, int value) {
    Node* Cur = Tree;
    while (Cur != nullptr && Cur->value != value) {
        if (value > Cur->value)
            Cur = Cur->right;
        else
            Cur = Cur->left;
    }
    if (Cur == nullptr)
        return Tree;
    Node* Swap = Cur;
    //Если нет левого потомка
    if (Cur->left == nullptr)
        Tree = Transplant(Tree, Cur, Cur->right);
    else if (Cur->right == nullptr)
        Tree = Transplant(Tree, Cur, Cur->left);
    else {
        Swap = Minimum(Cur->right);
        Tree = Transplant(Tree, Swap, Swap->right);
        Cur->value = Swap->value;
    }

    return Tree;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    //ifstream fin("bstsimple.in");
    //ofstream fout("bstsimpled.out");
    string com;
    int x;
    Node* Tree = nullptr;
    while (cin >> com) {
        cin >> x;
        if (com == "insert") {
            Node *Select = new Node(x);
            Tree = Insert(Tree, Select);
        } else if (com == "delete") {
            Tree = Delete(Tree, x);
        } else if (com == "exists") {
            cout << Exsists(Tree, x) << '\n';
        } else if (com == "next") {
            Node* y = Next(Tree, x);
            if (y != nullptr)
                cout << y->value << '\n';
            else
                cout << "none" << '\n';
        } else if (com == "prev") {
            Node* y = Prev(Tree, x);
            if (y != nullptr)
                cout << y->value << '\n';
            else
                cout << "none" << '\n';
        }
    }
}