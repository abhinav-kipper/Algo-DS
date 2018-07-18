#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long a[],long long candies,int n,long long k)
{
    int  kcount=0;
    for (int i=0;i<n;i++)
    {
        kcount+=(a[i]/candies);
    }
    if (kcount>=k)
        return true;
    return false;
}

main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        long long a[n];
        for (int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<long long>());
        long long start=1,totalcand=0;
        for (int i=0;i<n;i++)
            totalcand+=a[i];
        long long end=totalcand;
        long  long ans=0;
        while(start<=end){
                long long mid =start+ (end-start)/2;
                if (isPossible(a,mid,n,k)){
                        ans=mid;
                    start=mid+1;
                }
                else  end=mid-1;
        }
        cout<<ans<<endl;



    }
}
