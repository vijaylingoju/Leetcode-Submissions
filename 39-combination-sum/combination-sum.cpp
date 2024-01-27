class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i, int n, vector<int>&arr, int k, vector<int>&ds){
        if(i>=n)return;
        if(k<0)return;
        if(k==0){
            ans.push_back(ds);
            return;
        }
        if(k>=arr[i]){
            ds.push_back(arr[i]);
            fun(i,n,arr,k-arr[i],ds);
            ds.pop_back();
        }
        fun(i+1,n,arr,k,ds);
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int>ds;
        fun(0,arr.size(),arr,k,ds);
        return ans;
    }
};