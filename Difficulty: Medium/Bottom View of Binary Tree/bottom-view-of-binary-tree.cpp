/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        
        map<int, int>mp;
        int hd = 0;
        queue<pair<Node*, int>>q;
        
        q.push({root, 0});
    
        
        while(!q.empty()){
            Node* node = q.front().first;
            int hd = q.front().second;
            mp[hd] = node->data;
            q.pop();
            
            
            if(node->left) {
                q.push({node->left, hd-1});
            }
            if(node->right){
                q.push({node->right, hd+1});
            }
        }
        
        vector<int>ans;
        
        for(auto it: mp) ans.push_back(it.second);
        
        return ans;
        
    }
};