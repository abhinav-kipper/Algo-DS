#include<iostream>
using namespace std;
void merge(int a[],int start,int end){
    int temp[100];
    int mid=(start+end)/2;
    int left=start,left_end=mid,right=mid+1,right_end=end,tempk=0;
    while (left<=left_end && right <=right_end) //copy
    {
        if (a[left]<=a[right])
            temp[tempk++]=a[left++];
        else temp[tempk++]=a[right++];
    }
    while (left<=left_end) //left left
        temp[tempk++]=a[left++];
    while(right<=right_end) //right left so copied
        temp[tempk++]=a[right++];


    //copying back to original
    for (int k=0;k<tempk;k++)
        a[start++]=temp[k];
}


void mergesort(int a[],int start,int end)
{
    if (end>start){
        int mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,end);
    }
}



int main(){
    int a[100];
    for (int i=0;i<10;i++)
        cin>>a[i];
    mergesort(a,0,9);
    cout<<endl;
    for (int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
