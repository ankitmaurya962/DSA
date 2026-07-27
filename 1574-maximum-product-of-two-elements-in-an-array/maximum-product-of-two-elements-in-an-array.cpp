class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 0;
        int num1idx = -1;
        //first largest
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > num1){
                num1 = nums[i];
                num1idx = i;
            }
        }

        //seond largest
        int num2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > num2 && i!=num1idx){
                num2 = nums[i];
            }
        }
        return (num1 - 1) * (num2- 1);
    }
};