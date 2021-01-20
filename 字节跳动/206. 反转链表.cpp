class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;

        ListNode * temp = head->next;
        head->next = NULL;

        while (temp) {
            ListNode * t = temp->next;
            temp->next = head;
            head = temp;
            temp = t;
        }
        return head;
    }
};