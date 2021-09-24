// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    //Function to check whether the list is palindrome.
    void reverse(Node **head)
    {
        Node *current = *head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }
    bool isPalindrome(Node *head)
    {
        int i = 0;
        Node *it = head, *p1, *prev;
        while (it != NULL)
        {
            i++;
            it = it->next;
        }
        p1 = it = head;
        i = (i + 1) / 2;
        while (i--)
        {
            prev = it;
            it = it->next;
        }
        prev->next = NULL;
        reverse(&it);
        while (it && p1)
        {
            if (it->data != p1->data)
                return 0;
            it = it->next;
            p1 = p1->next;
        }
        return 1;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends