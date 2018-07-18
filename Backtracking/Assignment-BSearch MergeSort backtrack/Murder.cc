#include<bits/stdc++.h>
using namespace std;
int s;
int merge(int a[],int si,int ei)
{
    int mid=si+(ei-si)/2;
    int left=si,leftend=mid,right=mid+1,rightend=ei,k=0;
    int temp[ei-si+1],sum=0;
    while(left<=leftend && right<=rightend){
        if (a[left]<a[right]){
                sum+=a[left]*(rightend+1-right);
            temp[k++]=a[left++];
        }
        else  temp[k++]=a[right++];
    }
    while(left<=leftend) temp[k++]=a[left++];
    while(right<=rightend) temp[k++]=a[right++];

    for (int  i=0;i<k;i++)
        a[si++]=temp[i];
    return sum;
}
int mergesort(int a[],int si,int ei)
{
     if  (si>=ei) return 0;
    int mid=si+(ei-si)/2;
    mergesort(a,si,mid);
    mergesort(a,mid+1,ei);
    s+=merge(a,si,ei);
    return s;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++)
            cin>>a[i];
            s=0;
        int sum=mergesort(a,0,n-1);
        cout<<sum;

        sum=0;
    }
}
