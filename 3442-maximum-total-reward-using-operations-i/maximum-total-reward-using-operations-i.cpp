class Solution {
public:
    int fun(int i,int x, vector<int>&rewardValues,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        int pick = -1e9;
        if(dp[i][x]!=-1)return dp[i][x];
        if(rewardValues[i]>x){
            pick = rewardValues[i] + fun(i+1,x+rewardValues[i],rewardValues,n,dp);
        }
        int nopick =  fun(i+1,x,rewardValues,n,dp);
        return dp[i][x]=max(pick,nopick);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n = rewardValues.size();
        vector<vector<int>>dp(n+1,vector<int>(4*1e4,-1));
        return fun(0,0,rewardValues,n,dp);
    }
};