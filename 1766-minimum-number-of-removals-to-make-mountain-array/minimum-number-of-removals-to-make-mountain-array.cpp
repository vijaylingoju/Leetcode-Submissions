class Solution {
public:
    void getLeftLIS(int n, vector<int>& nums, vector<int> &prefix){
        vector<int>ele;

        for(int  i = 0; i < n; i++){
            if(ele.size()==0 or ele.back()<nums[i]){
                ele.push_back(nums[i]);
                prefix[i] = ele.size();
            } else{
                auto it = lower_bound(ele.begin(),ele.end(),nums[i]) - ele.begin();
                ele[it] = nums[i];
                prefix[i] = it + 1;
            }
        }
    }
    void getRightLIS(int n, vector<int>& nums, vector<int> &suffix){
        vector<int>ele;

        for(int  i = n-1; i > 0; i--){
            if(ele.size()==0 or ele.back()<nums[i]){
                ele.push_back(nums[i]);
                suffix[i] = ele.size();
            } else{
                auto it = lower_bound(ele.begin(),ele.end(),nums[i]) - ele.begin();
                ele[it] = nums[i];
                suffix[i] = it + 1;
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        getLeftLIS(n,nums,prefix);
        getRightLIS(n,nums,suffix);
        for(int a:prefix){
            cout<<a<<" ";
        }
        cout<<"\n";
        for(int a:suffix){
            cout<<a<<" ";
        }
        int ansMax = 0;
        for(int i = 1; i < n-1; i++){
            if(prefix[i]>1 and suffix[i]>1){
                ansMax = max(ansMax, prefix[i] + suffix[i] - 1);
            }
        }
        return n - ansMax;
    }
    // 2 1 1 5 6 2 3 1

    
};