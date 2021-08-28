// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        cout << ch;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//return the address of the string
char *reverse(char *S, int len)
{
    int i = 0;
    stack<char> temp;
    for (i = 0; i < len; i++)
        temp.push(S[i]);
    i = 0;
    char *ch = new char[len + 1];
    while (!temp.empty())
    {
        ch[i++] = temp.top();
        temp.pop();
    }
    ch[len] = '\0';
    return ch;
}