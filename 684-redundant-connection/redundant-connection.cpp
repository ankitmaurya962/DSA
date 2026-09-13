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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);
        for(int i = 0; i<n; i++) parent[i] = i;

        rank.resize(n+1, 0);

        for(auto it: edges){
            if(find(it[0]) == find(it[1])) return{it[0], it[1]};
            else{
                Union(it[0], it[1]);
            }
        }

        return {};
    }
};