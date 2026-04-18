class Solution {
public:
    int mirrorDistance(int n) {
        //reverse
        int reverse = 0;
        int original = n;
        while(n!=0){
            int last = n%10;
            reverse = reverse*10 + last;
            n = n/10;
        }
        n = original;
        return abs(n - reverse);
    }
};