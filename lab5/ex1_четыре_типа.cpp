#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <int> steck;
    string line, out;
    getline(cin, line);
    bool answer = true;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '(') {steck.push(1);}
        if (line[i] == '{') {steck.push(2);}
        if (line[i] == '[') {steck.push(3);}
        if (line[i] == '<') {steck.push(4);}
        else
        {
            if (steck.empty()) {answer = false; break;}
            if (line[i] == ')')
            {
                if (steck.top() == 1) {steck.pop();}
                else {answer = false; break;}
            }
            if (line[i] == '}')
            {
                if (steck.top() == 2) {steck.pop();}
                else {answer = false; break;}
            }
            if (line[i] == ']')
            {
                if (steck.top() == 3) {steck.pop();}
                else {answer = false; break;}
            }
            if (line[i] == '>')
            {
                if (steck.top() == 4) {steck.pop();}
                else {answer = false; break;}
            }
        }
    }
    if (!steck.empty()) {answer = false;}
    out = answer ? "YES" : "NO";
    cout << out << endl;
    return 0;
}
