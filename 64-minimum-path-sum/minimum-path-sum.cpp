class Solution {
public:
    int fun(int i, int j, vector<vector<int>>&grid, int n, int m,vector<vector<int>>&dp){
        if(i==n-1 and j==m-1)return grid[n-1][m-1];
        if(i>=n or j>=m)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int down = grid[i][j]+fun(i+1,j,grid,n,m,dp);
        int right = grid[i][j]+fun(i,j+1,grid,n,m,dp);
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,grid,n,m,dp);
    }
};