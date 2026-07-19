class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];
        for(int i = 1; i<nums.size(); i++){
            smallest = min(nums[i], smallest);
            largest = max(nums[i], largest);
        }
        return __gcd(smallest, largest);
    }
};