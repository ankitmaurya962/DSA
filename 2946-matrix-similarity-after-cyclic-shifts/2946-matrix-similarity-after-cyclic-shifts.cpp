class Solution {
public:
    void leftshift(vector<int>&arr){
        reverse(arr.begin(), arr.begin()+1);
        reverse(arr.begin() + 1, arr.end());
        reverse(arr.begin(), arr.end());
    }

    void rightshift(vector<int>&arr){
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+1);
        reverse(arr.begin() + 1, arr.end());
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>temp = mat;
        for(int r = 0; r<k; r++){
            for(int i = 0; i<n; i++){
                if(i%2 == 0){
                    leftshift(temp[i]);
                }else{
                    rightshift(temp[i]);
                }
            }
        }

        return temp == mat;
    }
};