class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int fun(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp){
        
        if(startRow>=m or startColumn>=n or startRow<0 or startColumn<0)return 1;
        
        if(maxMove==0) return 0;
        if(dp[maxMove][startRow][startColumn]!=-1)return dp[maxMove][startRow][startColumn];
        ll x = 0;
        x+= fun(m,n,maxMove-1,startRow-1,startColumn,dp)%mod;
        x%=mod;
        x+= fun(m,n,maxMove-1,startRow,startColumn+1,dp)%mod;
        x%=mod;
        x+= fun(m,n,maxMove-1,startRow+1,startColumn,dp)%mod;
        x%=mod;
        x+= fun(m,n,maxMove-1,startRow,startColumn-1,dp)%mod;
        x%=mod;

        return dp[maxMove][startRow][startColumn]=x%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return fun(m,n,maxMove,startRow,startColumn,dp)%mod;
    }
};