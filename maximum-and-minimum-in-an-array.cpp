#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

struct Pair {
  ll max,min;
};

Pair getMinMax(int *arr,int n){
  Pair minmax;
  minmax.max=arr[0];
  minmax.min=arr[0];
  for(int i=1;i<n;i++){
    if(arr[i]>minmax.max)
      minmax.max=arr[i];
    else if(arr[i]<minmax.min)
      minmax.min=arr[i];
  }
  return minmax;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = { 1000, 11, 445, 1, 330, 3000 };
  int n = sizeof(arr)/sizeof(arr[0]);
  
  Pair minmax = getMinMax(arr,n);

  cout<<minmax.max<<" "<<minmax.min;
return 0;
}