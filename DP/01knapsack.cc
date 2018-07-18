#include<iostream>
using  namespace std;


int knapsack(int wts[],int prices[],int N,int W){
    ///Base Case
    if(N==0||W==0){
        return 0;
    }

    ///Rec Case
    int inc= 0,exc=0;
    if(wts[N-1]<=W){
        inc = prices[N-1] + knapsack(wts,prices,N-1,W- wts[N-1]);
    }

    exc = knapsack(wts,prices,N-1,W);

    return max(inc,exc);
}
//bottom up
int knapsack2(int wts[],int price[],int N,int W)
{
    int dp2[100][100];

    for (int n=0;n<=N;n++)
    {
    for (int w=0;w<=W;w++)
        {

            if (n==0||w==0) dp2[n][w]=0; //base

            else{
                    int inc=0,exec=0;
                    if(wts[n-1]<=w)
                        inc=dp2[n-1][w-wts[n-1]]+price[n-1];

                    exec=dp2[n-1][w];


                    dp2[n][w]=max(inc,exec);
            }

        }}

return dp2[N][W];
}



main()
{
    int wts[]={1,2,4,5}; //Weight of corresponding article
    int price[]={5,4,8,6}; //Price of corresponding article
    int dp[100][100]={0};
    int N=4; //noOfarticles
    int W=5; //bagsize
    int dp2[100][100]={0};
   cout<<knapsack(wts,price,N,W)<<endl; //recursive
    cout<<knapsack2(wts,price,N,W); //dp

}
