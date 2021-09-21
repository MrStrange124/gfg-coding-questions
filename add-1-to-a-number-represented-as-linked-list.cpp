// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *addOne(Node *head)
    {
        Node *it = head, *p = NULL, *ans = head;
        while (it)
        {
            if (it->data != 9)
                p = it;
            it = it->next;
        }
        if (p == NULL)
        {
            p = new Node(1);
            p->next = head;
            ans = p;
            p = head;
        }
        else
        {
            p->data = p->data + 1;
            p = p->next;
        }
        while (p)
        {
            p->data = 0;
            p = p->next;
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
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends