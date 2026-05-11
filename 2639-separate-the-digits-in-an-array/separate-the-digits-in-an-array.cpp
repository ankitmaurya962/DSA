class Solution {
public:
    void separate(int no, vector<int>&ans){
        int temp = no;
        vector<int>digits;
        while(temp!=0){
            int last = temp%10;
            digits.push_back(last);
            temp = temp/10;
        }
        reverse(digits.begin(), digits.end());
        ans.insert(ans.end(), digits.begin(), digits.end());
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it: nums){
            separate(it, ans);
        }

        return ans;
    }
};