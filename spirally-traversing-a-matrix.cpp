// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;
        int i = 0, j = 0, dir = 0;
        int top = 0, bottom = r - 1, left = 0, right = c - 1;
        while (top <= bottom && left <= right)
        {
            //l->r
            if (dir == 0)
            {
                i = left;
                while (i <= right)
                    ans.push_back(matrix[top][i++]);
                top++;
            }
            //t->b
            else if (dir == 1)
            {
                i = top;
                while (i <= bottom)
                    ans.push_back(matrix[right][i++]);
                right--;
            }
            //r->l
            else if (dir == 2)
            {
                i = right;
                while (i >= left)
                    ans.push_back(matrix[bottom][i--]);
                bottom--;
            }
            //b->t
            else if (dir == 3)
            {
                i = bottom;
                while (i >= top)
                    ans.push_back(matrix[left][i--]);
                left++;
            }
            dir %= 4;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends