// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int MAH(vector<int> arr)
    {
        int n = arr.size();
        int left[n], right[n], width[n];
        int i;
        stack<pair<int, int>> s;
        for (i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
            if (s.empty())
            {
                left[i] = -1;
                s.push({arr[i], i});
            }
            else if (s.top().first < arr[i])
            {
                left[i] = s.top().second;
                s.push({arr[i], i});
            }
        }
        while (!s.empty())
            s.pop();
        for (i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
            if (s.empty())
            {
                right[i] = n;
                s.push({arr[i], i});
            }
            else if (s.top().first < arr[i])
            {
                right[i] = s.top().second;
                s.push({arr[i], i});
            }
        }
        for (i = 0; i < n; i++)
            width[i] = right[i] - left[i] - 1;
        for (i = 0; i < n; i++)
            width[i] *= arr[i];
        return *max_element(width, width + n);
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        vector<int> v;
        for (int i = 0; i < m; i++)
            v.push_back(M[0][i]);
        int mx = MAH(v);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                    v[j] = 0;
                else
                    v[j] += M[i][j];
            }
            mx = max(mx, MAH(v));
        }
        return mx;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends