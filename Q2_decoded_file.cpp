#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    stack<int> mult;
    stack<string> str;

    string num = "";
    string word = "";

    for (auto &x : s)
    {
        if (x >= 'a' && x <= 'z')
            word += x;
        else if (word.length())
        {
            str.push(word);
            word = "";
        }

        if (x >= '0' && x <= '9')
            num += x;
        else if (num.length())
        {
            mult.push(stoi(num));
            num = "";
        }

        if (x == ']')
        {
            string temp = str.top();
            str.pop();
            int k = mult.top();
            mult.pop();
            string nw = "";
            while (k--)
                nw += temp;
            if (!str.empty())
            {
                str.top() += nw;
            }
            else
            {
                str.push(nw);
            }
        }
    }

    string ans = str.top();

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
