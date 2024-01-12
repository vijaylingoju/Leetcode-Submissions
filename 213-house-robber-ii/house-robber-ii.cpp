class Solution {
public:
    int fun(int i, vector<int>&nums, int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        int pick = nums[i]+fun(i+2,nums,n,dp);
        int nopick = fun(i+1,nums,n,dp);
        return dp[i]=max(pick,nopick);
    }
    int rob(vector<int>& nums){
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size()+1,-1);
        int a = fun(0,nums,nums.size()-1,dp);
        vector<int>dp1(nums.size()+1,-1);
        int b = fun(1,nums,nums.size(),dp1);
        return max(a,b);
    }
};