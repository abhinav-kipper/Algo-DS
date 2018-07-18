#include<iostream>
using namespace std;

//Recursion k=3 (Max possible jump)
int ways (int n)
{
    //Ground
    if (n==0)
        return 1;
    if (n<0) return 0; //eg or 2 calls will be 1  0 and -1 but for -1 doesnt make sense
    return ways(n-1)+ways(n-2)+ways(n-3);
}

int topDownDp (int n,int *dp)
{
    if (n==0)
        return dp[n]=1;
    if (n<0) return 0;
    if (dp[n]!=0)
        return dp[n];
    return dp[n]=topDownDp(n-1,dp)+topDownDp(n-2,dp)+topDownDp(n-3,dp);
}

int way2(int n,int k)
{
    if (n==0)
        return 1;
    if  (n<0) return 0;
    int ans=0;
    for (int j=1;j<=k;j++)
    {
         ans+=way2(n-j,k); //eg k=3 ;;;f(n)=f(n-1)+f(n-2)+f(n-3),,,1,2,3 are j
    }
    return ans;
}

//BottomUp
int wayBottomUp(int n)
{
 int *dp=new int[n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for (int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}


//Bottom UP for k  big oh n*k
int waysBU(int n,int k)
{
    int *dp=new int[n];
    dp[0]=1;
    for (int step=1;step<=n;step++)
    {
        dp[step]=0;

        for (int j=1;j<=k;j++)
        {
            if (step-j>=0)
                dp[step]+=dp[step-j];
        }
    }
    return dp[n];
}

//Bottom UP big oh n
int optimised(int n,int k)
{
    int *dp=new int[n];
    dp[0]=1;
    for (int step=1;step<=n;step++)
    {
        if (step-1-k>0)
        dp[step]=2*dp[step-1]-dp[step-1-k];

        else {dp[step]=0;
                for (int j=1;j<=k;j++){
                if(step-j>=0)
                dp[step]+=dp[step-j];
        }
    }
    }
    return dp[n];
}
main()
{
    cout<<ways(4)<<endl;
    int dp[100];
    for (int i=0;i<100;i++)
        dp[i]=0;
    cout<<topDownDp(4,dp)<<endl;
    cout<<way2(4,3)<<endl;
    cout<<wayBottomUp(4)<<endl;
    cout<<waysBU(4,3)<<endl;
    cout<<optimised(4,3)<<endl;
}
