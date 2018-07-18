#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
using namespace std;
int topDown(int *arr,int n,int * dp)
{
  		if (n<=0)
          return 0;
  		if (dp[n-1]!=-1)
          	return dp[n-1];
  		int inc=arr[n-1]+topDown(arr,n-2,dp); //taking last element
  		int  exc=topDown(arr,n-1,dp);
  		return dp[n-1]=max(inc,exc);
}
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main().
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */
  		int * dp=new int [n];
  		for (int i=0;i<n;i++)
          	dp[i]=-1;
  		int ans= topDown(arr,n,dp);
  		for (int i=0;i<n;i++)
            cout<<" "<<dp[i];
        cout<<endl;
  		return ans;


}
int main()
{
    int a[]={5,9,6,3};
    cout<<getMaxMoney(a,4);
}
