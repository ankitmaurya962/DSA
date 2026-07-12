class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp = arr;
        sort(arr.begin(), arr.end());

        unordered_map<int, int>mp;
        int prevRank = 1;
        for(int i = 0; i<n; i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = prevRank;
                prevRank++;
            }
        }

        vector<int>ans(n);

        for(int i = 0; i<n; i++){
            ans[i] = mp[temp[i]];
        }

        return ans;
    }
};