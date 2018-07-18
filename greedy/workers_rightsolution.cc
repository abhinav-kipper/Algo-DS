#include<bits/stdc++.h>
using namespace std;
#define ll long  long
#define mp make_pair
#define ft first
#define sc second

bool compare (pair<ll,pair<ll,ll> >&p1,pair<ll,pair<ll,ll> >&p2)
{
    if  (p1.ft==p2.ft)
    {
        if (p1.sc.ft==p2.sc.ft)
        {
           return p1.sc.sc<p2.sc.sc;
        }
         return p1.sc.ft>p2.sc.ft;
    }
    return p1.ft<p2.ft;
}
int main()
{
    vector<pair<ll,pair<ll,ll> > > v1;
    ll workers,d_unit;
    ll t,x,y,i;
    cin>>workers>>d_unit;
    for (i=0;i<workers;i++)
    {
        cin>>t>>x>>y;
        v1.push_back(mp(t,mp(y,x)));
    }
    sort(v1.begin(),v1.end(),compare);


    i=0;
    ll sec=v1[0].ft;
    ll cost=0;
    ll fast_worker_unit=0; //worker is not selected yet ( select that worker that will do work in minimum time)
    ll last_sec=0;
    while (i<workers)
    {
        d_unit-=((fast_worker_unit)*(v1[i].ft-last_sec));
        if (d_unit<=0)
            break;
        if (v1[i].sc.ft>fast_worker_unit) //better worker
        {
            fast_worker_unit=v1[i].sc.ft;
            cost+=v1[i].sc.sc;//pay first time
        }
        last_sec=v1[i].ft;
        i++;
    }
    cout<<cost<<endl;
    return 0;
}
