class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;
        // 使用 快慢双指针。
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * ans = new ListNode(0);
        ans->next = head;
        
        ListNode * pre = ans;
        while (fast) {

            for (int i = 0; i < k; i ++ ) {
                if (fast) fast = fast->next;
                else {
                    pre->next = slow;
                    return ans->next;
                }
            }
            
            // 反转 链表
            ListNode * t_head = slow;
            ListNode * tmp = t_head;

            slow = slow->next;
            t_head->next = NULL;
            
            while (slow != fast) {
                ListNode * t = slow->next;
                slow->next = t_head;
                t_head = slow;
                slow=t;
            }
            pre->next = t_head;
            pre = tmp;
        }
        
        return ans->next;
    }
};