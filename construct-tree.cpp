// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    int e;
    int find(int in[], int start, int end, int value)
    {
        for (int i = start; i <= end; i++)
        {
            if (in[i] == value)
                return i;
        }
        return -1;
    }
    Node *soln(int in[], int pre[], int start, int end)
    {
        static int i = 0;
        if (start > end || i == e)
            return NULL;
        Node *tnode = new Node(pre[i++]);
        if (start == end)
            return tnode;
        int j = find(in, start, end, tnode->data);
        tnode->left = soln(in, pre, start, j - 1);
        tnode->right = soln(in, pre, j + 1, end);
        return tnode;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        e = n;
        return soln(in, pre, 0, n);
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

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends