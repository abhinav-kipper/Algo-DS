#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void show(int a[])
{
    for (int i=0;i<10;i++)
        cout<<'\t'<<a[i];
}
main()
{
   int a[]={1,65,34,2,3,4,6,8,6,4,3,32,6457,3};
   sort(a,a+10);  //sort
   show(a);
   //search after sort
   if(binary_search(a,a+10,6457))
    cout<<"\nPRESENT";
   else cout<<"\nNOT PRESENT";
}
//nlogn
