/*Structure of binary tree Node 
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
  int height(Node* root){
      if(root == NULL) return 0;
      
      int lh = height(root->left);
      int rh = height(root->right);
      
      return max(lh, rh) + 1;
  }
    void dfs(Node *root, int &maxD){
        if(root == NULL) return;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        maxD = max(lh + rh, maxD);
        
        dfs(root->left, maxD);
        dfs(root->right, maxD);
        
    }
    int diameter(Node* root) {
        int maxD = 0;
        dfs(root, maxD);
        return maxD;    }
};