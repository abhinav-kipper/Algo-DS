#include<bits/stdc++.h>
//Always take 3*n size as it can go to index 2n+1 or 2n+2 etc
using namespace std;
struct node{int maximum;
int smaximum;};
void buildtree(int * arr,node * tree,int treeIndex,int start,int end)
{
    if (start==end)
    {
        tree[treeIndex].maximum=arr[start];
        tree[treeIndex].smaximum=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,2*treeIndex,start,mid);
    buildtree(arr,tree,2*treeIndex+1,mid+1,end);

    node left=tree[2*treeIndex];
    node  right=tree[2*treeIndex+1];
    tree[treeIndex].maximum=max(left.maximum,right.maximum);
    tree[treeIndex].smaximum=min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
    return ;
}
node query(node * tree, int start,int end,int treeIndex,int left,int right )
{
    if (start>right || end<left)
        return ;
    if (start>=left && end<=right)
        return tree[treeIndex] ;
    int  mid=(start+end)/2;
    node ans1=query(tree,start,mid,2*treeIndex,left,right);
    node ans2=query(tree,mid+1,end,2*treeIndex+1,left,right);



}
void update(int * arr,node * tree,int start,int end,int treeIndex,int indx,int value)
{
    if (start==end)
    {
        arr[indx]=value;
        tree[treeIndex].maximum=arr[indx];
        return;
    }
    int mid=(start+end)/2;
    if (indx<=mid) update(arr,tree,start,mid,2*treeIndex,indx,value);
    else update (arr,tree,mid+1,end,2*treeIndex+1,indx,value);

    node left=tree[2*treeIndex];
    node  right=tree[2*treeIndex+1];
    tree[treeIndex].maximum=max(left.maximum,right.maximum);
    tree[treeIndex].smaximum=min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
}
int main()
{
    int n;
    cin>>n;
    int * arr=new int[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    node * tree=new node[3*n];
    buildtree(arr,tree,1,0,n-1);
    //for (int i=1;i<3*n;i++){
      //  cout<<tree[i].maximum<<" "<<tree[i].smaximum<<endl;
    //}
    int Q,a,b,c;
    cin>>Q;
    while(Q--)
    {
        cin>>a>>b>>c;
        if (a=='Q')
        {
            node  * ans=query(tree,0,n-1,1,--b,--c);
            cout<<ans.maximum+ans.smaximum<<endl;
        }
        else {
            update(arr,tree,0,n-1,1,--b,c);
        }
    }

}
