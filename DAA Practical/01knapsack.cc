#include<iostream>
using namespace std;

int knapsack(int wts[],int price[],int N,int W)
{
    int dp[100][100];
    int inc=0,exc=0;
    for (int n=0;n<=N;n++)
    {
        for (int w=0;w<=W;w++)
        {
            if (n==0||w==0)
                dp[n][w]=0;

            else {


                if (wts[n-1]<=w)
                    inc=price[n-1]+dp[n-1][w-wts[n-1]];
                exc=dp[n-1][w];
                dp[n][w]=max(inc,exc);
            }
        }
    }
    return dp[N][W];
}

int main()
{
    int wts[]={2,7,3,4};
    int price[]={5,20,20,10};
    int N=4;
    int W=11;
    cout<<knapsack(wts,price,N,W);
    return 0;
}
