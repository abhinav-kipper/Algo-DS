//Generate all palindromic strings<=k formed using first n alphabets any number of times.
//code by ashok and approach by saqib kamal. Asked in PayU telephonic interview 1
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void palindrome(vector<char>& v,vector<char> &res,int i,int j)
	{
	    //cout<<res.size()<<" "<<i<<" "<<j<<endl;
	    //for(int le=0;le<v.size();le++) cout<<v[le];cout<<endl;
	    if(i>j)
	    {
	        for(int x=0;x<res.size();x++)
	        {
	            cout<<res[x];
	        }
	        cout<<endl;
	        //res.clear();
	        
	    }
	    else if(i==j)
	    {
	        for(int l=0;l<v.size();l++)
	        {
	            res[i]=v[l];
	       for(int x=0;x<res.size();x++)
	        {
	            cout<<res[x];
	        }
	        cout<<endl;
	        //res.clear();
	        }
	        
	    }
	    else
	    {
	        for(int l=0;l<v.size();l++)
	        {
	            res[i]=res[j]=v[l];
	            palindrome(v,res,i+1,j-1);
	           // cout<<res.size()<<" ygrfe"<<endl;
	        }
	    }
	    return;
	    
}

int main() {
	// your code goes here
	
	vector<char> v(3);
	v[0]='a';v[1]='b';v[2]='c';	
	int k=3;
	for(int l=1;l<=k;l++)
	{
	   vector<char> res(l);
	    int i=0,j=l-1;
	    //cout<<i<<" yo "<<j<<" "<<l<<endl;
	    palindrome(v,res,i,j);
	}

	return 0;
}
