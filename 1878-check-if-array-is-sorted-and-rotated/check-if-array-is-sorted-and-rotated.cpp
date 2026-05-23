class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i]>nums[(i+1)%nums.size()]){//modulo is used so that we can compare first and last number 
                                               // incase of rotation
                count++;
            }         
        }
        if(count>1){
            return false;
        }else{
            return true;
        }
    }
};