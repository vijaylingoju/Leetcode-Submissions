class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k,s1=nums[0],n=nums.size();
        for(int i=1;i<n;i++){
            s1+=nums[i];
            if(nums[i]==nums[i-1]){
                k=nums[i];
            }
        }
        int s=((n*(n+1)/2))-(s1-k);
        return {k,s};
    }
};