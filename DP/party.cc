#include <bits/stdc++.h>
#define ll long long
using namespace std;
int knapsack(vector<int> fees,vector<int> fun,ll budget,ll n ,int dp[501][101])
{
    int  inc,exc;
    if (n==0|| budget==0) return dp[budget][n]=0;
    if  (dp[budget][n]!=-1&&dp[budget][n]!=0) return dp[budget][n];
     if (budget>=fees[n-1]){
             inc=fun[n-1]+knapsack(fees,fun,budget-fees[n-1],n-1,dp);
        }
    else
        inc=INT_MIN;
      exc=knapsack(fees,fun,budget,n-1,dp);
      cout<<inc<<" "<<exc<<endl;
       return dp[budget][n]=max(inc,exc);
}

int main()
{
  ll b=1,n=1;
  while(b !=0 && n!=0)
  {
    vector<int> fees,fun;
    cin>>b>>n;
    ll x,y;
    for (ll i=0;i<n;i++)
    {
      cin>>x>>y;
      fees.push_back(x);
      fun.push_back(y);
    }
    int dp[501][101];
     for (int i=0;i<=b;i++)
    {
        dp[i][0]=0;

    }
    for (int i=0;i<=n;i++)
    {
        dp[0][i]=0;

    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=n;j++)
            dp[i][j]=-1;
    }
    cout<<knapsack(fees,fun,b,n,dp)<<endl;
 for (int i=0;i<=b;i++)
    {
         for (int  j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
    }

  }
    return 0;
}
