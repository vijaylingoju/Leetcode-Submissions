class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int ans = 0, n = nums.size(), curr = 0, i = 0, j = 0;
        while(j<n){
            curr += nums[j]%2;
            while(curr>k){
                curr-=(nums[i++]%2);
            }
            ans+=(j-i+1);
            j+=1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};