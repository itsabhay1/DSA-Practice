/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfsTree(TreeNode* root){
        if(root == nullptr) return 0;
        return 1+max(dfsTree(root->left), dfsTree(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int lt = dfsTree(root->left);
        int rt = dfsTree(root->right);
        int n = lt + rt;
        return max(n, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};