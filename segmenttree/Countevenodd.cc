#include<bits/stdc++.h>
#include<vector>
using namespace std;
class tree{
 public :int evensum;
  int oddsum;
  tree()
  {
      evensum=0;
      oddsum=0;
  }
};
void buildTree(vector<int> &arr, tree *t,int start,int  end, int treeNode)
{

  if (start==end)
  {
    //leaf
    if (arr[start]%2==0)
    t[treeNode].evensum++;

    else t[treeNode].oddsum++;

    return;
  }

  int mid=(start+end)/2;

  buildTree(arr,t,start,mid,2*treeNode);

  buildTree(arr,t,mid+1,end,2*treeNode+1);

  t[treeNode].evensum=t[2*treeNode].evensum+t[2*treeNode+1].evensum;
  t[treeNode].oddsum=t[2*treeNode].oddsum+t[2*treeNode+1].oddsum;
}
void update (vector<int>&arr,tree * t,int start,int end,int treeNode,int indx,int value)
{
  if (start==end)
  {
    arr[indx]=value;

    if (arr[indx]%2==0)
    {
         t[treeNode].evensum=1;
          t[treeNode].oddsum=0;

    }


    else {t[treeNode].oddsum=1;
        t[treeNode].evensum=0;
    }

    return;
  }
  int mid=(start+end)/2;
  if (indx<=mid)
    update(arr,t,start,mid,2*treeNode,indx,value);
  else update(arr,t,mid+1,end,2*treeNode+1,indx,value);

 t[treeNode].evensum=t[2*treeNode].evensum+t[2*treeNode+1].evensum;
  t[treeNode].oddsum=t[2*treeNode].oddsum+t[2*treeNode+1].oddsum;

}
int evencount(tree* t,int start,int end,int treeNode,int left,int right)
{
    //completely outside given range
    if (start>right || end<left){
        return 0;
    }
    //completely inside give range
    if (start>=left && end<=right){
        return t[treeNode].evensum;
    }
    //partially inside and partially outside
    int mid=(start+end)/2;
    int ans1=evencount(t,start,mid,2*treeNode,left,right);
    int ans2=evencount(t,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}
int oddcount(tree* t,int start,int end,int treeNode,int left,int right)
{
    //completely outside given range
    if (start>right || end<left){
        return 0;
    }
    //completely inside give range
    if (start>=left && end<=right){
        return t[treeNode].oddsum;
    }
    //partially inside and partially outside
    int mid=(start+end)/2;
    int ans1=oddcount(t,start,mid,2*treeNode,left,right);
    int ans2=oddcount(t,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}
int main() {

  int n,p,q,x;
  cin>>n;
  vector<int > a;

  for (int i=0;i<n;i++)
  {
    cin>>x;
    a.push_back(x);
  }
  tree t[4*n] ;
  buildTree(a,t,0,n-1,1); //tree index 1 to n



  for  (int i=1;i<=2*n;i++)
        cout<<t[i].evensum<< " "<<t[i].oddsum<<endl;
  cin>>q;
 while(q--)
  {
    int Q,x,y;
    cin>>Q>>x>>y;
    if (Q==0){
      update(a,t,0,n-1,1,x,y);
    }
    else if (Q==1){
     evencount(t,0,n-1,1,x-1,y-1);
    }
    else if  (q==2){
      oddcount(t,0,n-1,1,x-1,y-1);
    }
for (int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
     for  (int i=1;i<=2*n;i++)
        cout<<t[i].evensum<< " "<<t[i].oddsum<<endl;
  }

}
	// Write your code here
//}
