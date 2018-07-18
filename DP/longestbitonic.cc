#include<bits/stdc++.h>
using namespace std;
int bitonic(int *input,int n)
{
    cout<<"lis";
  int *lis=new int[n];
  int *lds=new int[n];

	//lis
  lis[0]=1;
  for (int i=0;i<n;i++){
    lis[i]=1; 		//atleast 1
    for (int j=i-1;j>=0;j--){
      if (input[j]>=input[i]){continue;
                            }
                            //cout<<"d";
      int possAnslis=lis[j]+1;
      if (possAnslis>lis[i])
        lis[i]=possAnslis;
    }
  }
  //cout<<"d";
    for (int i=0;i<n;i++)
        cout<<lis[i]<<" ";
  //lds
  lds[0]=1;
  for (int i=n-1;i>=0;i--){
    lds[i]=1;
    for (int j=n-1;j>i;j--){
      if (input[j]>=input[i]){
        continue;
      }
      int possAnslds=lds[j]+1;
      if (possAnslds>lds[i])
        lds[i]=possAnslds;
    }
  }
  cout<<"\nlds\n";
  for (int i=0;i<n;i++)
        cout<<lds[i]<<" ";

  //bitonic

  int bitonicbest=lis[0]+lds[0]-1;
  for (int i=1;i<n;i++){
    if (bitonicbest<lis[i]+lds[i]-1)
      bitonicbest=lis[i]+lds[i]-1;
  }
  delete [] lis;
  delete [] lds;
  return bitonicbest;
}
int main()
{
  int n;
  cin>>n;
  int *input=new int[n];
  for (int i=0;i<n;i++)
    cin>>input[i];

  int ans=bitonic(input,n);
  delete [] input;
  cout<<ans;
  return 0;
}
