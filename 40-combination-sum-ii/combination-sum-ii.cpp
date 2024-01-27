class Solution {
public:
    vector<vector<int>>ans;
    map<vector<int>,int>mpp;
    void fun(int i, int n, vector<int>&arr, int k, vector<int>&ds,vector<vector<int>>&dp){
        
        if(k<0)return;
        if(k==0){
            if(mpp.find(ds)==mpp.end())ans.push_back(ds);
            mpp[ds]+=1;
            return;
        }
        if(i>=n)return;
        if(k>=arr[i]){
            ds.push_back(arr[i]);
            fun(i+1,n,arr,k-arr[i],ds,dp);
            ds.pop_back();
        }
        int j = i+1;
        while(j<n and arr[j]==arr[j-1])j+=1;
        fun(j,n,arr,k,ds,dp);

        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        vector<int>ds;
        vector<vector<int>>dp(arr.size()+1,vector<int>(k+1,-1));
        sort(arr.begin(),arr.end());
        fun(0,arr.size(),arr,k,ds,dp);
        return ans;
    }
};