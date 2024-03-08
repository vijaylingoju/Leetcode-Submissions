class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_freq = 0, n = nums.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]+=1;
            max_freq = max(max_freq,mpp[nums[i]]);
        }
        int count = 0;
        for(auto it:mpp){
            if(it.second==max_freq)count+=1;
        }
        return count*max_freq;
    }
};