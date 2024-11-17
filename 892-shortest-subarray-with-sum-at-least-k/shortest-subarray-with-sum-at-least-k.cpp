class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& nums, int k) {
        ll sum = 0; 
        int n = nums.size();
        int ans = INT_MAX; 
        deque<pair<ll, ll>> dq;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k) {
                ans = min(ans, i + 1);
            }

            pair<ll, ll> curr = {INT_MAX, INT_MAX};  // Initialize to INT_MAX
            while (!dq.empty() && (sum - dq.front().second >= k)) {
                curr = dq.front();
                dq.pop_front();
            }

            if (curr.second != INT_MAX) {
                ans = min(ans, static_cast<int>(i - curr.first));
            }

            while (!dq.empty() && sum <= dq.back().second) {
                dq.pop_back();
            }

            dq.push_back({i, sum});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};