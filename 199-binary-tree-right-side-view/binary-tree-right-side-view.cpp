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
    void dfs(TreeNode* root, int l, map<int, int>&mp){
        if(root == NULL) return;

        mp[l] = root->val;

        dfs(root->left, l+1, mp);
        dfs(root->right, l+1, mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int>mp;
        dfs(root, 0, mp);

        vector<int>ans;
        for(auto it: mp) ans.push_back(it.second);
        
        return ans;
    }
};