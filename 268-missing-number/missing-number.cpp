class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int x = 0, n = nums.size();
        for(int i = 0; i < n; i++)x+=nums[i];
        return (n*(n+1)/2 - x);
    }
};