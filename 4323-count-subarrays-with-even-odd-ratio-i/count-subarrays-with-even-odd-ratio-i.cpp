class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int oddCount= 0;
            int evenCount = 0;
            for(int j = i; j<n; j++){
                if(nums[j]%2 == 0) evenCount++;
                else oddCount++;

                if(oddCount>0){
                    if(evenCount*b <= a*oddCount) ans++;
                }
            }
        }

        return ans;
    }
};