struct cmp{
    bool operator()(ListNode * a, ListNode * b) {return a->val > b->val;}
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // 使用 优先队列
        priority_queue<ListNode *, vector<ListNode*>, cmp> q;
        // 把队头 全部进 栈。
        for(auto i: lists) if (i) q.push(i);

        ListNode * head = new ListNode(0);
        ListNode * temp = head;
        while (q.size()) {
            ListNode * t = q.top();
            q.pop();
            temp->next = t;
            temp = t;
            if (t->next) q.push(t->next);
        }
        
        return head->next;
    }
};