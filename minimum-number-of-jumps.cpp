#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int minJumps(int *arr, int n){
        int i = 0,j,step=0,tmax=0,k,l;
        while(i<n-1){
          if(i+arr[i]>=n){
            break;
          }
          tmax=0;
          for(j=i+1,k=1;j<=i+arr[i];j++,k++){
            if(tmax<arr[j]+k&&arr[j]!=0){
              tmax=arr[j]+k;
              l=k;
            }
          }
          if(tmax==0)
            return -1;
          i+=l;
          step++;
        }
        return step;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int n = 10;
  int arr[]={2,3,1,1,2, 4, 2, 0, 1, 1};
  cout<<minJumps(arr,n);
return 0;
}