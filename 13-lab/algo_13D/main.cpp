#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void prefix_func(string str, vector <int> &pi) {
    for (int i = 1; i < pi.size(); i++) {
        int k = pi[i - 1];
        while(k > 0 && str[i] != str[k]) {
            k = pi[k - 1];
        }
        if (str[i] == str[k]) {
            k++;
        }
        pi[i] = k;
    }
}


int main() {
    string s;
    int alphabet;
    cin >> alphabet;
    cin >> s;
    s += '#';
    vector <int> pi (s.length());
    int len = s.length();

    prefix_func (s, pi);
    vector <vector <int>> aut (len, vector<int> (alphabet));

    for (int i = 0; i < len; i++) {
        for (char c = 0x61; c < alphabet + 97; c++) {
            if (i > 0 && c != s[i]) {
                aut[i][c - 97] = aut[pi[i - 1]][c - 97];
            }
            else {
                aut[i][c - 97] = i + (c == s[i]);
            }
        }
    }

    for (int i = 0; i < len; i++) {
        if (i != 0) {
            cout << '\n';
        }
        for (int j = 1; j <= alphabet ; j++) {
            cout << aut[i][j - 1] << ' ';
        }
    }

    return 0;
}