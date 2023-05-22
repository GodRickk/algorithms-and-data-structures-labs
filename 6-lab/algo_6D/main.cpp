#include <iostream>
#include <string>

using namespace std;

int GetKey(string key) {
    int hashValue = 0;
    int temp = 1;
    for(char i : key) {
        //hashValue += temp * (int)i;
        //hashValue %= 100003;
        //temp = (temp * 37) % 100003;
        hashValue = (i / 10) * hashValue + i;
        //hashValue = i / 10;
    }
    return abs(hashValue % 100003);
    //return hashValue;
}

struct Node {
    string value;
    Node* parent;
    Node* left;
    Node* right;
    explicit Node(string el){
        value = el;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

struct Header {
    string key;
    Node* head;
    Header* nextColision;
    Header* prevColision;
    int hashkey;
    int count;
    explicit Header(string k) {
        key = k;
        hashkey = GetKey(key);
        nextColision = nullptr;
        prevColision = nullptr;
        count = 0;
    }
};

Header* HashTable[100000];
bool del_check;


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

Node* Minimum(Node* Tree) {
    while (Tree->left != nullptr) {
        Tree = Tree->left;
    }
    return Tree;
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

Node* DeleteEl(Node* Tree, string value) {
    Node* Cur = Tree;
    while (Cur != nullptr && Cur->value != value) {
        if (value > Cur->value)
            Cur = Cur->right;
        else
            Cur = Cur->left;
    }
    if (Cur == nullptr) {
        del_check = false;
        return Tree;
    }

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
    del_check = true;
    return Tree;
}

bool Exsists(Node* Tree, string value) {
    bool flag = false;
    Node* Cur = Tree;
    Node* Prev;
    Node* newNode = new Node(value);
    while (Cur != nullptr && Cur->value != value) {
        if (value > Cur->value){
            Prev = Cur;
            if (Cur->right == nullptr) {
                Cur->right = newNode;
                Cur->right->parent = Cur;
                flag = true;
                break;
            }
            Cur = Cur->right;
        }
        else if (value < Cur->value) {
            Prev = Cur;
            if (Cur->left == nullptr) {
                Cur->left = newNode;
                Cur->left->parent = Cur;
                flag = true;
                break;
            }
            Cur = Cur->left;
        }

    }
    return flag;
}

void Put(string key, string value) {
    bool checker;
    Header *newHeader = new Header(key);
    Node *newNode = new Node(value);
    if (HashTable[newHeader->hashkey] == nullptr) {
        HashTable[newHeader->hashkey] = newHeader;
        HashTable[newHeader->hashkey]->head = newNode;
        HashTable[newHeader->hashkey]->count += 1;
    } else {
        Header *curHeader = HashTable[newHeader->hashkey];
        while (1) { //currCol->nextColision != nullptr
            //Нашли объект с таким же ключом
            if (curHeader->key == newHeader->key) { //Если мы уже нашли хэдер с таким же ключом Нужно вставлять сюда нашу ноду(Если такое ещё нет)
                //curHeader->head = Insert(curHeader->head, newNode); //?? Как понять добавили или нет, чтобы понять, увеличивать счетчик или нет
                checker = Exsists(curHeader->head, value); //true если элемента не было и мы его добавили
                if (checker)
                    curHeader->count += 1; //Соеденить инсерт и экзист
                break;
            }
            if (curHeader->nextColision == nullptr) {
                curHeader->nextColision = newHeader;
                curHeader->nextColision->head = newNode;
                curHeader->nextColision->count += 1;
                curHeader->nextColision->prevColision = curHeader;
                break;
            }
            curHeader = curHeader->nextColision;
        }
    }
}


void printTree(Node* Tree) {
    cout << Tree->value << " ";
    if (Tree->left != nullptr)
        printTree(Tree->left);
    if (Tree->right != nullptr)
        printTree(Tree->right);
}


void Get(string key) {
    int keyRes = GetKey(key);
    if (HashTable[keyRes] == nullptr) {
        cout << "0"; //return "0";
    } else {
        Header *curHeader = HashTable[keyRes];
        while (curHeader != nullptr) {
            if (curHeader->key == key) {
                cout << curHeader->count << " ";
                printTree(curHeader->head);
                break;
            }
            curHeader = curHeader->nextColision;
        }
        if (curHeader == nullptr)
            cout << "0";
    }
}

void Delete(string key, string value) {
    int keyRes = GetKey(key);
    Header* curHeader = HashTable[keyRes];
    if (HashTable[keyRes] != nullptr) {
        while (curHeader != nullptr) {
            if (curHeader->key == key) {
                curHeader->head = DeleteEl(curHeader->head, value);
                if (del_check)
                    curHeader->count -= 1;
                break;
            }
            curHeader = curHeader->nextColision;
        }
    }
    if (curHeader == nullptr)
        return;
    else if (curHeader->head == nullptr)
        if (curHeader == HashTable[keyRes])
            HashTable[keyRes] = curHeader->nextColision;
        else
            curHeader->prevColision->nextColision = curHeader->nextColision;
}

void DelleteAll (string key) {
    int keyRes = GetKey(key);
    Header *prevCol = nullptr;
    Header *currCol = HashTable[keyRes];
    if (HashTable[keyRes] != nullptr) {
        if (HashTable[keyRes]->key == key) {
            HashTable[keyRes] = HashTable[keyRes]->nextColision;
        }
        else {
            while (currCol != nullptr) {
                if (currCol->key == key) {
                    currCol->prevColision->nextColision = currCol->nextColision;
                    if (currCol->nextColision != nullptr)
                        currCol->nextColision->prevColision = currCol->prevColision;
                    break;
                }
                currCol = currCol->nextColision;
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    string command;
    string key, value;

    //ListElem* Tree = nullptr;
    while (cin >> command) {
        if (command == "put") {
            cin >> key >> value;
            //ListElem *Select = new ListElem(key, value);
            //Tree = Put(Tree, Select);
            Put(key, value);
        } else if (command == "get") {
            cin >> key;
            //string resGet = Get(key);
            Get(key);
            cout << "\n";
            //cout << resGet << "\n";
        } else if (command == "delete") {
            cin >> key >> value;
            //Tree = Delete(Tree, key, value);
            Delete(key, value);
        }
        else if (command == "deleteall") {
            cin >> key;
            DelleteAll(key);
        }
    }
    return 0;
}