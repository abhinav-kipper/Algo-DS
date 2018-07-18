#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int partition(int a[],int start,int end)
{
    int left=start;
    int right=end;
    int pivot=a[start];
    while(left<right){
        while (a[left]<=pivot)
            left++;
        while (a[right]>pivot)
            right--;
        if (left<right)
            swap(a[left],a[right]);
    }
    a[start]=a[right];
    a[right]=pivot;
    return right;
}
void quicksort(int a[],int start,int end)
{
    //base condition
    if (start>=end)
        return;
    int pivot=partition(a,start,end);
    quicksort(a,start,pivot-1);
    quicksort(a,pivot+1,end);
}

int main(){
    int a[100];
    for (int i=0;i<10;i++)
        cin>>a[i];
    quicksort(a,0,9);
    cout<<endl;
    for (int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
