#include<bits/stdc++.h>
using namespace std;

bool isPossible(int cows,long long a[],int n,long long distance ){
    int count=1;
    long long last_pos=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]-last_pos>=distance){
            last_pos=a[i];
            count++;
        }
        if (count==cows) return true;
    }
    return false;
}

/*int bsaggressiveCow(int c,long long a[],int n,long long l,long long r)
{
    static int ans=-1;
    if (l>r) return -1;
    int mid=l+(r+l)/2;
    if (isPossible(c,a,n,mid))
    {
        ans=mid;
        bsaggressiveCow(c,a,n,mid+1,r);
}

else bsaggressiveCow(c,a,n,0,mid-1);
    return ans;
    }*/


int main() {
	// Write your code here
  int  t;
  cin>>t;
  while (t--)
  {

    int n,c;
    cin>>n>>c;
    long long *a=new long long [n];
    for (int i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n);
    long long ans=-1;
    /*int s=bsaggressiveCow(c,a,n,0,a[n-1]-a[0]);
    cout<<s<<endl;*/

    long long start=0,end=a[n-1]-a[0];
    while(start<=end){
        long long mid =start+ (end-start)/2;
        if (isPossible(c,a,n,mid)){
            ans=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    cout<<ans<<endl;


}
}
