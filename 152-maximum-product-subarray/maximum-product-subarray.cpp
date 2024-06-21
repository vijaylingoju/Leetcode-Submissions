class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prefix = 1LL, suffix = 1LL, ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
            if(prefix==0)prefix=1LL;
            if(suffix==0)suffix=1LL;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            ans = max(ans,max(prefix,suffix));
        }
        return (int)ans;
    }
};