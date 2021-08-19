// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *a = new int[2];
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                a[0] = abs(arr[i]);
        }
        for (int i = 0; i < n; i++)
            if (arr[i] > 0)
                a[1] = i + 1;
        return a;
    }
    int *findTwoElement2(int *arr, int n)
    {
        int *a = new int[2];
        int x = 0, y = 0;
        int xor1;

        /* Will have only single set bit of xor1 */
        int set_bit_no;

        int i;

        xor1 = arr[0];

        /* Get the xor of all array elements */
        for (i = 1; i < n; i++)
            xor1 = xor1 ^ arr[i];

        for (i = 1; i <= n; i++)
            xor1 = xor1 ^ i;

        set_bit_no = xor1 & ~(xor1 - 1);
        for (i = 0; i < n; i++)
        {
            if (arr[i] & set_bit_no)
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
        for (i = 1; i <= n; i++)
        {
            if (i & set_bit_no)
                x = x ^ i;
            else
                y = y ^ i;
        }
        a[0] = x;
        a[1] = y;
        return a;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement2(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends