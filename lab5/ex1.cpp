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
        if (line[i] == ')')
        {
            if (steck.empty()) {answer = false; break;}
            else {steck.pop();}
        }
    }
    if (!steck.empty()) {answer = false;}
    out = answer ? "YES" : "NO";
    cout << out << endl;
    return 0;
}
