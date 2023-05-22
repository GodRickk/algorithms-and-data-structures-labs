#include <fstream>
#include <string>

using namespace std;

struct Stack {
    char value;
    Stack *top = NULL;
};

Stack* add(char value, Stack *top) {
    Stack *st = (Stack*) malloc(sizeof(Stack));
    st->value = value;
    st->top = top;
    return st;
}

int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    for (int i = 0; i < 10000; i++) {

        Stack* brrackets = NULL;
        string symbol;
        getline(fin, symbol);

        if (symbol.length() == 0) break;

        for (int j = 0; j < symbol.length() + 1; j++) {
            if (symbol[j] == '(' || symbol[j] == '[') {
                brrackets = add(symbol[j], brrackets);

            } else if (symbol[j] == ')') {
                if (brrackets == NULL || brrackets->value == '[') {
                    fout << "NO\n";
                    break;
                } else {
                    brrackets = brrackets->top;
                }
            } else if (symbol[j] == ']') {
                if (brrackets == NULL || brrackets->value == '(') {
                    fout << "NO\n";
                    break;
                } else {
                    brrackets = brrackets->top;
                }
            } else {
                if (brrackets != NULL)
                    fout << "NO\n";
                else
                    fout << "YES\n";
                break;
            }
        }

    }
    return 0;
}