#include <iostream>
#include <algorithm>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

void printUnion(int *arr1,int m,int *arr2,int n){
  int i=0,j=0,k=n+m;
  while(i<m&&j<n){
    if(arr1[i]>arr2[j]){
      cout<<arr2[j]<<" ";
      j++;
    }
    else if(arr1[i]<arr2[j]){
      cout<<arr1[i]<<" ";
      i++;
    }
    else{
      cout<<arr1[i]<<" ";
      i++;j++;k--;
    }
  }
  while(i<m){
    cout<<arr1[i++]<<" ";
  }
  while(j<n){
    cout<<arr2[j++]<<" ";
  }
}

void printIntersection(int *arr1,int m , int *arr2,int n){
  int i=0,j=0;
  while (i<m&&j<n)
  {
    if(arr1[i]>arr2[j])
      j++;
    else if(arr2[j]>arr1[i])
      i++;
    else{
      cout<<arr1[i]<<" ";
      i++;j++;
    }
  }
  
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr1[] = { 1, 2, 4, 5, 6 };
  int arr2[] = { 2, 3, 5, 7 };
 
  int m = sizeof(arr1) / sizeof(arr1[0]);
  int n = sizeof(arr2) / sizeof(arr2[0]);

  printUnion(arr1,m,arr2,n);
  cout<<endl;
  printIntersection(arr1,m,arr2,n);
  cout<<endl;
return 0;
}