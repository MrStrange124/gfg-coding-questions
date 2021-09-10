#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
void printList(Node *pt)
{
    while (pt != NULL)
    {
        cout << pt->data << " ";
        pt = pt->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head, *second, *third;
    head = new Node;
    second = new Node;
    third = new Node;
    head->data = 5;
    head->next = second;
    second->data = 6;
    second->next = third;
    third->data = 7;
    printList(head);
    return 0;
}