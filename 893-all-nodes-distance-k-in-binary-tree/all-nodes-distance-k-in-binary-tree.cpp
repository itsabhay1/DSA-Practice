/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == nullptr) return {};
        unordered_map<TreeNode*, TreeNode*> parentNode;
        markParent(root,parentNode);

        return bfsTravel(target, parentNode, k);
    };

    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentNode){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                parentNode[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                parentNode[node->right] = node;
            }
        }
    }

    vector<int> bfsTravel(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentNode, int k){
        unordered_set<TreeNode*>visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while(!q.empty()){
            int size = q.size();

            if(dist == k) break;

            dist++;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parentNode[node] && visited.find(parentNode[node]) == visited.end()){
                    q.push(parentNode[node]);
                    visited.insert(parentNode[node]);
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

};