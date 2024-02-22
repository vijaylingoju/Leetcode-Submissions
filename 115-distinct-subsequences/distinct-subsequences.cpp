class Solution {
public:
    int mod = 1e9+7;
    int fun(string &s, string &t, int cur_s, int i, int n,vector<vector<int>>&dp){
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        if(cur_s>=t.size()) {
            return 1;
        }
        if(i>=n)return 0;
        int res = 0;
        if(dp[i][cur_s]!=-1)return dp[i][cur_s];
        if(cur_s < t.size()){
             if(t[cur_s]==s[i]){
                res = res + fun(s,t,cur_s+1,i+1,n,dp);
            }
        }
        res = res + fun(s,t,cur_s,i+1,n,dp);
       
        return dp[i][cur_s]=res % mod;
    }
    int numDistinct(string s, string t){
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        
        return (fun(s,t,0,0,s.size(),dp)) % mod;
    }
};