class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int mini=INT_MAX;
        while(st<=end){
            while(st<end && nums[st] == nums[st+1])st++;
            while(st<end && nums[end] == nums[end-1])end--;

            int mid=st+(end-st)/2;
            if(nums[st]<=nums[mid]){
                mini=min(mini,nums[st]);
                st=mid+1;
            }else{
                mini=min(mini,nums[mid]);
                end=mid-1;                
            }
        }
        return mini;
    }
};