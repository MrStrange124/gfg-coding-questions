#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int getDiff(int *arr,int n,int k){
  sort(arr,arr+n);
  int tmax,tmin,result=arr[n-1]-arr[0];
  int i=0;
  for(i=1;i<=n-1;i++){
    if(arr[i]>=k&&arr[n-1]>=k){
      tmax = max(arr[n-1]-k,arr[i-1]+k);
      if(arr[i]-k<0)
        continue;
      tmin = min(arr[0]+k,arr[i]-k);
      result=min(result,tmax-tmin);
    }
  }
  return result;

}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int k = 6;
  int n = 3;
  int arr[] = { 1, 15, 10 };
  cout<<getDiff(arr,n,k);
return 0;
}