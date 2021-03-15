#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int b, N;
    queue<int> q1, q2, tmp;
    cin >> N;
    string a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a == "-")
        {
            cout << q1.front() << endl;
            q1.pop();
            if ((q1.size() + q2.size()) % 2 == 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            cin >> b;
            if (a == "+")
            {
                q2.push(b);
                if ((q1.size() + q2.size()) % 2 == 1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
            if (a == "*")
            {
                if ((q1.size() + q2.size()) % 2 == 0) {q1.push(b);}
                else
                {
                    tmp = q2;
                    while ( !q2.empty() ) {q2.pop();}
                    q2.push(b);
                    while ( !tmp.empty() )
                    {
                        q2.push(tmp.front());
                        tmp.pop();
                    }
                }
            }
        }
    }
    return 0;
}
