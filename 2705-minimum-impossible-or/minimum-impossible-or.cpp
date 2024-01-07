class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = nums.size();

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