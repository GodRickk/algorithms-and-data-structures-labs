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
    cin >> str;
    vector <int> pi (str.length());

    prefix_func(str, pi);
    for (int i = 0; i < pi.size(); i++) {
        cout << pi[i] << ' ';
    }

    return 0;
}