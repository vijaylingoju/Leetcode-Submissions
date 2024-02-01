class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(nums[0]);
        int i = 1;
        cout<<nums.size()<<endl;
        while (i < n) {
            if ((i + 1) % 3 == 0) {
                if (abs(temp[0] - nums[i]) <= k) {
                    temp.push_back(nums[i]);
                } else {
                    return {};
                }
                ans.push_back(temp);
                temp.clear();
                if (i == n - 1) return ans;
                temp.push_back(nums[i + 1]);  
                i += 2;  
            } else {
                if (abs(temp[0] - nums[i]) <= k) {
                    temp.push_back(nums[i]);
                } else {
                    return {};
                }
                i += 1;
            }
        }
        return ans;
    }
};