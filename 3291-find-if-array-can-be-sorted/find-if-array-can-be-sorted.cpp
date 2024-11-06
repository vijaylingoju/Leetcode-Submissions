class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int setBits = __builtin_popcount(nums[0]);
        int maxi = nums[0];
        int mini = nums[0];
        int prevMax = INT_MIN;

        for(int i = 1; i < nums.size(); i++){
            if(__builtin_popcount(nums[i]) == setBits){
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            } else{
                if(mini < prevMax) return false;

                prevMax = maxi;
                maxi = nums[i];
                mini = nums[i];
                setBits = __builtin_popcount(nums[i]);
            }
        }
        if(mini < prevMax) return false;
        return true;
    }
};