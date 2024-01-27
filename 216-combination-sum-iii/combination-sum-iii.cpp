class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i, int n, vector<int>&arr, int k, vector<int>&ds,int s){
        if(s==0){
            if(k==ds.size())ans.push_back(ds);
            return;
        }
        if(i>=n)return;
        if(arr[i]<=s){
            ds.push_back(arr[i]);
            fun(i+1,n,arr,k,ds,s-arr[i]);
            ds.pop_back();
        }
        fun(i+1,n,arr,k,ds,s);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        vector<int>ds;
        for(int i = 1; i < 10; i++)arr.push_back(i);
        fun(0,arr.size(),arr,k,ds,n);
        return ans;
    }
};