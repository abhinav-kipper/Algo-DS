#include<bits/stdc++.h>
using namespace std;
void buildTree(int * arr,int * tree,int start,int end,int treeNode)
  {
    if (start==end)
    {
      tree[treeNode]=arr[start];
      return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
  }
void  uxy(int *arr,int * tree,int start,int end,int  treeNode,int indx,int  value)
{
  if (start==end)
  {
    arr[indx]=value;
    tree[treeNode]=value;
    return ;
  }
  int mid=(start+end)/2;
  if (indx<=mid)
    uxy(arr,tree,start,mid,treeNode,indx,value);
  else uxy(arr,tree,start,mid,treeNode,indx,value);
	tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int qlr(int * tree,int start,int end,int treeNode,int left,int right)
{
  //completely outside
  if (start>right && end<left)
    return 0;
  //completely inside
  if (start>=left && end<=right)
    return tree[treeNode];
  //partially inside
  int mid=(start+end)/2;
  int ans1=qlr(tree,start,mid,2*treeNode,left,right);
  int ans2=qlr(tree,mid+1,end,2*treeNode+1,left,right);
  return min(ans1,ans2);
}
int main() {

	// Write your code here
  int n,q,c,a1,b;
  cin>>n>>q;
  int a[n];
  for (int i=0;i<n;i++)
    cin>>a[i];
  int *tree=new int [4*n];

  buildTree(a,tree,0,n-1,1);
  for (int i=0;i<q;i++)
  {
   cin>>c>>a1>>b;
    if (c==q)
     cout<<qlr(tree,0,n-1,1,a1,b)<<endl;
    else  uxy(a,tree,0,n-1,1,a1,b);

  }
      //for (int i=1;i<=2*n;i++)
        //cout<<tree[i]<<" ";

}
