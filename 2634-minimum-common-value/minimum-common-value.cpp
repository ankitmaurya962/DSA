class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        int smallest = 0;
        int comman = 0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                smallest = nums1[i];
                i++;
            }else if(nums1[i] > nums2[j]){
                smallest = nums2[j];
                j++;
            }else{
                smallest = nums1[i];
                comman = 1;
                break;
            }
        }

        return comman == 1 ? smallest: -1;
    }
};