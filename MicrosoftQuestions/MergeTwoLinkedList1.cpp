// Given two sorted lists, merge them so as to produce a combined sorted list
//Used Extra memory here 
Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *resultHead=NULL, *resultTail=NULL;
    if (!head1) return head2;
    if (!head2) return head1;
    int  minData;
    // Your Code Here
    while (head1 && head2){
        if (head1->data <= head2->data){
             minData = head1->data;
             head1=head1->next;
        }
        else {
            minData = head2->data;
            head2=head2->next;
        }
        Node * newNode = new Node(minData);
            if (!resultHead){
                resultHead=newNode;
                resultTail=resultHead;
            } else{
                 resultTail->next = newNode;
        resultTail=newNode;
            }
           
    }
    while (head1){
          Node * newNode = new Node(head1->data);
           head1=head1->next;
            if (!resultHead){
                resultHead=newNode;
                resultTail=resultHead;
            }
         else{
                 resultTail->next = newNode;
        resultTail=newNode;
            }
    }
      while (head2){
          
          Node * newNode = new Node(head2->data);
           head2=head2->next;
            if (!resultHead){
                resultHead=newNode;
                resultTail=resultHead;
            }
         else{
                 resultTail->next = newNode;
        resultTail=newNode;
            }
    }
    return resultHead;
    
    
}
