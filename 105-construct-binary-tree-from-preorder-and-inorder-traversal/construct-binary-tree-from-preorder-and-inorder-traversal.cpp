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
    TreeNode* buildTreeHelper(vector<int>& preorder, int& preIndex,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& inMap) {
        if (inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int inIndex = inMap[root->val];

        root->left = buildTreeHelper(preorder, preIndex, inorder, inStart,
                                     inIndex - 1, inMap);
        root->right = buildTreeHelper(preorder, preIndex, inorder, inIndex + 1,
                                      inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;

        TreeNode* root =
            buildTreeHelper(preorder, preIndex, inorder, 0, n - 1, inMap);
        return root;
    }
};