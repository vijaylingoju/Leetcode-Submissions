class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            for(int j = i+1; j < n; j++){
                if(j>i+1 and nums[j]==nums[j-1])continue;
                int k = j+1, l = n-1;
                
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l and nums[k]==nums[k+1])k++;
                        while(k<l and nums[l]==nums[l-1])l--;
                        k+=1;
                        l-=1;
                    }else if(sum<target){
                        k+=1;
                    }else{
                        l-=1;
                    }//1i 1j 1k 2 2 2  2 4  4 4l
                }
            }
        }
        return ans;
    }
};