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
    bool isPalindrome(ListNode* head) {
        //Middle of the LL
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reverse the second half
        ListNode *curr=slow;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *newhead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newhead;

        }
        // Compare both halves
        ListNode *first = head;
        ListNode *second = prev;
        while(second != NULL){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;

        
    }
};