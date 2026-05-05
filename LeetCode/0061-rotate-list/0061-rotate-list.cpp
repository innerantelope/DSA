class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL || head->next == NULL || k==0 ) return head;
      int length=1;
      ListNode * tail=head;
      while(tail->next){
        tail=tail->next;
        length++;
      }
      tail->next=head;
      k=k%length;
      int steps=length-k;
      while(steps--){
        tail=tail->next;
      }
      head = tail->next;
      tail->next = NULL;
      return head;
    }
    
};