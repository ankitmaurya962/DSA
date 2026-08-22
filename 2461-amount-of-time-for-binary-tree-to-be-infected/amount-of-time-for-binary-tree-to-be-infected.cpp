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
    TreeNode* findStart(TreeNode* root, int start){
        if(root == NULL) return NULL;

        if(root->val == start) return root;

        TreeNode* left = findStart(root->left, start);
        if(left) return left;

        TreeNode* right = findStart(root->right, start);
        if(right) return right;

        return NULL;
    }
    void parentTrack(TreeNode* root, unordered_map<TreeNode* , TreeNode*>&parent){
        if(root == NULL) return;

        if(root->left){
            parent[root->left] = root;
            parentTrack(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            parentTrack(root->right, parent);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parent;
        unordered_map<TreeNode*, bool>visited;
        TreeNode* startNode = findStart(root, start);
        parentTrack(root, parent);
        queue<TreeNode*>q;
        q.push(startNode);
        visited[startNode] = true;

        int dist = 0;
        while(!q.empty()){
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

        return dist-1;
    }
};