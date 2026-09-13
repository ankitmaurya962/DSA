// User function Template for C++
class Solution {
  public:
        int find_parent(int i, vector<int>&parent){
        if(parent[i] == i) return i;

        return parent[i] = find_parent(parent[i], parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find_parent(x, parent);
        int parent_y = find_parent(y, parent);

        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
           parent[parent_x] = parent_y; 
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int s = n*m;
        vector<int>parent(s);
        for(int i = 0; i<s; i++){
            parent[i] = i;
        }
        vector<int>rank(s, 0);
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        vector<int>ans;
        
        int count = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        for(int i = 0; i<operators.size(); i++){
            int row = operators[i][0];
            int col = operators[i][1];
            
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            
            vis[row][col] = 1;
            count++;
            
            for(int j = 0; j<4; j++){
                int newX = drow[j] + row;
                int newY = dcol[j] + col;
                
                if(newX >=0 && newX < n && newY >=0 && newY < m && vis[newX][newY] == 1){
                    int node = row * m + col;
                    int adjnode = newX * m + newY;
                    
                    if(find_parent(node, parent)!=find_parent(adjnode, parent)){
                        count--;
                        Union(node, adjnode, parent, rank);
                    }
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};
