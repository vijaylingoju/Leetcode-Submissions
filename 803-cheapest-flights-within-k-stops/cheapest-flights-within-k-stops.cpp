class Solution {
public:
    int dp[101][101];
    
    int fun(int i, int dst, int k, unordered_map<int,vector<pair<int,int>>>& adj) {
        if (k < 0) return 1e9;
        if ( i == dst) return 0;
        if (dp[i][k] != -1) return dp[i][k]; 
        int mi = 1e9;
        for (auto pr : adj[i]) {
                int cost = pr.second + fun(pr.first, dst, k - 1, adj);
                // if(cost==1e9)continue;
                mi = min(mi, cost);
        }
        return dp[i][k] = mi; 
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof(dp));
        unordered_map<int,vector<pair<int,int>>> adj;
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        int check = fun(src, dst, k + 1, adj);
        return check == 1e9 ? -1 : check;
    }
};
