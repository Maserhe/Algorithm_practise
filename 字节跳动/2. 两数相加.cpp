class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int add = 0;
        ListNode * head = new ListNode(0);
        ListNode * tmp = head;

        while (l1 || l2) {
            int a = l1? l1->val:0;
            int b = l2? l2->val:0;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next; 
            ListNode * newNode = new ListNode((a + b + add) % 10);
            add = (a + b + add) / 10;
            tmp->next = newNode;
            tmp = tmp->next;
        }
        if (add) {
            ListNode * last = new ListNode(1);
            tmp->next = last;
        }
        return head->next;
    }
};