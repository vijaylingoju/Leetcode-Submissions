class Solution {
public:
    set<vector<int>>ss;
    void fun(int i, int n, vector<int>&nums, int k, vector<int>&ds){
        if(k<0)return;
        if(k==0){
            ss.insert(ds);
            return;
        }
        if(i>=n)return;
        int j = i+1;
        while(j<n and nums[j]==nums[i])j++;
        fun(j,n,nums,k,ds);

        ds.push_back(nums[i]);
        fun(i+1,n,nums,k-nums[i],ds);
        ds.pop_back();

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        fun(0,n,nums,k,ds);
        for(auto it:ss){
            ans.push_back(it);
        }
        return ans;
    }
};