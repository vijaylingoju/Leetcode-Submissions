class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX, j=INT_MAX, n=nums.size();
        for(int x = 0; x < n; x++){
            if(nums[x]<=i)i=nums[x];
            else if(nums[x]<=j)j=nums[x];
            else return true;
        }
        return false;
    }
};