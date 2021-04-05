#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, i, j, m;
    cin >> N;
    m = N/2 + N%2;
    for (i = 0; i < m; i++) {
        for (j = 0; j < i; j++) {
            cout << " ";
        }
        for (j = 0; j < N-i-i; j++) {
            cout << "*";
        }
        for (j = 0; j < i; j++) {
            cout << " ";
        }
        if (i != m - 1) {cout << endl;}
    }
    return 0;
}
