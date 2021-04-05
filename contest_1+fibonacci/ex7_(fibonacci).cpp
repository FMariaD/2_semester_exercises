#include <iostream>

using namespace std;

int main()
{
    int N=4000000, a=1, b=2, x;
    long s=0;
    while (b < N) {
        x = b;
        b = b + a;
        a = x;
        if (b % 2 == 0) {s += b;}
    }
    cout << s << endl;
    return 0;
}
