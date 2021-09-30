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

// Recursive function to perform preorder traversal on the tree
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << " " << root->data;
    preorder(root->left);
    preorder(root->right);
}
void preorder2(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr)
    {
        if (curr)
        {
            cout << " " << curr->data;
            if (curr->right)
                s.push(curr->right);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
        }
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

    preorder2(root);

    return 0;
}
