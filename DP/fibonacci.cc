#include<iostream>
using namespace std;

int  fib(int n)
{
    if (n==0||n==1)
        return n;
    return fib(n-1)+fib(n-2);
}

//TopDown Dp Recursion +Memoization
int topDownDp(int n,int *dp){
    if (n==0||n==1){
        dp[n]=n;

        return n;
    }
    //Already computed
    if (dp[n]!=-1)
        return dp[n];
    return dp[n]=topDownDp(n-1,dp)+topDownDp(n-2,dp);

}

// Bottom Up Approach BIg o of N
int fibBottomUp(int n)
{
    int *dp=new int[n];
    dp[0]=0;
    dp[1]=1;

    for (int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fibOpt(int n)
{
    int a=0,b=1;
    int c;
    for (int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    cout<<fib(5)<<endl;

    int dp[100];
    for (int i=0;i<100;i++)
        dp[i]=-1;
    cout<<topDownDp(5,dp)<<endl;

     cout<<fibBottomUp(5)<<endl;
     cout<<fibOpt(5)<<endl;
}
