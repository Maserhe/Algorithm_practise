class Solution {
public:
    /**
     * 
     * @param root TreeNode¿‡ 
     * @return int’˚–Õvector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        
        while (q.size()) {
            vector<int> temp;
            int size = q.size();
            while (size -- ) {
                TreeNode * t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
                
            }
            if (flag) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};