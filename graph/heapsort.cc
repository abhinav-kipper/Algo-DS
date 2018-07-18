#include<bits/stdc++.h>
#define MAX 100000
#define swap(a,b,c) ((c)=(a),(a)=(b),(b)=(c))
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest=i,temp;
    int leftChild=(2*i+1);
    int rightChild=(2*i+2);



    if (arr[largest]<arr[leftChild] && leftChild<n)
        largest=leftChild;
    if (arr[largest]<arr[rightChild] && rightChild<n)
        largest=rightChild;
    if(largest!=i)
    {
        swap(arr[i],arr[largest],temp);
        heapify(arr,n,largest);
    }
}
void build_heap (int arr[],int n)
{
 // 1. Heapify the given array ...Build the max heap by rearranging the elements
        for (int i=(n-1)/2;i>=0;i--)
        {   //cout<<arr[i]<<"         :"<<endl;
        heapify(arr,n,i);
        }
         for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}
void heapsort(int arr[],int n)
{
        int temp;
        //Taking the max element at the end of the heap ARRAY
        while (n>1)
        {
            swap(arr[0],arr[n-1],temp);
            n--;
            heapify(arr,n,0);

        }






}
main()
{
    int arr[MAX],n;
    cout<<"Enter number of elements:";
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Input is :"<<endl;
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    build_heap(arr,n);
    heapsort(arr,n);
    int size1=n;
    cout<<"Output is :"<<endl;
    for (int i=0;i<size1;i++)
        cout<<arr[i]<<" ";
}
