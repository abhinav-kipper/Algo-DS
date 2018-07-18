#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
ll a[1000000]={0};
ll latestnonconflict(vector<pair<ll,pair<ll,ll> > > &v,int start,int end,ll k)
{

    while (start<=end){
         int mid=(start+end)/2;
    if(v[mid].second.first<=k)
    {
        if (v[mid+1].second.first<=k)
            start=mid+1;
        else return v[mid].second.second;
    }

    else
        end=mid-1;
    }


}
bool compare (pair<ll,pair<ll,ll> > &p,pair<ll,pair<ll,ll> > &q)
{
    return p.second.first<q.second.first;
}

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,pair<ll,ll> > > v;
    ll s,f,p;
    for (int i=0;i<n;i++)
    {
        cin>>s>>f>>p;
        v.push_back(mp(s,mp(f,p)));
    }
    sort(v.begin(),v.end(),compare);
   //for  (int i=0;i<n;i++)
     //   cout<<v[i].first<<" ";


        a[0]=v[0].second.second;
    int i=0;
    int exc,inc;
    for (int i=1;i<n;i++)
    {
        exc=a[i-1];
        inc=v[i].second.second+latestnonconflict(v,0,i-1,v[i].first);
        a[i]=max(inc,exc);
    }
    cout<<a[n-1]<<endl;
    return 0;
}
