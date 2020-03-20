//Given two linked lists sorted in increasing order.
//Merge them such a way that the result list is in decreasing order (reverse order).
struct Node * mergeResult(Node *head1,Node *head2)
{
    // your code goes here
    Node  *resultTail=NULL;
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
         Node * newNode = new Node();
          newNode->data = minData;
          newNode->next = NULL;
            if (!resultTail){
                resultTail=newNode;
                resultTail->next = NULL;
            } else{
                newNode->next = resultTail;
        resultTail=newNode;
            }
           
    }
    while (head1){
          Node * newNode = new Node();
          newNode->data = head1->data;
          newNode->next = NULL;
           head1=head1->next;
            if (!resultTail){
                resultTail=newNode;
                resultTail->next = NULL;
            }
         else{
                   newNode->next = resultTail;
        resultTail=newNode;
            }
    }
      while (head2){
          
            Node * newNode = new Node();
          newNode->data = head2->data;
          newNode->next = NULL;
           head2=head2->next;
            if (!resultTail){
                resultTail=newNode;
                resultTail->next = NULL;
            }
         else{
                 newNode->next = resultTail;
        resultTail=newNode;
            }
    }
    return resultTail;
}
