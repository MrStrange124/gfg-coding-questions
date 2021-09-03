#include <bits/stdc++.h>
#define ll long long
using namespace std;
class myStack
{
    int maxSize;
    int *stackArray;
    int top;

public:
    myStack(int s)
    {
        maxSize = s;
        stackArray = new int[s];
        top = -1;
    }
    void push(int x)
    {
        stackArray[++top] = x;
    }
    int pop()
    {
        if (top == -1)
            return top;
        return stackArray[top--];
    }
    int peek()
    {
        if (top == -1)
            return top;
        return stackArray[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return maxSize == top;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    myStack s(5);
    cout << s.isEmpty() << endl;
    s.push(1);
    cout << s.peek() << endl;
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    return 0;
}