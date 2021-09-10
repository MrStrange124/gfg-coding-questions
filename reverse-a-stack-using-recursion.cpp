#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
stack<char> s;
void insert_at_bottom(char x)
{
    if (s.empty())
        s.push(x);
    else
    {
        int temp = s.top();
        s.pop();
        insert_at_bottom(x);
        s.push(temp);
    }
}
void reverse()
{
    if (s.size() > 0)
    {
        char x = s.top();
        s.pop();
        reverse();
        insert_at_bottom(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    s.push('1');
    s.push('2');
    s.push('3');
    insert_at_bottom('0');
    reverse();
    char ch[4];
    int i = 3;
    while (!s.empty())
    {
        ch[i--] = s.top();
        s.pop();
    }
    for (auto i : ch)
        cout << i << " ";
    return 0;
}