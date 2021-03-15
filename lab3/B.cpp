#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, b1, b2;
    cin >> n >> m >> k;
    vector<vector<int>> vec(n+2, vector<int>(m+2));
    for (int i = 0; i < k; i++) {
        cin >> b1 >> b2;
        vec[b1][b2] = -1;
        for (int j = b1-1; j <= b1+1; j++) {
            for (int g = b2-1; g <= b2+1; g++) {
                if ((j != b1) or (g != b2)) {
                    if (vec[j][g] == NULL) {vec[j][g] = 0;}
                    if (vec[j][g] != -1) {vec[j][g]+= 1;}
                }
            }
        }
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (vec[i][j] == NULL) {vec[i][j] = 0;}
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
