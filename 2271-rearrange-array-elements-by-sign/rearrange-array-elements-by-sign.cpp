class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        vector<int>pos,neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        vector<int>ans;
        for(int i = 0; i < nums.size()/2; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;

    }
};