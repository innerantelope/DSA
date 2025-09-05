class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (true) {
            int minIndex = -1;
            int minVal = INT_MAX;

            for (int i = 0; i < k; i++) {
                if (lists[i] != nullptr) {
                    if (lists[i]->val < minVal) {
                        minVal = lists[i]->val;
                        minIndex = i;
                    }
                }
            }

            if (minIndex == -1) break;

           
            tail->next = lists[minIndex];
            tail = tail->next;

            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy->next;
    }
};