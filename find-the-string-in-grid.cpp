// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> search(vector<vector<char>> &grid, string word, int i, int j)
    {
        int r = grid.size(), c = grid[0].size(), k = word.size(), a, b, d;
        int count = 0;
        vector<int> ans;
        for (a = j, d = 0; a < c && d < k; a++, d++)
        {
            if (word[d] != grid[i][a])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0; a < r && d < k; a++, d++)
        {
            if (word[d] != grid[a][j])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = j, d = 0; a >= 0 && d < k; a--, d++)
        {
            if (word[d] != grid[i][a])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0; a >= 0 && d < k; a--, d++)
        {
            if (word[d] != grid[a][j])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0, b = j; a < r && b < c && d < k; a++, d++, b++)
        {
            if (word[d] != grid[a][b])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0, b = j; a < r && b >= 0 && d < k; a++, d++, b--)
        {
            if (word[d] != grid[a][b])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0, b = j; a >= 0 && b >= 0 && d < k; a--, d++, b--)
        {
            if (word[d] != grid[a][b])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        for (a = i, d = 0, b = j; a >= 0 && b < c && d < k; a--, d++, b++)
        {
            if (word[d] != grid[a][b])
                break;
        }
        if (d == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        return ans;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        int r = grid.size(), c = grid[0].size(), count = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (word[0] == grid[i][j])
                {
                    vector<int> temp = search(grid, word, i, j);
                    if (temp.size())
                        ans.push_back(temp);
                }
            }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
} // } Driver Code Ends