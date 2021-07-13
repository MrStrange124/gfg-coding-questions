#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

void reverseArray(int *arr,int n){
  for(int i=0, j=n-1;i<j;i++,j--)
    swap(arr[i],arr[j]);
}

void recursive(int *arr,int s,int e){
  if(s>=e)
    return;
  swap(arr[s],arr[e]);

  return recursive(arr,s+1,e-1);
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  // reverseArray(arr,n);
  recursive(arr,0,n-1);

  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
return 0;
}