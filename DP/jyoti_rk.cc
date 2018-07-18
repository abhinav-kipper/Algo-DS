/*This code is a copyright of princess23*/
/*Write the name of the program*/
#include<bits/stdc++.h>
using namespace std ;
#define ll long long
string s;
ll count_rs(ll i,ll j,string p)
{
	ll count=0;
	for(ll k=i;k<=j;k++)
	{
		if(p[k]=='k')
			p[k]='r';
		else
			p[k]='k';
	}
	for(ll k=0;k<p.length();k++)
	if(p[k]=='r')
	count++;
	return count;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
ll t,n,arr[100009],i,j;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ll res=count_rs(0,-1,s);
		n=s.length();
		ll st_i=-1,en_i=-1;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				ll temp=count_rs(i,j,s);     //count no of r by reversing the subarray
				if(res<temp)
				{
					res=temp;
					st_i=i;
					en_i=j;
				}
			}
		}
		cout<<"reversal index "<<st_i<<" "<<en_i<<endl;
		cout<<res<<endl;
	}
return 0;
}
