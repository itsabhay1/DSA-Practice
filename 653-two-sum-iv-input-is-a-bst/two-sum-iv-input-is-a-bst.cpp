class Solution {
public:
    bool dfs(TreeNode* root, int k, unordered_set<int>& need) {
        if (!root) return false;

        if (need.count(root->val)) return true;

        need.insert(k - root->val);

        return dfs(root->left, k, need) || dfs(root->right, k, need);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> need;
        return dfs(root, k, need);
    }
};