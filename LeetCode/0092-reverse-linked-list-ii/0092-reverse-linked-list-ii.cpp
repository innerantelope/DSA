/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        for(int i=0;i<left-1;i++){
            temp=temp->next;
        }
        ListNode* leftprev=temp;
        ListNode* prevhead=leftprev->next;
        ListNode* curr=prevhead;
        ListNode* prev=NULL;
        for(int i=0;i<right-left+1;i++){
            ListNode* currnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currnext;

        }
        leftprev->next=prev;
        prevhead->next=curr;
        return dummy->next;
    }
};