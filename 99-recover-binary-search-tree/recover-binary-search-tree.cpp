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
private:
  TreeNode* first;
  TreeNode* middle;
  TreeNode* last;
  TreeNode* prev;

private:
   void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);

    if(prev && root->val < prev->val){

        // if it is first violation
        if(first == NULL){
            first = prev;
            middle = root;
        }

        // if it is second violation
        else{
            last = root;
        }
    }

    prev = root;
    inorder(root->right);
   }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        first = middle = last = NULL;
        prev = nullptr;
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};