class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if (!root) return true;
        if (judge(root) == -1) return false;
        return true;

    }

    int judge(TreeNode* root) {
        if (!root) return 0;
        int a = judge(root->left);
        int b = judge(root->right);
        if (a == -1 || b == -1) return -1;
        if (abs(a - b) > 1) return -1;
        return max(a, b) + 1;
    }

};