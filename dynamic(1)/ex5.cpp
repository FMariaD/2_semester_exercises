#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> replace_matrix (vector<vector<int>> a, int y) {
    a.erase(a.begin());
    for (int i = 0; i < a.size(); i++)
    {
        a[i].erase(a[i].begin() + y);
    }
    return a;
}

int determinant(vector<vector<int>> a)  {
    if (a.size() == 1) {return a[0][0];}
    if (a.size() == 2) {return a[0][0] * a[1][1] - a[0][1] * a[1][0];}
    int det = 0;
    for (int i = 0; i < a.size(); i++)
    {
        det += (i % 2 == 0 ? 1 : -1) * a[0][i] * determinant(replace_matrix(a, i));
    }
    return det;
}


int main()

{
    int n, i, j;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    cout << determinant(m);
    return 0;
}
