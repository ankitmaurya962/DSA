class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int sum = 0;
        int maxRange = -1;
        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];
            int maxDigit = 0;
            int minDigit = 9;
            while(num!=0){
                int digit = num%10;
                maxDigit = max(maxDigit, digit);
                minDigit = min(minDigit, digit);
                num = num/10;
            }
            int range = maxDigit - minDigit;

            if(range > maxRange){
                maxRange = range;
                sum = nums[i];
            }else if(range == maxRange){
                sum += nums[i];
            }
        }

        return sum;
    }
};