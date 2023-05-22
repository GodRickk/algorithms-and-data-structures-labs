#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    string str;
    string sub_str;
    cin >> sub_str;
    cin >> str;
    int i = 0;
    int count = 0;
    vector <int> index;
    for (i = str.find(sub_str, i++); i != string::npos; i = str.find(sub_str, i + 1)) {
        count++;
        index.push_back(i);
    }

    cout << count << '\n';
    for (int j = 0; j < index.size(); j++) {
        cout << index[j] + 1 << ' ';
    }

    return 0;
}