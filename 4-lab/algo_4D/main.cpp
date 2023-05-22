#include <fstream>
using namespace std;

struct Stack {
    long value;
    Stack *top = NULL;
};

Stack* add(long value, Stack* top) {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->value = value;
    st->top = top;
    return st;
}

int main() {
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    char command;
    Stack* numbers = NULL;
    for (int i = 0; i < 100; i++) {
        fin >> command;
        if (command == '+') {

            if (numbers==NULL||numbers->top==NULL)
                break;
            numbers->top->value = numbers->value+numbers->top->value;
            numbers = numbers->top;

        } else if (command == '-') {

            if (numbers==NULL||numbers->top==NULL)
                break;
            numbers->top->value = numbers->top->value-numbers->value;
            numbers = numbers->top;

        } else if (command == '*') {

            if (numbers==NULL||numbers->top==NULL)
                break;
            numbers->top->value = numbers->value*numbers->top->value;
            numbers = numbers->top;

        } else if ((int)command>=48&&(int)command<=58) {
            numbers = add((int)command - 48, numbers);
        }
    }
    fout << numbers->value;
    return 0;
}