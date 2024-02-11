class Solution {
public:
    int dp[142][71][71];
    int fun(int i, int j, int x, int y, vector<vector<int>>&grid, int n, int m){
        if(i>=n or x>=n or j<0 or j>=m or y<0 or y>=m)return 0;
        if(i==n-1 and x==n-1) return grid[i][j]+grid[x][y];
        int mx = 0;
        if(dp[i+j][x][y]!=-1) return dp[i+j][x][y];
        for(int a = -1; a<=1; a++){
            for(int b = -1; b<=1; b++){
                int ii = i+1, xx = x+1;
                int jj = j+a, yy = y+b;
                if(ii==xx and jj==yy)continue;
                mx=max(mx,fun(ii,jj,xx,yy,grid,n,m)); 
            } 
        }
        return dp[i+j][x][y]=(mx+grid[i][j]+grid[x][y]);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0,m-1,grid,n,m);
    }
};