// arr - input array
// n - size of array
#include<bits/stdc++.h>
using namespace std;
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  sort(arr,arr+n);
  int minn=INT_MAX;
  for (int i=1;i<=n-1;i++)
  {

    minn=min(minn,abs(arr[i]-arr[i-1])) ;
  }
  return minn;


}

int main()
{
    int a[]={2,9,0,4,5};
    cout<<minAbsoluteDiff(a,5);
    return 0;
}
