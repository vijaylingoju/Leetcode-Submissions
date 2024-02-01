class Solution {
public:

    int fun(int i, int n, int pk, vector<int>&stones,map<int,int>&mp,vector<vector<int>>&dp){
       if(i==n-1)return 1;
       cout << i << " ";
       bool a = false , b = false , c = false;
       if(dp[i][pk] != -1) return dp[i][pk];
       if(pk-1 > 0){
            int x = stones[i] + (pk-1);
            if(mp[x] != 0) a = fun(mp[x],n,pk-1,stones,mp,dp);
       }
       if(pk != 0){
           int x = stones[i] + (pk);
            if(mp[x] != 0) b = fun(mp[x],n,pk,stones,mp,dp);
       }
       int x = stones[i] + (pk+1);
        if(mp[x] != 0) c = fun(mp[x],n,pk+1,stones,mp,dp);
       
       return dp[i][pk] = a|b|c;
        
    }
    bool canCross(vector<int>& stones) {
        map<int,int>mp;
        int n= stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        if(stones[1] != 1) return false;
        for(int i = 0 ; i < n ; i++){
            mp[stones[i]] = i;
        }
        return fun(1,n,1,stones,mp,dp);
    }
};