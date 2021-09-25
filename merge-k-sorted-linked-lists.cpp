// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
public:
    //Function to merge K sorted linked list.
    // Node *merge(Node *first, Node *second)
    // {
    //     Node *itr = first, *temp, *prev;
    //     while (itr != NULL && second != NULL)
    //     {
    //         prev = itr;
    //         if (itr->next != NULL && (itr->next)->data >= second->data)
    //         {
    //             temp = itr->next;
    //             itr->next = second;
    //             second = second->next;
    //             itr = itr->next;
    //             itr->next = temp;
    //         }
    //         else
    //             itr = itr->next;
    //     }
    //     if (second != NULL)
    //         prev->next = second;
    //     return first;
    // }
    Node *merge(Node *a, Node *b)
    {

        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        Node *result;

        if (a->data < b->data)
        {
            result = a;
            result->next = merge(a->next, b);
        }

        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
        result->next = NULL;
        return result;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        for (int i = K - 2; i >= 0; i--)
        {
            arr[i] = merge(arr[i], arr[i + 1]);
        }
        return arr[0];
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}
// } Driver Code Ends