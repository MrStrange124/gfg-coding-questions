// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node *head)
    {
        // Initialize current, previous and
        // next pointers
        struct Node *current = head;
        struct Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        return prev;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);
        int carry = 0, temp;
        Node *i1 = first, *i2 = second, *ans = NULL, *tp;
        while (i1 && i2)
        {
            temp = i1->data + i2->data + carry;
            carry = temp / 10;
            if (!ans)
            {
                ans = new Node(temp % 10);
                tp = ans;
            }
            else
            {
                tp->next = new Node(temp % 10);
                tp = tp->next;
            }
            i1 = i1->next;
            i2 = i2->next;
        }
        while (i1)
        {
            temp = i1->data + carry;
            carry = temp / 10;
            tp->next = new Node(temp % 10);
            i1 = i1->next;
            tp = tp->next;
        }
        while (i2)
        {
            temp = i2->data + carry;
            carry = temp / 10;
            tp->next = new Node(temp % 10);
            i2 = i2->next;
            tp = tp->next;
        }
        if (carry)
        {
            tp->next = new Node(carry);
        }
        ans = reverse(ans);
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
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends