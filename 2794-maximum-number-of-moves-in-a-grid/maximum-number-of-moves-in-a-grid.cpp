class Solution {
public:
    int fun(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>>&dp){
        if(i>=n or j>=m or i<0 or j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int tr = 0, rr = 0, br = 0;

        if(i-1>=0 and j+1<m and grid[i][j] < grid[i-1][j+1]){
            tr = 1 + fun(i-1,j+1,n,m,grid,dp);
        }
        if(j+1<m and grid[i][j] < grid[i][j+1]){
            rr = 1 + fun(i,j+1,n,m,grid,dp);
        }
        if(i+1<n and j+1<m and grid[i][j] < grid[i+1][j+1]){
            br = 1 + fun(i+1,j+1,n,m,grid,dp);
        }
        return dp[i][j] = max({tr,rr,br});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0 ; i < n; i++){
            mx = max(mx,fun(i,0,n,m,grid,dp));
        }
        return mx;
    }
};