class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size();
        int left = 0;
        int right = n-1;
        
        int maxArea = 0;
        while(left<right){
            int area =  min(height[left], height[right]) * (right - left - 1);
            maxArea = max(area, maxArea);
            
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return maxArea;
    }
};