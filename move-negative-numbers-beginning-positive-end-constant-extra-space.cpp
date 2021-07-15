#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

void rearrange(int *arr,int n){
  int low=0,high=n-1;
  while(low<=high){
    if(arr[low]>=0){
      swap(arr[low],arr[high]);
      high--;
      low--;
    }
    low++;
  }
}

void rearrange1(int *arr,int n){
  int i=0,j=0;
  for(;i<n;i++){
    if(arr[i]<0){
      if(i!=j)
        swap(arr[i],arr[j]);
      j++;
    }
  }
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
  int n = sizeof(arr) / sizeof(arr[0]);
    // rearrange(arr, n);
    rearrange1(arr, n);

  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;
}