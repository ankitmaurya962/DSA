class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int k = 0; k<4; k++){
            for(int i=0;i<=n-2;i++){
                for(int j=i+1;j<=n-1;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat == target) return true;
        }

        return false;
    }
};