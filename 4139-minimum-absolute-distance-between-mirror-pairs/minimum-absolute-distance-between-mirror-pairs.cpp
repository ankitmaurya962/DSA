class Solution {
public:
    int reverseNum(int x){
        int a = 0;
        while(x!=0){
            int last = x%10;
            a = a*10 + last;
            x = x/10;
        }

        return a;
    }
    int minMirrorPairDistance(vector<int>& nums) {

        int ans = INT_MAX;
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            int r = reverseNum(nums[i]);

            if(mp.find(nums[i]) == mp.end()){
                mp[r] = i;
            }else{
                ans = min(ans, abs(i - mp[nums[i]]));
                mp[r] = i;
            }
        }

        return  ans == INT_MAX ? -1: ans;
    }
};