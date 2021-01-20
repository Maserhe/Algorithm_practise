class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode * newList = new ListNode(0);
        ListNode * temp = newList;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                temp->next = l2;
                l2 = l2->next;
            }
            else {
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }

        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        return newList->next;
    }
};