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
    void dfs(TreeNode* root, int x, int y, vector<tuple<int,int,int>> &nodes){
        if(!root) return;

        nodes.push_back({x, y, root->val});

        dfs(root->left, x-1, y+1, nodes);
        dfs(root->right, x+1, y+1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;

        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevX = INT_MIN;

        for(auto &[x, y, val] : nodes){
            if(x != prevX){
                ans.push_back({});
                prevX = x;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};