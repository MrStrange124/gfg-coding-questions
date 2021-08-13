// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        int mod = 1e9 + 7;
        long long temp = 1, temp2 = 2, ans;
        if (n < 3)
            return n;
        for (long long i = 3; i <= n; i++)
        {
            ans = (temp2 + ((i - 1) * temp) % mod) % mod;
            temp = temp2;
            temp2 = ans;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends