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

Pair MinMax(int *arr,int start,int end){
  Pair minmax ,mml,mmr;
  int mid;
  if(start==end){
    minmax.max=arr[start];
    minmax.min=arr[start];
    return minmax;
  }
  if(end==start+1){
    if(arr[start]>arr[end]){
      minmax.min=arr[end];
      minmax.max=arr[start];
    }
    else{
      minmax.max=arr[end];
      minmax.min=arr[start];
    }
    return minmax;
  }
  mid=(start+end)/2;
  mml=MinMax(arr,start,(mid-1));
  mmr=MinMax(arr,mid,end);
  
  minmax.max=mml.max>mmr.max?mml.max:mmr.max;
  minmax.min=mml.min<mmr.min?mml.min:mmr.min;

  return minmax;
}

Pair MinMax2(int *arr,int n){
  Pair minmax;
  if(n&1){
  minmax.max=arr[0];
  minmax.min=arr[0];
  }
  else{
    minmax.max=arr[0]>arr[1]?arr[0]:arr[1];
    minmax.min=arr[0]<arr[1]?arr[0]:arr[1];
  }
  int i=2;
  while(i<=n){
    if(arr[i]>arr[i+1]){
      if(arr[i]>minmax.max)
        minmax.max=arr[i];
      if(arr[i+1]<minmax.min)
        minmax.min=arr[i+1];
    }else{
      if(arr[i+1]>minmax.max)
        minmax.max=arr[i+1];
      if(arr[i]<minmax.min)
        minmax.min=arr[i];
    }
    i+=2;
  }
  return minmax;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = { 1000, 11, 445, 1, 330, 3000 };
  int n = sizeof(arr)/sizeof(arr[0]);
  
  // Pair minmax = getMinMax(arr,n);
  // Pair minmax = MinMax(arr,0,n-1);
  Pair minmax = MinMax2(arr,n-1);

  cout<<minmax.max<<" "<<minmax.min;
return 0;
}