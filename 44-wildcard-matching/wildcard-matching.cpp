class Solution {
public:
    bool fun(int ps, int ns, string &s, string &p, vector<vector<int>>&dp){
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        if(ps<0 and ns<0)return true;
        if(ps<0 and ns>=0)return false;
        if(ps>=0 and ns<0){
            while(ps>=0){
                if(p[ps]!='*')return false;
                ps-=1;
            }
            return true;
        }
        if(dp[ps][ns]!=-1)return dp[ps][ns]; 
        if(p[ps]==s[ns] or  p[ps]=='?')return dp[ps][ns]=fun(ps-1,ns-1,s,p,dp);
        
        if(p[ps]=='*'){
            return dp[ps][ns]=fun(ps-1,ns,s,p,dp) | fun(ps,ns-1,s,p,dp);
        } 
        return dp[ps][ns]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(p.size()+1,vector<int>(s.size()+1,-1));
        return fun(p.size()-1,s.size()-1,s,p,dp);
    }
};