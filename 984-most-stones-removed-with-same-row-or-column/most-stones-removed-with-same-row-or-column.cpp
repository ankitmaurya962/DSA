class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int n1, int n2){
        int parent_n1 = find(n1);
        int parent_n2 = find(n2);

        if(parent_n1 == parent_n2) return;

        if(rank[parent_n1] > rank[parent_n2]){
            parent[parent_n2] = parent_n1;
        }else if(rank[parent_n1] < rank[parent_n2]){
            parent[parent_n1] = parent_n2;
        }else{
            parent[parent_n1] = parent_n2;
            rank[parent_n2]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i, j);
                }
            }
        }

        int components = 0;
        for(int i = 0; i<n; i++){
            if(parent[i] == i) components++;
        }

        return n-components;
    }
};