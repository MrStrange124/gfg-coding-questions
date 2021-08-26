// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        int t;
        int ans = 0;
        y = y >> l - 1;
        for (int i = l; i <= r && y; i++)
        {
            if (y & 1)
            {
                t = 1;
                t <<= i - 1;
                ans |= t;
            }
            y >>= 1;
        }
        return x | ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        Solution ob;
        cout << ob.setSetBit(x, y, l, r) << "\n";
    }
    return 0;
} // } Driver Code Ends