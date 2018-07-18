#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        int key=a[i],j=i-1;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int a[100];
    for (int i=0;i<10;i++)
        cin>>a[i];
    insertionsort(a,10);
    cout<<endl;
    for (int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
