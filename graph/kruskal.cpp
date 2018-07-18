#include<bits/stdc++.h>
using namespace std;
int disj[1000];
int find(int a)
{
	if(disj[a]==a)
	return a;
	else
	return find(disj[a]);
}
void unio(int x,int y)
{
	while(disj[x]!=x)
	{
		x=disj[x];
	}
	disj[x]=y;
}
int main()
{
	set<pair<int,pair<int,int> > > s;
	set<pair<int,pair<int,int> > >::iterator it;
	int v,e,i,x,y,d;
	cout<<"Enter number of vertices and edges: ";
	cin>>v>>e;
	for(i=1;i<=v;i++)
	{
		disj[i]=i;
	}
	cout<<"Edges :\n";
	for(i=0;i<e;i++)
	{
		cin>>d>>x>>y;
		s.insert(make_pair(d,make_pair(x,y)));
	}
	cout<<"Edges in minimun spanning tree: \n";
	for(it=s.begin();it!=s.end();it++)
	{
		x=it->second.first;
		y=it->second.second;
		if(find(x)!=find(y))
		{
			cout<<x<<" "<<y<<"\n";
			unio(x,y);	
		}		
	}
	for(i=1;i<=v;i++)
	{
		cout<<disj[i]<<" ";
	}
}
/*
5 6
1 2 1
1 3 3
2 4 8
3 4 2
4 5 3
3 5 6
*/
