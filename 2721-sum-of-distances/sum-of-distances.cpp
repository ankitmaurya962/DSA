class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>ans(n, 0);

        unordered_map<int, long long>freq;
        unordered_map<int, long long>indexSum;

        //left->right
        for(int i = 0; i<nums.size(); i++){
            long long f = freq[nums[i]];
            long long sum = indexSum[nums[i]];
            ans[i] += f*i - sum;

            //update map
            freq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        freq.clear();
        indexSum.clear();

        //right->left
        for(int i = n-1; i>=0; i--){
            long long f = freq[nums[i]];
            long long sum = indexSum[nums[i]];
            ans[i] += sum - f*i;

            //update map
            freq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        return ans;
    }
};