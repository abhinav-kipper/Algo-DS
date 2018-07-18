#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int kthLargest (vector<int> arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int> p;
  for (int  i=0;i<arr.size();i++)
  {
    p.push(arr[i]);
  }
 for (int i=1;i<k;i++) p.pop();
  cout<<p.top();
}
main()
{
    vector<int> v;
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    int r;
    cin>>r;
    kthLargest(v,n,r);


}
