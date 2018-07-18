#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
if (a<b)
    {
        if (a<c) return a;
        return c;
    }
    else if (b<c) return b;
    return c;
}
//geeks for geeks video to understand
int convert(string x,string y)
{
    int m=x.length(),n=y.length();
    int dp[m+1][n+1];
    for (int  i=0;i<m+1;i++)
    {
        for (int j=0;j<n+1;j++){
                //base case
            if (i==0) dp[0][j]=j; //first string empty only operation  is to add
            else if (j==0) dp[i][0]=i; //second string empty

            //if last character match , ignore last character and recur for rest of the string
            else if (x[i-1]==y[j-1]){ //element i-1 is ith in dp as null in dp
                    dp[i][j]=dp[i-1][j-1] ;//copy prev  as no new operation needed prev best suffice
            }
            else dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
        return dp[m][n];
    }
}
main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int a=0;
        a=convert(s1,s2);
        cout<<a<<endl;
    }
}
