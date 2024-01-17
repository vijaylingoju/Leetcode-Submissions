class Solution {
public:
vector<vector<int>>ans;
    void fun(vector<int>&arr, int n, vector<int>&vis, vector<int>&ds){
        if(ds.size()==n){
            ans.push_back(ds);
            return ;
        }
        for(int i = 0 ; i < n; i++){
            if(vis[i]==0){
                ds.push_back(arr[i]);
                vis[i]=1;
                fun(arr,n,vis,ds);
                vis[i]=0;
                ds.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        vector<int>ds;
        fun(nums,nums.size(),vis,ds);
        
        return ans;
    }
};