class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n!=0){
            int last = n%10;
            sum += last;
            n = n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            mini = min(mini, sumOfDigits(nums[i]));
        }
        return mini;
    }
};