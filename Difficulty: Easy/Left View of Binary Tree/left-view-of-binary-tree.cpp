/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  void dfs(Node* root, int l, map<int, int>&mp){
      if(root == NULL) return;

      if(mp.find(l)==mp.end()) mp[l] = root->data;

      dfs(root->left, l+1, mp);
      dfs(root->right, l+1, mp);
  }
    vector<int> leftView(Node *root) {
        // code here
        map<int, int>mp;
        dfs(root, 0, mp);

        vector<int>ans;
        for(auto it: mp) ans.push_back(it.second);

        return ans;
    }
};