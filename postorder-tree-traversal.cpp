#include <bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform postorder traversal on the tree
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << " " << root->data;
}
void postorder2(Node *root)
{
    stack<Node *> s;
    s.push(root);
    stack<int> ans;
    Node *curr;
    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        ans.push(curr->data);
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
    while (!ans.empty())
    {
        cout << " " << ans.top();
        ans.pop();
    }
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    postorder2(root);

    return 0;
}