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
    void reorderList(ListNode* head) {
        //find the middle of the ll
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the second half
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        while(curr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        slow->next=NULL;
        //merge the two halves
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            ListNode* tmp1=first->next;
            ListNode* tmp2=second->next;
            first->next=second;
            second->next=tmp1;
            first=tmp1;
            second=tmp2;
        }
        
    }
};