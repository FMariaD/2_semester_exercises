#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()

{
    int n, i, x;
    vector<int> v(0);
    cin >> n;
    x = n;
    string s, sub_s="";
    cin.sync();
    getline(cin, s);
    v.push_back(0);
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ') {sub_s += s[i];}
        else if (sub_s != "")
        {
            v.push_back(stoi(sub_s));
            sub_s = "";
        }
    }
    if (sub_s != "") {v.push_back(stoi(sub_s));}
    sort (v.begin(), v.end());
    for (i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i-1] <= n) {x = v[i] + n;}
        else {break;}
    }
    cout << x << endl;
    return 0;
}
