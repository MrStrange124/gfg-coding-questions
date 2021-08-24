// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findNum(int n)
    {
        int high = n * 5, low = 5, ans = 0, temp, temp2;
        while (high >= low)
        {
            int mid = (high + low) / 2;
            temp = mid = mid - mid % 5;
            while (mid > 0)
            {
                mid /= 5;
                ans += mid;
            }
            if (ans == n)
                return temp;
            if (ans > n)
            {
                temp2 = temp;
                high = temp - 5;
            }
            else
                low = temp + 5;
            ans = 0;
        }
        return temp2;
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
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends