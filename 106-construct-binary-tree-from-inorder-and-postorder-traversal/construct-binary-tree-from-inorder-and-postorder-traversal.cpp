/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int>& postorder, int postStart, int postEnd,
                vector<int>& inorder, int inStart, int inEnd,
                unordered_map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode* node = new TreeNode(postorder[postEnd]);
        int nodePos = mp[node->val];
        int rightElements = inEnd - nodePos;
        node->right = f(postorder, postEnd - rightElements , postEnd-1, inorder,
                       nodePos + 1, inEnd, mp);
        node->left = f(postorder, postStart, postEnd - rightElements - 1, inorder,
                      inStart, nodePos - 1, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return f(postorder, 0, postorder.size() - 1, inorder, 0,
                 inorder.size() - 1, mp);
    }
};