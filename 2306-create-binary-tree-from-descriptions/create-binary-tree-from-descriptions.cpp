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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>st;

        for(int i = 0; i<n; i++){
            //parent
            int parentNodeVal = descriptions[i][0];
            TreeNode* parentNode;
            if(mp.find(parentNodeVal) == mp.end()){
                parentNode = new TreeNode(parentNodeVal);
                mp[parentNodeVal] = parentNode;
            
            }else{
                parentNode = mp[parentNodeVal];
            }

            //child
            int childNodeVal = descriptions[i][1];
            st.insert(childNodeVal);
            TreeNode* childNode;
            if(mp.find(childNodeVal) == mp.end()){
                childNode = new TreeNode(childNodeVal);
                mp[childNodeVal] = childNode;
            }else{
                childNode = mp[childNodeVal];
            }
            //left or rightCHild
            if(descriptions[i][2] == 1){
                parentNode->left = childNode;
            }else{
                parentNode->right = childNode;
            }
        }  
        //find root
        for(int i = 0; i<descriptions.size(); i++){
            if(st.find(descriptions[i][0]) == st.end()){
                return mp[descriptions[i][0]];
            }
        }
        return NULL;
    }
};