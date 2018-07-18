#include<bits/stdc++.h>
using namespace std;
int firstIndex(int input[], int size1, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(size1==0)
  {
      return INT_MIN;
  }
  if(input[0]==x)
    return 0;
    int s=firstIndex(input+1,size1-1,x);
    if(s>0)
  return s+1;
  return -1;


}
main()
{
    int i[]={1,2,3,4,5,6,7,8,345,345,124,124,11};
    int s=13;
    int t=firstIndex(i,s,9);
    cout<<t;
}
