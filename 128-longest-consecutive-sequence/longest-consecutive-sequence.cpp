class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int c=1,mx=0;
        for(int i = 1; i < n; i++){
            if((nums[i])==nums[i-1])continue;
            if((nums[i]-1)==nums[i-1])c+=1;
            else{
                mx=max(mx,c);
                c=1;
            }
        }
        mx=max(mx,c);

        return mx;
    }
};