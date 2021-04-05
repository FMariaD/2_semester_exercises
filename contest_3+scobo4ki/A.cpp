#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <double> steck;
    double a;
    while (a != 0) {
        cin >> a;
        if (a == 0) {break;}
        if (a > 0) {steck.push(a);}
        else {
            if (steck.empty() == false) {
                if ((-1)*a < steck.top()) {steck.top() = steck.top() + a;}
                else {steck.pop();}
            }
        }
    }
    if (steck.empty()) {cout << "0 -1";}
    else {cout << steck.size() << " " << steck.top();}
    return 0;
}
