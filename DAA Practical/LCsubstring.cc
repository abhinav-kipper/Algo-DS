#include<iostream>
using namespace std;
int lcs(char *X,char *Y,int xlen,int ylen)
{
    int m=xlen,n=ylen;
    int LCS[m+1][n+1];
    int result =0;

    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (i==0|| j==0)
                LCS[i][j]=0;
            else if (X[i-1]==Y[j-1]) //imp
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
                result=max(result,LCS[i][j]);
            }
            else
            {
                LCS[i][j]=0;
            }
        }
    }
    return result;
}

int  main()
{
cout<<lcs("abdce","afbrdcte",5,8);
}
