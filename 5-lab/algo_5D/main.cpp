#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

vector<pair <int,string>> labels;
vector<string> commands;
int registers[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream InputFile("quack.in");
    ofstream OutputFile("quack.out");
    string command;
    string label;
    unsigned short x;
    int number, number2;
    int y;
    unsigned short a, b, res;
    int CommandNumber = 0;
    char c, ch;
    queue <int> myqueue;

    while (InputFile >> command) {
        commands.push_back(command);
        if (command[0] == ':') {
            label = command.substr(1);
            labels.emplace_back(CommandNumber, label);
        }
        CommandNumber++;
    }
    CommandNumber = 0;
    while (CommandNumber < commands.size()) {
        command = commands[CommandNumber];
        if (atoi(command.c_str()) == 0 && command != "0") {
            res = 0;
            if (command[0] == ':') {
                CommandNumber++;
                continue;
            }
            switch (command[0]) {
                case '+': {
                    a = myqueue.front();
                    myqueue.pop();
                    b = myqueue.front();
                    myqueue.pop();
                    res = a + b;
                    myqueue.push(res);
                }
                    break;

                case '-': {
                    a = myqueue.front();
                    myqueue.pop();
                    b = myqueue.front();
                    myqueue.pop();
                    res = a - b;
                    myqueue.push(res);
                }
                    break;

                case '*': {
                    a = myqueue.front();
                    myqueue.pop();
                    b = myqueue.front();
                    myqueue.pop();
                    res = a * b;
                    myqueue.push(res);
                }
                    break;

                case '/': {
                    a = myqueue.front();
                    myqueue.pop();
                    b = myqueue.front();
                    myqueue.pop();
                    res = a / b;
                    myqueue.push(res);
                }
                    break;

                case '%': {
                    a = myqueue.front();
                    myqueue.pop();
                    b = myqueue.front();
                    myqueue.pop();
                    res = a % b;
                    myqueue.push(res);
                }
                    break;

                case '>': {
                    c = command[1];
                    int i = c - 'a';
                    x = myqueue.front();
                    myqueue.pop();
                    registers[i] = x;
                }
                    break;

                case '<': {
                    c = command[1];
                    number = c - 'a';
                    x = registers[number];
                    myqueue.push(x);
                }
                    break;

                case 'P': {
                    if (command.length() > 1) {
                        c = command[1];
                        number = c - 'a';
                        OutputFile << registers[number] << "\n";
                    } else {
                        x = myqueue.front();
                        myqueue.pop();
                        OutputFile << x << "\n";
                    }
                }
                    break;
                case 'C': {
                    if (command.length() > 1) {
                        c = command[1];
                        number = c - 'a';
                        c = (char)abs(registers[number] % 256);
                        OutputFile << c;
                    } else {
                        x = myqueue.front();
                        myqueue.pop();
                        c = (char)abs(x % 256);
                        OutputFile << c;
                    }
                }
                    break;

                case 'J': {
                    label = command.substr(1);
                    for (auto & j : labels)
                        if (j.second == label) {
                            CommandNumber = j.first;
                            break;
                        }
                }
                    break;

                case 'Z': {
                    c = command[1];
                    number = c - 'a';
                    if (registers[number] == 0) {
                        label = command.substr(2);
                        for (auto & j : labels)
                            if (j.second == label)
                            {
                                CommandNumber = j.first;
                                break;
                            }
                    }
                }
                    break;

                case 'E': {
                    c = command[1];
                    ch = command[2];
                    number = c - 'a';
                    number2 = ch - 'a';
                    if (registers[number] == registers[number2]) {
                        label = command.substr(3);
                        for (auto & j : labels)
                            if (j.second == label)
                            {
                                CommandNumber = j.first;
                                break;
                            }
                    }
                }
                    break;

                case 'G': {
                    c = command[1];
                    ch = command[2];
                    number = c - 'a';
                    number2 = ch - 'a';
                    if (registers[number] > registers[number2])
                    {
                        label = command.substr(3);
                        for (auto & j : labels)
                            if (j.second == label)
                            {
                                CommandNumber = j.first;
                                break;
                            }
                    }
                }
                    break;
                case 'Q': {
                    return 0;
                }
                default: break;
            }
        }
        else
            myqueue.push(atoi(command.c_str()));
        CommandNumber++;
    }
    return 0;
}