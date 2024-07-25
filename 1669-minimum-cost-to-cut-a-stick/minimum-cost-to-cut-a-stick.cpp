class Solution {
public:
    int dp[105][105];
    int dfs(vector<int>& cuts, int i, int j,vector<vector<int>>&dp) {
        if (j - i <= 1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;

        for (int k = i + 1; k < j; k++) {
            ans = min(ans, cuts[j] - cuts[i] + dfs(cuts, i, k,dp) + dfs(cuts, k, j,dp));
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(105,vector<int>(105,-1));
        int ans = dfs(cuts, 0, cuts.size() - 1,dp);
        // for(auto it:dp){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};