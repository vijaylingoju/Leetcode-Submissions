class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = nums.size();
        int x=accumulate(nums.begin(),nums.end(),0);
        return (n*(n+1)/2 - x);
    }
};