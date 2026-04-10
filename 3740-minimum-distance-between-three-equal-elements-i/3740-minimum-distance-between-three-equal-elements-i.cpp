class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>>mp;

        for(int  i = 0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto it: mp){
            if(it.second.size() >= 3){
                int sum = 0;
                vector<int>goodtuple = it.second;
                for(int i = 0; i<=goodtuple.size()-3; i++){
                    int a = goodtuple[i];
                    int b = goodtuple[i+1];
                    int c = goodtuple[i+2];

                    sum = abs(a-b) + abs(b-c) +abs(c-a);
                    ans  = min(sum, ans);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};