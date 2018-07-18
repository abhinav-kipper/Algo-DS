#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode{
    char data; //one of the input characters
    unsigned freq; //freq of  character
    struct MinHeapNode *left,*right;

     MinHeapNode(char data,unsigned freq){
     left=right=NULL;
     this->data=data;
     this->freq=freq;
     }
};
struct compare{
    bool operator()(MinHeapNode* l,MinHeapNode* r){
        return (l->freq > r->freq);
    }

};

void printCodes(struct MinHeapNode* root,string str){
    cout<<root->data<<endl;
    if (root==NULL) return ;
    if  (root->data!='$'){
        cout<<root->data<<":"<<str<<"\n";
cout<<"Princess"<<str<<endl;
        printCodes(root->left,str+"0");
        printCodes(root->right,str+"1");
    }
}

void HuffmanCodes(char data[],int freq[],int size){
    struct MinHeapNode *left,*right,*top;

    priority_queue<MinHeapNode *,vector<MinHeapNode*>,compare> minHeap;
    for (int i=0;i<size;++i)
        minHeap.push(new MinHeapNode(data[i],freq[i]));
        cout<<"Princess"<<endl;
        cout<<minHeap.size()<<" "<<endl;
    while(minHeap.size()>1){
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        cout<<minHeap.size()<<" "<<endl;
        cout<<left->data<<" "<<right->data<<endl;
        top=new MinHeapNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    cout<<"print";
    printCodes(minHeap.top(),"");
}
int main()
{
    char  a[]={'a','b','c','d','e','f'};
    int  freq[]={5,9,12,13,16,45};
    HuffmanCodes(a,freq,6);
}
