#include <iostream>

using namespace std;

int main()
{
    int n, b = 0, s = 0;
    cin >> n;
    int* m = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        b += m[i];
    }
    b /= n;
    for (int i = 0; i < n; i++) {
        if (m[i] > b) {s += m[i];}
    }
    delete[]m;
    cout << s << endl;
    return 0;
}
