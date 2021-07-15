#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;
void rotate(int *arr,int n){
  int i=0,j=n-1;
  for(;i!=j;i++){
    swap(arr[i],arr[j]);
  }
}
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = {1, 2, 3, 4, 5}, i;
  int n = sizeof(arr) / sizeof(arr[0]);
  rotate(arr,n);
  for(i = 0; i<n ; i++)
    cout<<arr[i]<<" ";
return 0;
}