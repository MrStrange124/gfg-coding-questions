#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> temp{3, 5};
  // vector<vector<int>> v1;
  // v1.push_back({1, 2});
  cout << temp.front();
  temp.pop_back();
  cout << temp.empty();
  return 0;
}