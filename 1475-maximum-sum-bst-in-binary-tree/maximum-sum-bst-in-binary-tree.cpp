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
 int ans = 0;

 struct info{
    bool isBST;
    int mn, mx;
    int sum;
 };

public:
    info bst(TreeNode* root){
        if(!root) return {true, INT_MAX, INT_MIN, 0};

        info left = bst(root->left);
        info right = bst(root->right);

        if(left.isBST && right.isBST && left.mx < root->val && root->val < right.mn){
            int currSum = root->val + left.sum + right.sum;
            ans = max(ans, currSum);

            return {
                true,
                min(left.mn,root->val),
                max(right.mx, root->val),
                currSum
            };
        }
        return {false, INT_MIN, INT_MAX, 0};
    }
public:
    
    int maxSumBST(TreeNode* root) {
        bst(root);
        return ans;
    }
};