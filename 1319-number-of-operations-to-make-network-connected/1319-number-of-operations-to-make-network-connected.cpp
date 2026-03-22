class Solution {
public:
    int find(int i, vector<int>&parent){
        if(parent[i] == i){
            return i;
        }

        return parent[i] = find(parent[i], parent);   
    }

    void Union(int x, int y, vector<int>&rank, vector<int>&parent){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y){
            return;
        }
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int>parent(n);
        vector<int>rank(n, 0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int components = n;
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(find(u, parent) != find(v, parent)){
                Union(u, v, rank, parent);
                components--;
            }
        }

        return components-1;
    }
};