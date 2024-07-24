class Solution {
public:
    int fun(int i, vector<int>&nums, int n, int k, vector<vector<int>>&dp){
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        if(k==0)return 0;
        if(i>=n)return 1e9;
        int pick = 1e9;
        if(dp[i][k]!=-1)return dp[i][k];
        if(k>=nums[i]) pick = 1 + fun(i,nums,n,k-nums[i],dp);
        int nopick = fun(i+1,nums,n,k,dp);
        return dp[i][k]=min(pick,nopick);
    }
    int coinChange(vector<int>& nums, int k) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(k+1,-1));
        int ans = fun(0,nums,nums.size(),k,dp);
        return ans==1e9 ? -1 : ans;
    }
};