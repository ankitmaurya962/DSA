class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        vector<vector<int>> subarr;

        for (int i = 0; i <= nums.size() - k; i++) {
            vector<int> temp;
            for (int j = i; j < i + k; j++) {
                temp.push_back(nums[j]);
            }

            subarr.push_back(temp);
        }

        int ans = -1;
        for (int l = 0; l < nums.size(); l++) {
            int count = 0;
            for (int i = 0; i < subarr.size(); i++) {
                for (int j = 0; j < subarr[i].size(); j++) {
                    if (nums[l] == subarr[i][j]){
                        count++;
                        break;
                    }
                }
            }
            if(count == 1) ans = max(ans, nums[l]);
        }

        return ans;
    }
};