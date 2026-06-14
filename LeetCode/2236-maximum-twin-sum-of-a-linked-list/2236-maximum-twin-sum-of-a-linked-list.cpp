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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int maxi=INT_MIN;
        for(int i=0;i<ans.size()/2;i++){
            int p=ans[i]+ans[ans.size()-1-i];
            if(p>maxi) maxi=p;

        }
        return maxi;
        
    }
};