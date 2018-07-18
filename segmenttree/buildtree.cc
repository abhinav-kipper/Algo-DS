#include<bits/stdc++.h>
using namespace std;
//tree index 1 to n total 2n elements , child of parent at 2i and 2i+1
void buildTree(int * arr,int * tree,int start ,int end,int  treeNode)
{
    if (start==end)
    {
        //leaf
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];//sum of elements
}
void updateTree(int  * arr,int * tree,int start,int end,int treeNode,int indx,int value)
{
    if (start==end)
    {
        arr[indx]=value;
        tree[treeNode]=value;
        return;
    }
int    mid=(start+end)/2;
    if (indx<=mid)
    {
       updateTree(arr,tree,start,mid,2*treeNode,indx,value);
    }
    else{
       updateTree(arr,tree,mid+1,end,2*treeNode+1,indx,value);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int query(int * tree,int start,int end,int treeNode,int left,int right)
{
    //completely outside given range
    if (start>right || end<left){
        return 0;
    }
    //completely inside give range
    if (start>=left && end<=right){
        return tree[treeNode];
    }
    //partially inside and partially outside
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}
int  main()
{
    int  arr[]={1,2,3,4,5};
    int  * tree=new int [10];
    buildTree(arr,tree,0,4,1);

    for  (int i=1;i<10;i++)
        cout<<tree[i]<< " ";
    updateTree(arr,tree,0,4,1,2,10);
    for  (int i=1;i<10;i++)
        cout<<endl<<tree[i]<< " ";

    int ans=query(tree,0,4,1,2,4);
    cout<<"Sum between interval 2 4 is:"<<ans;
}
