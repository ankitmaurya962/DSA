class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int x = 1;
        int sum = 0;
        int maxRange = n+k;
        int minRange = max(n-k, 1);
        for(int x = minRange; x<=maxRange; x++){
            if (!(n & x)) {
                sum += x;
            }
        }

        return sum;
    }
};