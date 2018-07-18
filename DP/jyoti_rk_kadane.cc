/*This code is a copyright of princess23*/
/*Write the name of the program*/
#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define pii pair<pi>
#define infile() freopen("large.in","r",stdin);
#define output() freopen("output.txt","w",stdout);
#define ll long long
#define sc1(t) cin>>t
#define sc2(n,m) cin>>n>>m
#define debug() cout<<"princess\n"
#define N 1005
#define mod 1000000007
#define printi(n) cout<<n
string s;
ll max(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
int main()
{
ios::sync_with_stdio(false);

cin.tie(NULL);
ll t,n;

cin>>t;

while(t--)
{
    ll max_1=0,cur_max=0,r_count=0,res;
	cin>>s;
    n=s.length();
    for (int i=0; i<n; i++)
    {
    	ll val=(s[i]=='k')? 1: -1;
        if (s[i] =='r')
        r_count++;
        cur_max = max(val,cur_max+val);
        max_1= max(max_1,cur_max);
        cout<<r_count<<" "<<cur_max<<" "<<max_1<<endl;
    }
    max_1=max(0,max_1);
    res=max_1+r_count;
    cout<<res<<endl;
}
return 0;
}
