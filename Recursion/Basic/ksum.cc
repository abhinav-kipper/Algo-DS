#include<bits/stdc++.h>
using namespace std;
bool ksum_present( int a[],int n,int k,int sum)
{
	
	if (sum==k)
	{
		return true;
	}
	if (n==0) return false;
	
	int x=ksum_present( a+1,n-1,k,sum);
	
	sum+=a[0];
	
	int y=ksum_present (a+1,n-1,k,sum);
	return x|| y;
		
}
int ksum_minlength ( int a[], int n ,int k ,int sum , int len)
{
	if (sum==k)
	{
		return len;
	}
	if (n==0) return INT_MAX;
	 int x=ksum_minlength( a+1,n-1,k,sum,len);
	sum+=a[0];
	int y=ksum_minlength (a+1,n-1,k,sum,len+1);
	return min( x,y);
}
int main()
{ int a[]={1,5,4,1,1,2};
	cout<<ksum_present ( a,6,3,0);
	cout<<endl<<ksum_minlength ( a, 6 ,3 ,0,0);
 return 0;
}
