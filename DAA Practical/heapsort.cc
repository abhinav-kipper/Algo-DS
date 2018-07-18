#include<iostream>
using namespace std;

void swap(int &a,int &b){
int temp=a;
a=b;
b=temp;
}

void  maxheapify(int a[],int heapsize,int i)
{
    int largest=i;
    int leftchild=(2*i+1);
    int rightchild=(2*i+2);

    if (a[largest]<a[leftchild] && leftchild<heapsize)
        largest=leftchild;
    if (a[largest]<a[rightchild] && rightchild<heapsize)
        largest=rightchild;

    if (largest!= i){
        swap(a[largest],a[i]);
        maxheapify(a,heapsize,largest);
    }
}

void build_heap(int a[],int heapsize)
{
    for (int i=(heapsize-1)/2;i>=0;i--){
        maxheapify(a,heapsize,i);
    }
}

void heapsort(int a[],int heapsize)
{
    build_heap(a,heapsize);
    for (int i=heapsize-1;i>0;i--) // downto 2 nd element
    {
        swap(a[0],a[i]);
        heapsize--;
        maxheapify(a,heapsize,0);
    }
}

int main()
{
    int a[100];
    for (int i=0;i<10;i++)
        cin>>a[i];
    heapsort(a,10);
    cout<<endl;
    for (int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
