class Solution {
public:
    int createNum(int start, int end){
        int num = 0;
        for(int i = start; i<=end; i++){
            num = num*10 + i;
        }

        return num;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;

        for(int i = 1; i<10; i++){
            for(int j = i; j<10; j++){
                int num = createNum(i, j);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};