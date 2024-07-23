class Solution {
public:
    int findNextIndex(int curr, vector<vector<int>>&rides,int n){
        int left = 0, right = n - 1, ans = n;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(rides[mid][0]>=curr){
                ans=mid;
                right = mid - 1;  
            }else{
                left = mid + 1; 
            }
        }
        return ans;
    }
    long long fun(int i,vector<vector<int>>&rides, int size, vector<long long>&dp){
        if(i>=size)return 0;
        if (dp[i] != -1) return dp[i]; 
        long long nopick = fun(i+1,rides,size,dp);
        int nxt_i = findNextIndex(rides[i][1],rides,size);
        long long cost = rides[i][1] - rides[i][0] + rides[i][2];
        long long pick = cost + fun(nxt_i,rides,size,dp);
        return dp[i] = max(pick,nopick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int size = rides.size();
        vector<long long>dp(size+1,-1LL);
        return fun(0,rides,size,dp);
    }
};