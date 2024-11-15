class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int peak = 0;
        while(peak < n - 1 and arr[peak] <= arr[peak + 1]){
            peak += 1;
        }
        int valley = n - 1;
        while(valley > peak and arr[valley - 1] <= arr[valley]){
            valley -= 1;
        }

        ans = min(n - peak - 1, valley);
        int i = 0, j = valley;
        while(i <= peak and j < n){
            if(arr[j] >= arr[i]){
                ans = min(ans, j - i - 1);
                i += 1;
            } else{
                j += 1;
            }
        }
        return ans==-1? 0: ans;
    }
};