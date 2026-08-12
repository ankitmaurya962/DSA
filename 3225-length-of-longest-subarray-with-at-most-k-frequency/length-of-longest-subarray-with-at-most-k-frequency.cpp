class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>freq;

        int i = 0;
        int j = 0;

        int longest = 0;
        while(i<nums.size()){
            freq[nums[i]]++;

            if(freq[nums[i]] > k){

                while(freq[nums[i]] > k){
                   freq[nums[j]]--; 
                   j++;
                }
            }
            
            longest = max(longest, i-j+1);
            i++;
        }

        return longest;
    }
};