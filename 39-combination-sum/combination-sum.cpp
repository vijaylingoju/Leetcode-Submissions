class Solution {
public:
    void fun(int i, int n, vector<int>&nums, int k,vector<int>&ds, vector<vector<int>>&ans){
        if(i>=n)return;
        if(k==0){
            ans.push_back(ds);
            return;
        }
        fun(i+1,n,nums,k,ds,ans);
        if(nums[i]<=k){
            ds.push_back(nums[i]);
            fun(i,n,nums,k-nums[i],ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>ds;
        fun(0,n,nums,target,ds,ans);
        return ans;
    }
};