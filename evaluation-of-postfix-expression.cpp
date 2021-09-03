// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        int n = S.length(), a, b;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
                s.push(S[i] - '0');
            else
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if (S[i] == '/')
                    s.push(b/a);
                else if(S[i]=='*')
                    s.push(b*a);
                else if(S[i]=='-')
                    s.push(b-a);
                else 
                    s.push(a+b);
            }
        }
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}
// } Driver Code Ends