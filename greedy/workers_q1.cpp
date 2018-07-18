#include<bits/stdc++.h>
using namespace std;
#define ll double
#define mp make_pair
#define ft first
#define sc second
int main()
{
    vector<pair<ll,pair<ll,ll> > >  v1;
    ll workers,d_unit;
    ll t,x,y,i;
    cin>>workers>>d_unit;
    for(i=0;i<workers;i++)
    {
        cin>>t>>x>>y;
        v1.push_back(mp(t,mp(x,y)));
    }
    sort(v1.begin(),v1.end());
    int sec=v1[0].ft;
    i=1;
    priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > > > pq1;
    priority_queue<pair<ll,pair<ll,ll> >,vector

    pq1.insert(mp(v1[0].sc.ft/v1[0].sc.sc,mp(v1[0].sc.ft,v1[0].sc.sc)));
    ll cost=0;
    while(d_unit!=0)
    {
        x=pq1.top().sc.ft;
        y=pq1.top().sc.sc;
        d_unit-=y;
        cost+=x;
        sec++;
        if(sec==v1[i].ft)
        {
            pq1.insert(mp(v1[i].sc.ft/v1[i].sc.sc,mp(v1[i].sc.ft,v1[i].sc.sc));
            i++;
        }
    }
    return 0;
}
