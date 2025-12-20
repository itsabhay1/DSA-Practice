class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool check(TreeNode* root, int index, int total) {
        if (!root) return true;
        if (index >= total) return false;
        return check(root->left, 2 * index + 1, total) &&
               check(root->right, 2 * index + 2, total);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return check(root, 0, total);
    }
};
