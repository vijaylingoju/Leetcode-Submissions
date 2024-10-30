class Solution {
public:
    // int fun(int prev, int i, int flag, int n, vector<int>& arr){
        

    //     for(int ind = i + 1; ind < n; ind++){
    //         if(prev<arr[i]){
    //             pick = fun(i,ind,flag,n,arr);
    //         }
            
    //     }
    // }
    int longestMountain(vector<int>& nums) {
        // int n = arr.aize();
        // return fun(0,1,1,n,arr);
        int mx = 0, up = 0, down = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(down and nums[i-1] < nums[i] or nums[i]==nums[i-1]){
                up=0;
                down=0;
            }
            up += nums[i-1] < nums[i];
            down += nums[i-1] > nums[i];
            if(up and down)mx = max(mx,up+down+1);
        }
        return mx;
    }
};