class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        while (true) {
            ListNode* end = pre;
            for (int i = 0; i < k && end; i++) end = end->next;
            if (!end) break;
            ListNode* nxt = end->next;
            ListNode* cur = pre->next;
            ListNode* prev = nxt;
            while (cur != nxt) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            ListNode* start = pre->next;
            pre->next = end;
            pre = start;
        }
        return dummy.next;
    }
};