#include<iostream>
using namespace std;
int lcs(char *X,char *Y,int xlen,int ylen)
{
    int m=xlen,n=ylen;
    int LCS[m+1][n+1];


    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (i==0|| j==0)
                LCS[i][j]=0;
            else if (X[i-1]==Y[j-1]) //imp
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    return LCS[m][n];
}

int  main()
{
cout<<lcs("abdce","afbrdcte",5,8);
}
