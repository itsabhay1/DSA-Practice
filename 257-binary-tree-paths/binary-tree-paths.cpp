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
    void paths(TreeNode* root, string curr, vector<string>& ans){
        if(root == NULL) return;

        if(!curr.empty()) curr += "->";
        curr += to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            ans.push_back(curr);
            return;
        }

        paths(root->left, curr, ans);
        paths(root->right, curr, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        paths(root,"",ans);
        return ans;
    }
};