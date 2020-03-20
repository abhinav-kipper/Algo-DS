//Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space).

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *resultHead=NULL;
    if (!head1) return head2;
    if (!head2) return head1;
    if (head1->data <=head2->data)
            resultHead=head1;
    else resultHead = head2;
    
    while(head1 && head2){
        if (head1->data<=head2->data){
            while(head1->next && head1->next->data<head2->data)
                head1=head1->next;
            Node * temp = head1->next;
            head1->next = head2;
            head1=temp;
        }
          if (head1 && head2 && head2->data<=head1->data) {
            while(head2->next && head2->next->data<head1->data)
                head2=head2->next;
            Node * temp = head2->next;
            head2->next = head1;
            head2=temp;
        }
    }
    
    return resultHead;
