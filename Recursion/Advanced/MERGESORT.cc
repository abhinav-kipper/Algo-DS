#include<iostream>
using namespace std;

void merge(int input[],int si,int ei)
{
  int temp[1001];
  int mid=(si+ei)/2;
  int l1=si,l2=mid+1,r1=mid,r2=ei,k=0;
  while (l1<=r1 && l2<=r2)
  {
    if (input[l1]<=input[l2])
    {
      temp[k++]=input[l1++];
    }
    else temp[k++]=input[l2++];
  }
  while (l1<=r1) temp[k++]=input[l1++];
  while (l2<=r2) temp[k++]=input[l2++];

  //INPLACE
  for (int i=0;i<k;i++)
  {
    input[si++]=temp[i];
  }
}


void mergesort(int input[],int si,int ei)
{
  if (si>=ei) return;
  int mid=(si+ei)/2;
  mergesort(input,si,mid);
  mergesort(input,mid+1,ei);
  merge(input,si,ei);
}
void mergeSort(int input[], int size){
	// base case
 	int si=0,ei=size-1;
 	mergesort(input,si,ei);
}
main()
{
    int a[]={1,4,32,5,3,2,11,2};
    mergeSort(a,8);
    for (int i=0;i<8;i++)
        cout<<a[i]<<" ";
}
