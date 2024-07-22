class Solution {
public:
    int fun(int i, int j, string &a, string &b, vector<vector<int>>&dp){
        if(i<0 or j<0)return 0;
        int pick = INT_MIN;
        int nopick = INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            pick = 1 + fun(i-1,j-1,a,b,dp);
        }
        else{
            nopick = max(fun(i-1,j,a,b,dp),fun(i,j-1,a,b,dp));
        }
        return dp[i][j]=max(pick,nopick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < m + 1; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};