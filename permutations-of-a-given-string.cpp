// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        int n = 1, i = S.length() + 1, j;
        sort(S.begin(), S.end());
        string temp = S;
        reverse(temp.begin(), temp.end());
        vector<string> ans;
        ans.push_back(S);
        while (S != temp)
        {
            for (i = S.length() - 2; i >= 0; i--)
            {
                if (S[i] < S[i + 1])
                    break;
            }
            for (j = S.length() - 1; j >= 0; j--)
                if (S[i] < S[j])
                    break;
            swap(S[i], S[j]);
            auto it = S.begin();
            for (j = 0; j <= i; j++)
                it++;
            sort(it, S.end());
            ans.push_back(S);
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
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends