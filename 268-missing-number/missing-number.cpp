class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = nums.size(), sum = n*(n+1)/2;
        int x=sum - accumulate(nums.begin(),nums.end(),0);
        return x;
    }
};