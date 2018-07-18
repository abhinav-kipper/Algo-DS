#include<iostream>
using namespace std;

int merge(int input[],int si,int ei)
{
    int icount=0;
    int *temp=new int[ei-si+1];
    int mid=(si+ei)/2;
    int left=si,leftend=mid,right=mid+1,rightend=ei,k=0;
    while(left<=leftend && right<=rightend)
    {
        if (input[left]<=input[right])
        {
            temp[k++]=input[left++];
        }
        else {
                icount+=leftend+1-left;
            temp[k++]=input[right++];
        }
    }
    while(left<=leftend) temp[k++]=input[left++];
    while(right<=rightend) temp[k++]=input[right++];

    for (int i=0;i<k;i++)
        input[si++]=temp[i];

    return icount;


}

int mergesort(int input[],int si,int ei)
{
    static int icount=0;
    if (si>=ei) return 0;
    int mid=(si+ei)/2;
    mergesort(input,si,mid);
    mergesort(input,mid+1,ei);
    icount+=merge(input,si,ei);
    return icount;
}

main()
{
    int a[]={2,5,3,4,1,6,0};
    cout<<mergesort(a,0,7);
}
