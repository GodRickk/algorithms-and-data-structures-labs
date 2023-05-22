#include <iostream>
#include <vector>
#include <string>
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
    string str;
    string sub_str;
    cin >> sub_str;
    cin >> str;

    string s_sum = sub_str + '#' + str;

    vector <int> pi (s_sum.length());

    prefix_func(s_sum, pi);

    /*for (int i = 0; i < pi.size(); i++) {
        cout << pi[i] << ' ';
    }*/

    vector<int> res;

    int count = 0;
    int l = sub_str.length();
    int index;
    for (int i = l + 1; i < pi.size(); i++) {
        if (pi[i] == sub_str.length()) {
            count++;
            index = (i - 2 * sub_str.length()) + 1;
            res.push_back(index);
        }
    }

    cout << count << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }

    return 0;
}