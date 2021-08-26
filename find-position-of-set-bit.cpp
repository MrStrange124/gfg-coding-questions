// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int n)
    {
        int count = 0, ans = 0;
        while (n)
        {
            ans++;
            if (count)
                break;
            if (n & 1)
                count++;
            n >>= 1;
            if (!n && count == 1)
                return ans;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends