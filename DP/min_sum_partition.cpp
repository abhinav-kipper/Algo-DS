//geeks
#include <bits/stdc++.h>
using namespace std;
int mindiff(vector<int>&input,int n,int sumS1,int sumTotal, vector<vector<int> > &dp)
{
    if (n==0)
    {
        return dp[n][sumS1]=abs((sumTotal-sumS1)-sumS1);
    }
    if (dp[n][sumS1]!=-1) return dp[n][sumS1];
    return dp[n][sumS1]=min (mindiff(input,n-1,sumS1+input[n-1],sumTotal,dp),
                mindiff(input,n-1,sumS1,sumTotal,dp));
}
int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n;
	    cin>>n; 
	    vector<int > input(n);
	    int sumTotal=0;
	    for (int i=0;i<n;i++)
	    {
	        cin>>input[i];
	        sumTotal+=input[i];
	    }
	    vector<vector<int > > dp(n+1);
	    for (int i=0;i<=n;i++)
	    {
	        for (int j=0;j< sumTotal;j++)
	        {
	            dp[i].push_back(-1);
	        }
	    }
	    cout<<mindiff(input,n,0,sumTotal,dp)<<endl;
	}
	return 0;
}
