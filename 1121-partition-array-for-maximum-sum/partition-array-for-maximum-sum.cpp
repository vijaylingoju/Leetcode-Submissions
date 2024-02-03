class Solution {
public:
    int fun(int i, vector<int>&arr, int k, int n, vector<int>&dp){
        if(i>=n)return 0;
        int mxx = 0;
        int ans = 0;
        if(dp[i]!=-1)return dp[i];
        for(int j = i; j < min(i+k,n); j++){
            mxx = max(mxx,arr[j]);
            ans = max(ans,(j-i+1)*mxx + fun(j+1,arr,k,n,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(501,-1);
        return fun(0,arr,k,arr.size(),dp);
    }
};