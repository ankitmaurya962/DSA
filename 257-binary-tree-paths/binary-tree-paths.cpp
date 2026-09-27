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
    void dfs(TreeNode* root, vector<string>&ans, string temp){
        if(root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp += to_string(root->val) + "->";
        if(root->left) dfs(root->left, ans, temp);
        if(root->right) dfs(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;

        dfs(root, ans, "");

        return ans;
    }
};