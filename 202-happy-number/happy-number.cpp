class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>mp;
        int tempNum = n;
        
        while(true){
            if(mp.find(tempNum)!=mp.end()) return false;
            mp[tempNum]++;
            
            int tempSum = 0;
            while(tempNum>0){
                int digit = tempNum%10;
                tempSum += digit * digit;
                tempNum /=10;
            }

            if(tempSum == 1) return true;

            tempNum = tempSum;
            
        }
        return true;
    }
};