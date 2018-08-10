#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	     int n,k;
	     cin>>n>>k;
	     int a[n];
	     for (int i=0;i<n;i++)
	            cin>>a[i];
	   deque<int> indexes;
	   int i=0;
	   for (i=0;i<k;i++)
	   {
	       //removing from back irrelevant elements (indices)
	       while (!indexes.empty() && a[i]>=a[indexes.back()])
	                indexes.pop_back();
	       indexes.push_back(i);
	   }
	   for (;i<n;i++)
	   {
	       //max at front of the dequeue always
	       cout<<a[indexes.front()]<<" ";
	       
	       //handling those which are out of window now
	       while (!indexes.empty() && indexes.front()<=i-k) //comparison of indices
	            indexes.pop_front();
	       //handling smaller (irrelevant numbers)
	        while (!indexes.empty() && a[i]>=a[indexes.back()]) //comparison of values
	                indexes.pop_back();
	       
	       indexes.push_back(i);         
	       
	   }
	    cout<<a[indexes.front()]<<endl;
	}
	return 0;
}
