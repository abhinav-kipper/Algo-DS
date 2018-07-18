#include<bits/stdc++.h>
using  namespace std;
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
  set<int> s;
  int ans=0;
  for (int i=0;i<n;i++)
    s.insert(arr[i]);
  int l=0,r=0,old=0;
  for (int i=0;i<n;i++)
  {
    if (s.find(arr[i]-1)==s.end())
    {
      int j=arr[i];
      while(s.find(j)!=s.end())
      {

        j++;
		}
      if (ans<j-arr[i] || (ans==j-arr[i] && i<old)){
        r=j-1;
        l=arr[i];
        ans=r-l;
        old=i;

      }


        //cout<<l<<" "<<ans<<" ";
    }
    //cout<<arr[i]<<"-i  ";
    //cout<<endl;
  }
  vector<int>  v;
  if (ans==0)
  {
      v.push_back(arr[0]);
      return v;
  }
  for (int i=l;i<=r;i++)
  {
    v.push_back(i);
  }
	return v;


}
main()
{

    int a[]={3,4,5};
    vector <int> v=longestSubsequence(a,3);
    for (int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

}
