class Solution {
public:
    int dp[10001];
    int fun(int i, int n, vector<int>& nums) {
        if (i == n - 1)
            return 0;
        if (i >= n)
            return 1e9;
        int x = 1e9;
        if(dp[i]!=-1)return dp[i];
        for (int j = 1; j <= nums[i]; j++) {
            if ((i + j) < n)
                x = min(x, 1 + fun(i + j, n, nums));
        }
        return dp[i]=x;
    }
    int jump(vector<int>& nums) { 
        memset(dp,-1,sizeof(dp));
        return fun(0, nums.size(), nums); 
    }
};