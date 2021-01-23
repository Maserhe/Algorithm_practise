class Solution {
public:

    // 使用归并排序吧。
    // 1. 划分子链
    // 2. 归并
    ListNode * mergeList(ListNode * first, ListNode * second) {

        // 头
        ListNode * head = new ListNode(0);
        ListNode * tmp = head;

        while (first && second) {
            if (first->val > second->val) {
                tmp->next = second;
                second = second->next;
            } else {
                tmp->next = first;
                first = first->next;
            }
            tmp = tmp->next;
        }
        if (first) tmp->next = first;
        if (second) tmp->next = second;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        queue<ListNode *> q;
        ListNode * tmp = head;
        while (tmp) {
            ListNode * t = tmp->next;
            tmp->next = NULL;
            q.push(tmp);
            tmp = t;
        }
        
        while (q.size() != 1) {
            ListNode * t1 = q.front();
            q.pop();
            ListNode * t2 = q.front();
            q.pop();
            q.push(mergeList(t1, t2));
        }
        return q.front();
    }
};