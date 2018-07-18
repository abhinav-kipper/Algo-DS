#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool subsetSum(vector<int> a,ll sum,ll size)
{
  bool inc,exc;

  if (sum==0 && size==0) return 1;

  else if (sum==0) return 1;

  else if (size==0) return 0;

  if (sum-a[size-1]<0)
    return exc=subsetSum(a,sum,size-1);
  else { exc=subsetSum(a,sum,size-1);
  		inc=subsetSum(a,sum-a[size-1],size-1);
         return inc||exc;
       }


}
int main()
{
  ll n;
  vector<int> a;
  cin>>n;

  a.resize(n);

  for (int i=0;i<n;i++)
    cin>>a[i];

  ll k;
  cin>>k;
  bool t=subsetSum(a,k,n);
  if (t) cout<<"Yes";
  else cout<<"No";
    return 0;

}
