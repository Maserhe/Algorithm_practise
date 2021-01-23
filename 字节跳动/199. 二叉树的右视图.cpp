class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if (!root) return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size()) {
            int n = q.size();
            ans.push_back(q.front()->val);
            for (int i = 0; i < n; i ++ ) {
                // ·Ö²ã
                TreeNode * t = q.front();
                q.pop();
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
        }
        return ans;
    }
};