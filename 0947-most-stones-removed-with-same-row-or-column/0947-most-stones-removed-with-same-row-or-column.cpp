class Solution {
public:
    int find(int i, vector<int>&parent){
        if(parent[i] == i){
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&rank){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int>parent(n);
        vector<int>rank(n, 0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        //same group elemnt join
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i, j, parent, rank);
                }
            }
        }
        //counting components
        int components = 0;
        for(int i = 0; i<n; i++){
            if(parent[i] == i) components++;
        }
        return n-components;
    }
};