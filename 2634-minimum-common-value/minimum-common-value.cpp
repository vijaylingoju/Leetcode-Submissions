class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while(i<n and j<m){
            if(nums1[i]<nums2[j]){
                i+=1;
            }
            else if(nums1[i]>nums2[j]){
                j+=1;
            }
            else if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            
        }
        return -1;
    }
};