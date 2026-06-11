class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
        }
        
        int tempSum = 0;
        for(int i = 0; i<arr.size(); i++){
            if(sum - tempSum - arr[i] == tempSum){
                return i;
            }
            tempSum += arr[i];
        }
        
        return -1;
    }
};