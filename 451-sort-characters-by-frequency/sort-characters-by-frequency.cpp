class Solution {
public:

    static bool comp(pair<char, int>&p1, pair<char, int>&p2){
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int>mp;

        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }

        vector<pair<char, int>>freq;

        for(auto it: mp){
            freq.push_back({it.first, it.second});
        }

        sort(freq.begin(), freq.end(), comp);

        string ans = "";
        for(int i = 0; i<freq.size(); i++){
            for(int j = 0; j<freq[i].second; j++){
                ans += freq[i].first;
            }
        }

        return ans;
    }
};