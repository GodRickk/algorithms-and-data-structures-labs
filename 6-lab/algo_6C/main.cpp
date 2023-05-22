#include <iostream>
#include <vector>

using namespace std;

int GetKey(string key) {
    int heshValue = 0;
    for(char i : key) {
        heshValue = 13 * heshValue + 5 * i;
        //heshValue = i / 10;
    }
    return abs(heshValue % 1000001);
}


struct ListElem {
    string key;
    string value;
    ListElem* next;
    ListElem* prev;
    ListElem* nextColision;
    int hashkey;
    explicit ListElem(string k, string val) {
        key = k;
        value = val;
        hashkey = GetKey(key);
        prev = nullptr;
        next = nullptr;
        nextColision = nullptr;
    }
};

ListElem* HashTable[1000001];


/*int Search(vector<pair<string, string>> v, const string &word) {
    int m = v.size();
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == word) {
            return i;
        }
    }
    return 0;
}*/



ListElem* Put(ListElem* Tree, ListElem* Select) {

    if (Tree == nullptr) {
        HashTable[Select->hashkey] = Select;
        return Select;
    }
    else if (HashTable[Select->hashkey] != nullptr && HashTable[Select->hashkey]->key == Select->key) {
        HashTable[Select->hashkey]->value = Select->value;
        return Tree;
    }
        // Если возникла коллизия
    else if (HashTable[Select->hashkey] != nullptr && HashTable[Select->hashkey]->key != Select->key) {
        ListElem* currCol = HashTable[Select->hashkey];
        while (currCol->nextColision != nullptr) {
            currCol = currCol->nextColision;
        }
        currCol->nextColision = Select;
        Tree->next = Select;
        Tree->next->prev = Tree;
        return Tree->next;
    }
    else {
        Tree->next = Select;
        Tree->next->prev = Tree;
        HashTable[Select->hashkey] = Select;
        return Tree->next;
    }
}

string Get(string key) {
    int keyRes = GetKey(key);
    if (HashTable[keyRes] == nullptr) {
        return "none";
    }
    else if (HashTable[keyRes]->key == key) {
        return HashTable[keyRes]->value;
    }
    else {
        ListElem* currCol = HashTable[keyRes];
        while (currCol->nextColision != nullptr) {
            currCol = currCol->nextColision;
            if (currCol->key == key)
                return currCol->value;
        }
        return "none";
    }
}

ListElem* Delete(ListElem* Tree, string key) {
    int keyRes = GetKey(key);
    ListElem* delStruct;
    ListElem* prevCol = nullptr;
    ListElem* currCol = HashTable[keyRes];
    if (HashTable[keyRes] != nullptr) {
        if (HashTable[keyRes]->key == key) {
            delStruct = HashTable[keyRes];
            HashTable[keyRes] = HashTable[keyRes]->nextColision;
        }
        else {
            /*while (currCol->key != key && currCol->nextColision != nullptr) {
                prevCol = currCol;
                currCol = currCol->nextColision;
            }*/
            while (currCol->nextColision != nullptr) {
                if (currCol->nextColision->key == key) {
                    prevCol = currCol;
                    currCol = currCol->nextColision;
                    break;
                }
                else {
                    currCol = currCol->nextColision;
                }
            }
            if (prevCol == nullptr)
                return Tree;
            delStruct = currCol;
        }
        //ListElem* delStruct = HashTable[keyRes];
        if (prevCol != nullptr) {
            prevCol->nextColision = currCol->nextColision;
        }
        if (delStruct->next != nullptr) {
            delStruct->next->prev = delStruct->prev;
        }
        else {
            Tree = delStruct->prev;
        }
        if (delStruct->prev != nullptr) {
            delStruct->prev->next = delStruct->next;
        }

        delete delStruct;
    }
    return Tree;
}

/*string Prev(string key) {
    int keyRes = GetKey(key);
    if (HashTable[keyRes] == nullptr) {
        return "none";
    }
    else {
        if (HashTable[keyRes]->prev == nullptr) {
            return "none";
        }
        else {
            return HashTable[keyRes]->prev->value;
        }
    }
}*/
string Prev(string key) {
    int keyRes = GetKey(key);
    if (HashTable[keyRes] == nullptr) {
        return "none";
    }
    else if (HashTable[keyRes]->key == key) {
        if (HashTable[keyRes]->prev == nullptr) {
            return "none";
        }
        else {
            return HashTable[keyRes]->prev->value;
        }
    }
    else {
        ListElem* currCol = HashTable[keyRes];
        while (currCol->nextColision != nullptr) {
            currCol = currCol->nextColision;
            if (currCol->key == key)
                if (currCol->prev == nullptr) {
                    return "none";
                }
                else {
                    return currCol->prev->value;
                }
        }
        return "none";
    }
}

string Next(string key) {
    int keyRes = GetKey(key);
    if (HashTable[keyRes] == nullptr) {
        return "none";
    }
    else if (HashTable[keyRes]->key == key) {
        if (HashTable[keyRes]->next == nullptr) {
            return "none";
        }
        else {
            return HashTable[keyRes]->next->value;
        }
    }
    else {
        ListElem* currCol = HashTable[keyRes];
        while (currCol->nextColision != nullptr) {
            currCol = currCol->nextColision;
            if (currCol->key == key)
                if (currCol->next == nullptr) {
                    return "none";
                }
                else {
                    return currCol->next->value;
                }
        }
        return "none";
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    string command;
    string key, value;

    ListElem* Tree = nullptr;
    while (cin >> command) {
        if (command == "put") {
            cin >> key >> value;
            ListElem *Select = new ListElem(key, value);
            Tree = Put(Tree, Select);
        } else if (command == "get") {
            cin >> key;
            string resGet = Get(key);
            cout << resGet << "\n";
        } else if (command == "delete") {
            cin >> key;
            Tree = Delete(Tree, key);
        } else if (command == "prev") {
            cin >> key;
            string resPrev = Prev(key);
            cout << resPrev << "\n";
        }
        else if (command == "next") {
            cin >> key;
            string resNext = Next(key);
            cout << resNext << "\n";
        }
    }
    return 0;
}