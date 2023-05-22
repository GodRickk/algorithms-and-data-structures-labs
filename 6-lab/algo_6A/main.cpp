#include <iostream>
#include <vector>

using namespace std;

vector<int> HeshTable[1000001];

int Search (vector<int> v, int number) {
    for (int k = 0; k < v.size(); k++) {
        if (v[k] == number) {
            return k;
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string command;
    int number;
    while (cin >> command){
        if (command == "insert") {
            cin >> number;
            int j = abs(number % 1000001);
            int g = Search(HeshTable[j], number);
            if (HeshTable[j].empty() || HeshTable[j][g] != number) {
                HeshTable[j].push_back(number);
            }
        }
        else if (command == "delete") {
            cin >> number;
            int j = abs(number % 1000001);
            int g = Search(HeshTable[j], number);
            if (!HeshTable[j].empty() && HeshTable[j][g] == number){
                swap(HeshTable[j][g], HeshTable[j][HeshTable[j].size() - 1]);
                HeshTable[j].pop_back();
            }
        }
        else if (command == "exists") {
            cin >> number;
            int j = abs(number % 1000001);
            int g = Search(HeshTable[j], number);
            if (!HeshTable[j].empty() && HeshTable[j][g] == number) {
                cout << "true\n";
            }
            else {
                cout << "false\n";
            }
        }
    }

    return 0;
}