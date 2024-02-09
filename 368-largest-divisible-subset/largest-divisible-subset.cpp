class Solution {
public:
    int mx=0;
    vector<int>ans;
    void fun(int i, int n, vector<int>&nums, vector<int>&ds, vector<int>&dp){
        if(i==n){
            if(ds.size()>ans.size()){
                ans=ds;
            }
            return;
        }
        if(dp[i]<(int)ds.size() and (ds.empty() or nums[i]%ds.back()==0)){
            dp[i]=ds.size();
            ds.push_back(nums[i]);
            fun(i+1,n,nums,ds,dp);
            ds.pop_back();
        }
        fun(i+1,n,nums,ds,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,-1);
        vector<int>ds;
        fun(0,n,nums,ds,dp);
        return ans;
    }
};