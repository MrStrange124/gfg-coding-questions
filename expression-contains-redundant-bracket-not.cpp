#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
void findRedundant(string s)
{
    stack<char> st;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            flag = 1;
            while (st.top() != '(')
            {
                if (!flag || st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    flag = 0;
                st.pop();
            }
            st.pop();
        }
        else
            st.push(s[i]);
        if (flag)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);
    return 0;
}