#include<bits/stdc++.h>
using namespace std;

//A huffman tree node
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data,unsigned freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

//comparison on frequency ..finding min freq
struct compare{
    bool operator()(MinHeapNode* l,MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

//PRINT huffmancode
void printCodes(struct MinHeapNode*root,string str)
{
    if  (!root)
        return;
    if (root->data!='$')
        cout<<root->data<<":"<<str<<"\n";
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

//Huffman
void HuffmanCodes(char data[],int freq[],int size)
{
    //create min heap and insert all characteres of data[]
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;
    for (int i=0;i<size;i++)
        minHeap.push(new MinHeapNode(data[i],freq[i]));

    //Till heap size becomes 1
    while (minHeap.size()!=1)
    {
        //Extract 2 min elements
        MinHeapNode *left=minHeap.top();
        minHeap.pop();
         MinHeapNode *right=minHeap.top();
        minHeap.pop();
        // '$' is a special value for internal nodes, not used
       MinHeapNode * Z=new MinHeapNode('$',left->freq+right->freq);
        Z->left=left;
        Z->right=right;
        minHeap.push(Z);
    }

    printCodes(minHeap.top(),"");
}
int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};
    HuffmanCodes(data,freq,6);
}
