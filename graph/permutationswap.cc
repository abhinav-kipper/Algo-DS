#include<bits/stdc++.h>
using namespace std;
vector<set<long long > > components(10005);
long long k=0;
void dfs(vector<long long > * edges ,long long start,set<long long> &a,bool * visited)
{
    visited[start]=true;
    a.insert(start);
    for (long long i=0;i<edges[start].size();i++)
    {
        long long next=edges[start][i];
        if (!visited[next])
            dfs(edges,next,a,visited);
    }
}
void  getComponents(vector<long long > * edges, long long n)
{
    bool * visited=new bool[n];
    for (long long  i=1;i<=n;i++)
        visited[i]=false;
    for (long long  i=1;i<=n;i++)
    {
            if (!visited[i])
                dfs(edges,i,components[k++],visited);
    }
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        components.resize(10001);
        long long n,m,x,y;
        cin>>n>>m;
        vector<long long> p(n+1),q(n+1);
        for (long long  i=1;i<=n;i++)
            cin>>p[i];

        for (long long i=1;i<=n;i++)
            cin>>q[i];

        vector<long long>edges[10010];

        for (long long i=1;i<=m;i++)
        {
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        getComponents(edges,n);
        set<long long  > :: iterator it;
        set<long long >a ;
        set<long long > b;
        long long flag=0;
        for (long long i=0;i<k;i++)
        {
            for (it=components[i].begin();it!=components[i].end();it++)
                   {
                    a.insert(p[*it]);
                    b.insert(q[*it]);
                   }
                   if (a!=b)
                   {
                        flag=1;
                        break;
                   }
                   a.clear();
                   b.clear();
                   // cout<<*it<<" ";
                      //      cout<<endl;
                }

            if (flag==1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        k=0;
        components.clear();
    }
}
