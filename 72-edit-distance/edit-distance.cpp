class Solution {
public:
    int fun(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        if(i<0 and j>=0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];
        int a = 1e9, b = 1e9, c = 1e9, d = 1e9;
        if(word1[i]==word2[j]){
            a = fun(i-1,j-1,word1,word2,dp);
        }else{
            b = 1+fun(i,j-1,word1,word2,dp);//insert
            c = 1+fun(i-1,j,word1,word2,dp);//delete
            d = 1+fun(i-1,j-1,word1,word2,dp);//replace
        }
        return dp[i][j] = min({a,b,c,d});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(n-1,m-1,word1,word2,dp);
    }
};