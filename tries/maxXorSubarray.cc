#include<bits/stdc++.h>
using namespace std;
class trieNode 
{
	public : trieNode * left;
				trieNode * right;
};
int insert(int n ,trieNode * head)
{
	trieNode * cur=head;
	for (int i=31;i>=0;i--)
	{
		int bit=  ( n >> i ) &1;
		if (bit==0)
		{
			if (!cur->left)
			{
				cur->left=new trieNode ();
			}
			cur=cur->left;
		}
		else
		{
			if (!cur->right)
			{
				cur->right=new trieNode ();
			}
			cur=cur->right;
		}
	}
}
int  maxXorPairKind(trieNode * head,int n)
{
	trieNode * cur=head;
	int xor_res=0;
	for (int i=31;i>=0;i--)
	{
		int bit= (n>>i) &1;
		if (bit==0) //move to right if possible - 1 
		{
			if (cur->right)
			{
				xor_res+=pow(2,i);
				cur=cur->right;
			}
			else cur=cur->left;
		}
		else
		{
			if (cur->left)
			{
				xor_res+=pow(2,i);
				cur=cur->left;
			}
			else cur=cur->right;
		}
	}
	return xor_res; 
}
int findMaxXorSubarray(trieNode * head,int * a,int size)
{
	int max_xor=INT_MIN,cur_poss_xor=0;
	for  (int i=0;i<size;i++)
	{
		cur_poss_xor=cur_poss_xor ^ a[i];
		int cur_xor=maxXorPairKind(head,cur_poss_xor);
		max_xor=max(max_xor,max(cur_poss_xor,cur_xor));
		insert(cur_poss_xor,head);
	}
	return max_xor;
}
int main()
{
 int arr[6]={8,2,10,16,0,6};
    trieNode*head=new trieNode();
  //for (int i=0;i<6;i++)
        insert(arr[0],head);
    cout<<findMaxXorSubarray(head,arr,6);
	return 0;
}
