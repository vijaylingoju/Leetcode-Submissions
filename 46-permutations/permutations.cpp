class Solution {
public:
    void fun(int i, int n, vector<vector<int>>&ans, vector<int>&nums){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int ind = i; ind < n; ind++){
            swap(nums[i],nums[ind]);
            fun(i+1,n,ans,nums);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,nums.size(),ans,nums);
        return ans;
    }
};