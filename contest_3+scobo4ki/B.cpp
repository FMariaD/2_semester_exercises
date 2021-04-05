#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    stack <int> steck;
    string line;
    getline(cin, line);
    vector<string>v (line.length());
    int j = 0, s = 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ')
        {
            s++;
            if (s == 1) {j++;}
        }
        else {v[j].push_back(line[i]); s = 0;}
    }
    if (s > 0) {j -= 1;}
    int tmp;
    for (int i = 0; i <= j; i++) {
        if ((v[i] != "+") && (v[i] != "-") && (v[i] != "*") && (v[i] != "/")) {steck.push(stoi(v[i]));}
        else {
                tmp = steck.top();
                steck.pop();
                if (v[i] == "+") {tmp = steck.top() + tmp;}
                if (v[i] == "-") {tmp = steck.top() - tmp;}
                if (v[i] == "/") {tmp = steck.top() / tmp;}
                if (v[i] == "*") {tmp = steck.top() * tmp;}
                steck.pop();
                steck.push(tmp);
        }
    }
    cout << steck.top() << endl;
    return 0;
}
