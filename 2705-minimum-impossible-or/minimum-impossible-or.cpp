class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int mx = nums[0], n = nums.size();
        for(int i = 1; i < nums.size(); i++)if(mx<nums[i])mx=nums[i];
        int k = floor(log2(mx));
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++)mp[nums[i]]+=1;
        int i = 0;
        while(true){
            if(mp.find((1<<i))==mp.end())
            {
                return (1<<i);
            }
            i+=1;
        }
        
        
    }
};