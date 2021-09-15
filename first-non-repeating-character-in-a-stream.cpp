// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        int arr[27] = {0};
        queue<char> st;
        string ans = "";
        for (int i = 0; i < A.length(); i++)
        {
            arr[A[i] - 'a']++;
            if (arr[A[i] - 'a'] == 1)
                st.push(A[i]);
            while (!st.empty())
            {
                if (arr[st.front() - 'a'] == 1)
                    break;
                st.pop();
            }
            if (st.empty())
                ans += '#';
            else
                ans += st.front();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends