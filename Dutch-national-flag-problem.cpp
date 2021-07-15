#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;
void sort012(int *arr,int n){
  int low=0,mid=0,high=n-1,i=0;
  while(mid<=high){
    if(arr[i]==0){
      swap(arr[i],arr[low]);
      low++;
      mid++;
    }
    else if(arr[i]==1){
      mid++;
    }
    else{
      swap(arr[i],arr[high]);
      high--;
      i--;
    }
    i++;
  }
}
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1, 2 };
  int n = sizeof(arr) / sizeof(arr[0]);
 
  sort012(arr, n);
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;
}