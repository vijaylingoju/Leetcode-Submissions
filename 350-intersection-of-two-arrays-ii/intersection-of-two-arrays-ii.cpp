class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = nums1.size() - 1, j = nums2.size() - 1;
        vector<int>ans;
        while(i>=0 and j>=0){
            if(nums1[i]<nums2[j]){
                j-=1;
            }else if(nums1[i]>nums2[j]){
                i-=1;
            }else{
                ans.push_back(nums1[i]);
                i-=1;
                j-=1;
            }
        }
        return ans;
    }
};