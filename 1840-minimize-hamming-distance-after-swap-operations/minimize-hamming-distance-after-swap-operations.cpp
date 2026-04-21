class Solution {
public:

    int find(vector<int>&parent, int i){
        if(i == parent[i]) return i;

        return parent[i] = find(parent, parent[i]);
    }


    void Union(int x, int y, vector<int>&parent, vector<int>&rank){
        int x_parent = find(parent, x);
        int y_parent = find(parent, y);

        if(x_parent != y_parent){
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<int>parent(source.size());
        //parent initialization
        for(int i = 0; i<source.size(); i++){
            parent[i] = i;
        }

        vector<int>rank(source.size(), 0);

        for(int i = 0; i<allowedSwaps.size(); i++){
            int x = allowedSwaps[i][0];
            int y = allowedSwaps[i][1];
            Union(x, y, parent, rank);
        }

        //map to store all parents all elements
        map<int, unordered_map<int, int>>mp;
        for(int i = 0; i < source.size(); i++){
            int root = find(parent, i);
            mp[root][source[i]]++;   // count frequency
        }

        //finding difference
        int diff = 0;
        for(int i = 0; i < source.size(); i++){
            int root = find(parent, i);

            if(mp[root][target[i]] > 0){
                mp[root][target[i]]--;
            } else {
                diff++;
            }
        }

        return diff;
    }
};