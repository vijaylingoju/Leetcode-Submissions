class Solution {
public:
    
    int fun(int i, vector<int>&nums, int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i]+fun(i+2,nums,n,dp);
        int nopick = fun(i+1,nums,n,dp);
        return dp[i]=max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return fun(0,nums,nums.size(),dp);
    }
};