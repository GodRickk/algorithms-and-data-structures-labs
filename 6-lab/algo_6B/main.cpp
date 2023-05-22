#include <iostream>
#include <vector>

using namespace std;

vector<pair<string, string>> HeshTable[1000001];

int Search(vector<pair<string, string>> v, const string &word) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == word) {
            return i;
        }
    }
    return 0;
}

int GetKey(string key) {
    int heshValue = 0;
    for(char i : key) {
        heshValue = 20 * heshValue + (int)i;
    }
    return abs(heshValue % 100001);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    string command;
    string key, value;
    int j, k;
    while (cin >> command) {
        if (command == "put") {
            cin >> key >> value;
            j = GetKey(key);
            k = Search(HeshTable[j], key);
            if (!HeshTable[j].empty() && HeshTable[j][k].first == key) {
                HeshTable[j][k].second = value;
            }
            if (HeshTable[j].empty() || HeshTable[j][k].first != key) {
                HeshTable[j].emplace_back(key, value);
            }
        }
        else if (command == "delete") {
            cin >> key;
            j = GetKey(key);
            k = Search(HeshTable[j], key);
            if (!HeshTable[j].empty() && HeshTable[j][k].first == key) {
                swap(HeshTable[j][k], HeshTable[j][HeshTable[j].size() - 1]);
                HeshTable[j].pop_back();
            }
        }
        else if (command == "get") {
            cin >> key;
            j = GetKey(key);
            k = Search(HeshTable[j], key);
            if (!HeshTable[j].empty() && HeshTable[j][k].first == key) {
                cout << HeshTable[j][k].second << '\n';
            } else {
                cout << "none\n";
            }
        }

    }

    return 0;
}