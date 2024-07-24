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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==n-1 and j==m-1){
                    dp[i][j] = grid[n-1][m-1];
                }else{
                    int down = grid[i][j];
                    if(i<n-1){
                        down += dp[i+1][j];
                    }else{
                        down += 1e9;
                    }
                    int right = grid[i][j];
                    if(j<m-1){
                        right += dp[i][j+1];
                    }else{
                        right += 1e9;
                    }
                    dp[i][j] = min(down,right);
                }
            }
        }
        for(auto it:dp){
            for(int i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return dp[0][0];
    }
};