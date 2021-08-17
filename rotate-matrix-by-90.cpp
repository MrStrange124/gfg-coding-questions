// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

#define N 4
void printMatrix(int arr[N][N]);
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[N][N])
{
    int b[N][N];
    // Traverse each cycle
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[j][N - i - 1] = a[i][j];
        }
    }
    printMatrix(b);
}
void rotate90Clockwise1(int a[N][N])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - 1 - i; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
void rotate90Clockwise2(int a[N][N])
{
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void rotate90Clockwise3(int a[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N / 2; j++)
            swap(a[i][j], a[i][N - 1 - j]);
}

// Function for print matrix
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driver code
int main()
{
    int arr[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate90Clockwise3(arr);
    printMatrix(arr);

    return 0;
}
