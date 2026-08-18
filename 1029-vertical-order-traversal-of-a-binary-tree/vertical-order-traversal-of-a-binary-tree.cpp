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
    void dfs(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int h, int l){
        if(root == NULL) return;

        mp[h][l].insert(root->val);
        dfs(root->left, mp, h-1, l+1);
        dfs(root->right, mp, h+1, l+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;

        dfs(root, mp, 0, 0);

        vector<vector<int>>ans;
        for(auto it1: mp){
            vector<int>cols;
            for(auto it2: it1.second){
                cols.insert(cols.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
    }
};