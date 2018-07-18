#include<bits/stdc++.h>
using namespace std;
class trieNode
{
    public:trieNode* right; //right exist means 1
    trieNode* left; // left exist means 0
};
// int is of 32  bits so go from 0 to 31 starting  from 31st bit as MSB matters most for max
void insert(int n,trieNode * head)
{
    trieNode * curr=head;
    for (int i=31;i>=0;i--)
    {
        int  bit=(n>>i)&1; // right shift
        if (bit==0)
        {
                if  (!curr->left) //left means  0
                {
                    curr->left=new trieNode();
                }
                curr=curr->left;
        }
        else{
                if (!curr->right)
                {
                    curr->right=new trieNode();
                }
                curr=curr->right;
        }
    }
}
int findMaxXorPair(trieNode*head,int *arr,int n)
{
            int max_xor=INT_MIN;
            for (int i=0;i<n;i++)
            {
                int value=arr[i];
                trieNode*curr=head;
                int curr_xor=0;
                for (int j=31;j>=0;j--)
                {
                    int bit=(value>>j)&1;
                    if (bit==0)//need 1 for  max
                    {
                            if (curr->right)
                            {
                                curr_xor+=pow(2,j); //coz 1 makes value not 0-- will be 1 in xor result so will contribute
                                curr=curr->right;
                            }

                            else{curr=curr->left;} //no other option
                    }
                    else { // need 0 for max
                            if (curr->left)
                            {
                                curr_xor+=pow(2,j); //max xor (curr) will be 1 here as satisfied the condition for 1 0 existed
                                curr=curr->left;
                            }

                            else{
                                curr=curr->right;
                            }
                    }
                }
                if (curr_xor>max_xor) max_xor=curr_xor;
            }
            return max_xor;
}
int main()
{
    int arr[6]={8,1,2,3,10,5};
    trieNode*head=new trieNode();
    for (int i=0;i<6;i++)
        insert(arr[i],head);
    cout<<findMaxXorPair(head,arr,6);
    return 0;
}
