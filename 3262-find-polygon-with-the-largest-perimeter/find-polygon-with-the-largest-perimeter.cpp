class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // 1 1 2 3 5  12 50 i
        // 1 2 4 7 12 24 74 j 
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        // 5  5  5
        // 5 10 15
        long long n = nums.size();
        vector<long long>prefix(n,0);
        sort(nums.begin(),nums.end());
        prefix[0]=nums[0];
        for(long long i = 1 ; i < n ; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        long long i = n-1, j=n-2;
        while(i>=0 and j>=0){
            if(nums[i]<prefix[j])return prefix[j+1];
            i-=1;
            j-=1;
        }
        return -1;


    }
};