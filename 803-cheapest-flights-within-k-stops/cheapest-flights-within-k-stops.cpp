class Solution {
public:
    int dp[101][101]; // Assuming n <= 100
    
    int fun(int i, int dst, int k, unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& vis) {
        //base cases
        if (k < 0) return 1e9;
        if ( i == dst) return 0;
        
        if (dp[i][k] != -1) return dp[i][k]; 
        
        //vis[i] = 1;
        int mi = 1e9;
        for (auto pr : adj[i]) {
            if (vis[pr.first] == 0) {
                int cost = pr.second + fun(pr.first, dst, k - 1, adj, vis);
                if(cost==1e9)continue;
                mi = min(mi, cost);
            }
        }
        //vis[i] = 0;
        return dp[i][k] = mi; 
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof(dp));
        unordered_map<int,vector<pair<int,int>>> adj;
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
    
        
        vector<int> vis(n, 0);
        int check = fun(src, dst, k + 1, adj, vis);
        return check == 1e9 ? -1 : check;
    }
};
