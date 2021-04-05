#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main()
{
    stack <int> steck;
    string line, out;
    char a, b, s;
    bool answer = true;
    int N;
    map <char, int> book;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        book[a] = i;
        book[b] = (-1) * i;
    }
    cin >> line;
    for (int i = 0; i < line.length(); i++) {
        s = line[i];
        if (book[s] > 0) {steck.push(book[s]);}
        else
        {
            if (steck.empty()) {answer = false; break;}
            if (steck.top() == (-1)*(book[s])) {steck.pop();}
            else {answer = false; break;}
        }
    }

    if (!steck.empty()) {answer = false;}
    out = answer ? "YES" : "NO";
    cout << out << endl;
    return 0;
}
