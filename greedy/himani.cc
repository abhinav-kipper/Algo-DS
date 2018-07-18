#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
  	int n;
  cin>>n;
  ull m,two=pow(2,32);
  cin>>m;
  ull a,b;
  cin>>a>>b;
  vector<ull> arr;
  vector<int> c;
  arr.resize(n);
  c.resize(n);
  arr[0]=0;
  for  (int i=1;i<n;i++)
  {
    arr[i]=((arr[i-1]% m)*a +b)% two;
    c[i]=arr[i]/(pow(2,8));
    //cout<<c[i]<<endl;
  }
  int sell=0,buy=1,profit=0;
  for  (int  i=0;i<n-1;i++)
  {
    if (buy==1)
    {
      //buy here
      while (c[i]>c[i+1] && i!=n-1)
      {
        i++;
      }
      profit=profit-c[i];
      buy=0;
      sell=1;
    }
    else if (sell==1)
    {
      //sell here
      while (c[i]<c[i+1] && i!=n-1)
      {
        i++;
      }
      profit=profit+c[i];
      sell=0;
      buy=1;
    }
  }
  cout<<profit;


    //Write your code here
    return 0;
}
