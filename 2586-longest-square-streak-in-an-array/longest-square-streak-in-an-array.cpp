typedef long long ll;
class Solution {
public:
    map<pair<int,int>,int>dp;
    int fun(int ind, int n, vector<int>& nums, int prev){
        if(ind>=n)return 0;
        if(dp.find({ind,prev+1})!=dp.end())return dp[{ind,prev+1}];
        int pick = 0;
        if(prev==-1 or (ll)((ll)nums[prev]*(ll)nums[prev]) == (ll)nums[ind]){
            pick = 1 + fun(ind+1,n,nums,ind);
        }
        int nopick = fun(ind+1,n,nums,prev);
        return dp[{ind,prev+1}] = max(pick,nopick);
    }
    int longestSquareStreak(vector<int>& nums) {
         sort(nums.begin(), nums.end()); // Sort the numbers in ascending order
    unordered_map<int, int> streaks; // Stores the longest streak ending at each number
    int maxStreak = 0;
    
    for (int num : nums) {
        int root = sqrt(num);
        
        // Check if 'root' squared equals 'num' and if 'root' exists in streaks
        if (root * root == num && streaks.count(root)) {
            streaks[num] = streaks[root] + 1;
        } else {
            streaks[num] = 1; // Start a new streak if no predecessor
        }
        
        maxStreak = max(maxStreak, streaks[num]);
    }
    
    return (maxStreak > 1) ? maxStreak : -1; // Return -1 if no streak > 1
    }
};