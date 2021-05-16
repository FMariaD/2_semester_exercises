#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check_is_true (vector<int> v, int ans) {
    if (v.size() == 0) {return false;}
    if (v.size() == 1)
    {
        if ((v[0] == ans) || (v[0] == (-1)*ans)) {return true;}
        return false;
    }
    int ans_new = v[v.size() - 1];
    v.pop_back();
    bool var1, var2;
    var1 = check_is_true(v, ans_new + ans);
    var2 = check_is_true(v, ans_new - ans);
    if (var1 || var2) {return true;}
    return false;
}

int main()

{
    int ans, i;
    cin >> ans;
    vector<int> v(0);
    string s, sub_s="";
    cin.sync();
    getline(cin, s);
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
    cout << (check_is_true(v, ans) ? "YES" : "NO");
    return 0;
}
