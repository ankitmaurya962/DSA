class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>>mp;
        int n = mat.size();
        int m = mat[0].size();

        vector<int>freqRow(n, 0);
        vector<int>freqCol(m, 0);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i<arr.size(); i++){
            int r = freqRow[mp[arr[i]].first]+=1;
            if(r == m) return i;
            int c = freqCol[mp[arr[i]].second]+=1;
            if(c == n) return i;
        }

        return -1;
    }
};