class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r = 0;
        int l = 0;

        unordered_map<int, int>mp;
        int n = fruits.size();

        int maxFruits = 1;
        while(r < n){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;

                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                } 

                l++;
            }
            maxFruits = max(r-l+1, maxFruits);
            r++;
        }
        return maxFruits;
    }
};