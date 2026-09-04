class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto it: nums) st.insert(it);

        int i = k;
        while(st.find(i)!=st.end()){
            i +=k;
        }
        return i;
    }
};