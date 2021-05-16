#include<iostream>

using namespace std;

int main()

{
    int n, i;
    cin >> n;
    int m[n];
    m[0] = 1;
    for (i = 1; i <= n; i++)
    {
        m[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (i + 1 <= n ) {m[i+1] += m[i];}
        if (i + 2 <= n ) {m[i+2] += m[i];}
        if (i + 3 <= n ) {m[i+3] += m[i];}
    }
    cout << m[n] << endl;
    return 0;
}
