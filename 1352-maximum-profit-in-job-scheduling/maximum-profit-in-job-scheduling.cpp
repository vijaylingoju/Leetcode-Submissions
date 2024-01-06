class Solution {
public:
    int fun(int i, vector<pair<int,pair<int,int>>>&sche, vector<int>&startTime,int n, vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int var = lower_bound(startTime.begin(),startTime.end(),sche[i].second.first)-startTime.begin();

        int a = sche[i].second.second + fun(var, sche,startTime,n,dp);
        int b = fun(i+1,sche,startTime,n,dp);
        return dp[i]=max(a,b);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int  n = startTime.size();
        vector<pair<int,pair<int,int>>>sche;
        for(int  i = 0; i < n; i++){
            sche.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(sche.begin(),sche.end());
        sort(startTime.begin(),startTime.end());
        vector<int>dp(n,-1);
        return fun(0,sche,startTime,n,dp);

    }
};