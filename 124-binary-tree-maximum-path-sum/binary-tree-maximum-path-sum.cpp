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
    int dfs(TreeNode* root, int &maxSum){
        if(root == NULL) return 0;

        int lmax = max(0, dfs(root->left, maxSum));
        int rmax = max(0, dfs(root->right, maxSum));

        maxSum = max(lmax + rmax + root->val, maxSum);
        
        return max(lmax + root->val, rmax + root->val);

    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);

        return maxSum;
    }
};