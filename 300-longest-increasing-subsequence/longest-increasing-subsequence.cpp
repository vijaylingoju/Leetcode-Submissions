class Solution {
public:
    int fun(int i, int prev, vector<int>&nums, int n, vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int pick = INT_MIN;
        if(prev==-1 or nums[i]>nums[prev]){
            pick = 1 + fun(i+1,i,nums,n,dp);
        }
        int nopick = fun(i+1,prev,nums,n,dp);
        return dp[i][prev+1]=max(pick,nopick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,-1,nums,n,dp);
    }
};