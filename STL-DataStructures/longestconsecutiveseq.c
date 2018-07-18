#include<bits/stdc++.h>
using  namespace std;
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
  unordered_set<int> s;
  int ans=0;
  for (int i=0;i<n;i++)
    s.insert(arr[i]);
  int l=0;
  for (int i=0;i<n;i++)
  {
    if (s.find(arr[i]-1)==s.end())
    {
      int j=arr[i];
      while(s.find(j)!=s.end())
      {
        j++;
		}
      if (ans<j-arr[i]){
        ans=j-arr[i];
        l=arr[i];

      }


    }
  }
  vector<int>  v;
  for (int i=l;i<ans;i++)
  {
    v.push_back(i);
  }
	return v;


}
