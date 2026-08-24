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
    TreeNode* f(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>&mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int nodePos = mp[node->val];
        int leftElements =  nodePos - inStart;
        node->left = f(preorder, preStart + 1, preStart + leftElements, inorder, inStart, nodePos-1, mp);
        node->right = f(preorder, preStart + leftElements +1, preEnd, inorder, nodePos + 1, inEnd, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return f(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};