class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;

        int ans = 0;

        for(int i = 1; i<arr.size()-1; i++){
            int maxMountain = 0;

            //left of mountain
            int left = 0;
            for(int j = i; j>=1; j--){
                if(arr[j] > arr[j-1]) left++;
                else break;
            }

            //right of mountain
            int right = 0;
            for(int j = i; j<arr.size()-1; j++){
                if(arr[j] > arr[j+1]) right++;
                else break;
            }

            if(left != 0 && right != 0) ans = max(ans, left + right + 1);
        }

        return ans == 1 ? 0 : ans;
    }
};