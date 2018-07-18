#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,x,k;
        cin>>n>>m>>x>>k;
        string s;
        cin>>s;
        ll e=0,o=0;
        ll a=s.length();
        for(int i=0; i<a; i++)
        {
            if(s[i]=='E')
                e++;
            else
                o++;
        }
        for(int i=1; i<=m; i++)
        {
            if(i%2==0)
            {
                if(e>x)
                {
                    n=n-x;
                    e=e-x;
                }
                else
                {
                    n=n-e;
                    e=0;
                }
            }
            else
            {
                if(o>x)
                {
                    n=n-x;
                    o=o-x;
                }
                else
                {
                    n=n-o;
                    o=0;
                }
            }
        }
        if(n<=0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
