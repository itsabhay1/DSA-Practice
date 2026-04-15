/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int& postIndex, int inStart, int inEnd,
                              unordered_map<int, int>& inMap) {
        if (inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int inIndex = inMap[root->val];

        root->right = buildTreeHelper(inorder, postorder, postIndex,
                                      inIndex + 1, inEnd, inMap);
        root->left = buildTreeHelper(inorder, postorder, postIndex, inStart,
                                     inIndex - 1, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        int postIndex = n - 1;

        TreeNode* root =
            buildTreeHelper(inorder, postorder, postIndex, 0, n - 1, inMap);
        return root;
    }
};