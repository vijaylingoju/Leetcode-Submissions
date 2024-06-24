class Solution {
public:
    int fun(int m, int n,vector<vector<int>>&dp, vector<vector<int>>& grid){
        if(n<0 or m<0 or grid[m][n]==1)return 0;
        if(m==0 and n==0)return 1;
        
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=fun(m-1,n,dp,grid)+fun(m,n-1,dp,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,dp,grid);
    }
};