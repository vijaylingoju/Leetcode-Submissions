class Solution {
public:
    bool fun(int i, int n, vector<int>&nums, int sum, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i>=n)return false;
        bool pick = false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(nums[i]<=sum){
            pick = fun(i+1,n,nums,sum-nums[i],dp);
        }
        bool nopick = fun(i+1,n,nums,sum,dp);
        return dp[i][sum]=pick|nopick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            sum+=nums[i];
        }
        if(sum%2)return 0;
        sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return fun(0,n,nums,sum,dp);
    }
};