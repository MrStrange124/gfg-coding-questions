// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    Node *ans = NULL, *p = NULL;
    while (head1 && head2)
    {
        if (head1->data == head2->data)
        {
            if (!p)
            {
                ans = new Node(head2->data);
                p = ans;
            }
            else
            {
                ans->next = new Node(head2->data);
                ans = ans->next;
            }
            head2 = head2->next;
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
    }
    return p;
}