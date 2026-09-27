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
    void dfs(TreeNode *root, int h, int l, map<int, map<int, multiset<int>>>&mp){
        if(root == NULL) return;

        mp[h][l].insert(root->val);
        dfs(root->left, h-1, l+1, mp);
        dfs(root->right, h+1, l+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        
        dfs(root, 0, 0, mp);

        vector<vector<int>>ans;
        for(auto i: mp){
            vector<int>temp;
            for(auto j: i.second){
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};