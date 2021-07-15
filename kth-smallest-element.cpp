#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
#define imax INT_MAX
#define imin INT_MIN
#define ll long long
using namespace std;

int KthSmallest(int *arr,int n ,int k){
  sort(arr,arr+n);
  return arr[k-1];
}

int KthSmallest1(int *arr,int n,int k){
  set<int> s1(arr,arr+n);
  set<int>::iterator itr = s1.begin();
  advance(itr,k-1);
  return *itr;
}

int KthSmallest2(int *arr, int n,int k){
  map<int,int> m;
  for(int i=0;i<n;i++){
    m[arr[i]]+=1;
  }
  int freq=0;
  for(auto i=m.begin();i!=m.end();i++){
    freq+=i->second;
    if(freq>=k)
      return i->first;
  }

  return -1;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[] = { 12, 3, 5, 7, 19 };
  int n = sizeof(arr) / sizeof(arr[0]), k = 3;
  // cout<<KthSmallest(arr,n,k);
  // cout<<KthSmallest1(arr,n,k);
  cout<<KthSmallest2(arr,n,k);
return 0;
}