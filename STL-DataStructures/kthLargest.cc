#include<iostream>
using namespace std;
void swap (int &a,int &b)
{
  int temp=a;
  a=b;
  b=temp;
}
//Decreasing order
int  partition(int input[],int si,int ei)
{
  int  largeElements=0,pivot=input[si];


  //Counr no of elements smaller than pivot
  for (int i=si;i<=ei;i++)
  {
    if (pivot<input[i]) largeElements++;
  }

  //Position(key) of pivot is found
  int key=si+largeElements;
  swap(input[si],input[key]); //Place pivot correctly

  int i=si,j=ei;
  while (i!=key && j!=key){ //While any reaches pivot position
  if (input[i]>pivot) i++;
  else if (input[j]<=pivot) j--;
  else {
    swap(input[i++],input[j--]); //If  a[i] and a[j] both wrong swap
  }
  }
  return key;


}
int klargest(int a[],int si,int ei,int k)
{
    int pivotkey=partition(a,si,ei);
    if (pivotkey==k)
        return a[pivotkey];
    else if (pivotkey>k)
        partition(a,si,pivotkey-1);
    else partition(a,pivotkey+1,ei);

}
main()
{
    int  a[]={2,4,2,1,3,5,2,3};
    int r=klargest(a,0,7,4);
    cout<<r;
}
