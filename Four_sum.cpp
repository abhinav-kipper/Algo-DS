//geeks auxiliary array approach
#include <bits/stdc++.h>
using namespace std;
class Twosum
{
  public: 
        int first; int second; int sum;
};
bool no_common ( Twosum a,Twosum b)
{
    if (a.first==b.first || a.first==b.second || a.second==b.first || a.second==b.second)
            return false;
    return true;
}
int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	     int n;
	     cin>>n;
	     int a[n];
	     for (int i=0;i<n;i++)
	          cin>>a[i];
	    int x;
	    cin>>x;
	    int  triplet_size=n*(n-1)/2;
	    Twosum triplet[triplet_size];
	    int tr_iterator=0;
	    for (int i=0;i<n-1;i++)
	    {
	        for (int j=i+1;j<n;j++)
	        {
	            triplet[tr_iterator].sum=a[i]+a[j];
	            triplet[tr_iterator].first=i;
	            triplet[tr_iterator].second=j;
	            tr_iterator++;
	        }
	    }
	    //stored two_sums
	    bool flag=0;
	    for (int i=0;i<triplet_size-1;i++)
	    {
	        for (int j=i+1;j<triplet_size;j++)
	        {
	            if (triplet[i].sum+triplet[j].sum==x && no_common(triplet[i],triplet[j]))
	            {
	                flag=1;
	               
	                break;
	            }
	        }
	    }
	    if (flag) cout<<true<<endl;
	    else cout<<false<<endl;
	    
	            
	            
	}
	return 0;
}
