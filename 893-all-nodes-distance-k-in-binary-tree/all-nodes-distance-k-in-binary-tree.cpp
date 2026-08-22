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
    void parenttrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
        if(root == NULL) return;
        if(root->left) {
            parent[root->left] = root;
            parenttrack(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            parenttrack(root->right, parent);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool>visited;
        unordered_map<TreeNode*, TreeNode*>parent;

        parenttrack(root, parent);

        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty()){
            if(dist == k) break;
            int n = q.size();

            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                //upward
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
                //left
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                //right
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
            }
            dist++;
        }

        vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};