#include <iostream>
#include <vector>

using namespace std;

// сортирует v1 и v2 по v1, если по v1 совпадает, то по v2
void insert_sort(vector<int>& v1, vector<int>& v2) {
    int tmp, i, j, k;
    for (i = 1; i < v1.size(); i++)
    {
        k = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (v1[k] < v1[j])
            {
                tmp = v1[k];
                v1[k] = v1[j];
                v1[j] = tmp;
                tmp = v2[k];
                v2[k] = v2[j];
                v2[j] = tmp;
                k = j;
            }
            else
            {
                if ((v1[k] == v1[j])&&(v2[k] < v2[j]))
                {
                    tmp = v1[k];
                    v1[k] = v1[j];
                    v1[j] = tmp;
                    tmp = v2[k];
                    v2[k] = v2[j];
                    v2[j] = tmp;
                    k = j;
                }
                else
                {
                    break;
                }
            }
        }
    }

}

// функция определяет какое задание выгоднее сделать в последний день, рекурсивная
int delete_day(vector<int>& v1, vector<int>& v2) {
    if (v1.size() == 0) {return 0;}
    int ans=0, d, s=0, counter = 0, i;
    d = v1[v1.size() - 1];
    s = v2[v2.size()-1];
    v1.pop_back();
    v2.pop_back();
    while((v1[v1.size() - 1] == d)&&(v1.size() != 0))
    {
        v1.pop_back();
        counter += 1;
    }
    if (d-1 > 0)
    { for (i = 0; i < counter; i++) {v1.push_back(d-1);} }
    insert_sort(v1, v2);
    ans = s + delete_day(v1, v2);
    return ans;
}

int main()

{
    int n, i, j, a, b;
    cin >> n;
    vector<int> day(0), cost(0);
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        day.push_back(a);
        cost.push_back(b);
    }
    insert_sort(day, cost);
    cout << delete_day(day, cost);
    return 0;
}
