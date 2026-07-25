class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;

        while(n!=0){
            int digit = n%10;
            arr.push_back(digit);
            n = n/10;
        }

        sort(arr.begin(), arr.end());
        int s = arr.size();
        return arr[s-1] * arr[s-2];
    }
};