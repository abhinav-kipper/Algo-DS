//geeks
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	     int n;
	     cin>>n;
	     int  dp[n][n];
	     memset(dp,-1,sizeof(dp));
	     int input[n][n];
	     for (int i=0;i<n;i++)
	     {
	         for ( int j=0;j<n;j++)
	         {
	             cin>>input[i][j];
	         }
	     }
	     for (int  i=0;i<n;i++)
	            dp[n-1][i]=input[n-1][i];
	   
	        for (int i=n-2;i>=0;i--)
	        {
	            for (int  j=n-1;j>=0;j--)
	            {
	                int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
	                    op1=dp[i+1][j];
	                if (j-1>=0)
	                    op2=dp[i+1][j-1];
	                if(j+1<n)
	                    op3=dp[i+1][j+1];
	                dp[i][j]=input[i][j]+max(op1,max(op2,op3));
	            }
	        }
	        int mx=INT_MIN;
	        for  (int i=0;i<n;i++)
	                mx=max(mx,dp[0][i]);
	        cout<<mx<<endl;
	}
	return 0;
}
