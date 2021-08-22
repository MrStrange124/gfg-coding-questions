// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        vector<int> pos;
        for (int i = 0; i < S.length(); i++)
            if (S[i] == '[')
                pos.push_back(i);
        int count = 0;
        int p = 0;
        int sum = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '[')
            {
                p++;
                count++;
            }
            else
                count--;
            if (count < 0)
            {
                sum += pos[p] - i;
                swap(S[i], S[pos[p]]);
                ++p;
                count = 1;
            }
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
} // } Driver Code Ends