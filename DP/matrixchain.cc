#include<bits/stdc++.h>
using namespace std;
int matrixMultiply(int *arr,int ** dp,int i,int j)
{
    if (i==j)
        return 0;
    if (dp[i][j]!=-1){
        cout<<"Overlapping Subproblem"<<endl;
    }
    int minCost=INT_MAX;
    for (int k=i;k<=j-1;k++)
    {
        int possibleAns=matrixMultiply(arr,dp,i,k)+matrixMultiply(arr,dp,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        minCost=min(minCost,possibleAns);

    }
    dp[i][j]=minCost;
    return minCost;
}
int main()
{
    int n;
    cin>>n;
    int * arr=new int [n];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int ** dp=new int *[n];
    for (int i=0;i<n;i++)
        dp[i]=new int[n];
    //memset cant be used coz dynamically allocacting no contagious
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<matrixMultiply(arr,dp,1,n-1);
    return 0;
}
