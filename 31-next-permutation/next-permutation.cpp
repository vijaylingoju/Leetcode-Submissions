class Solution {
public:
    void swap(int i, int break_point, vector<int>&nums){
        int temp = nums[i];
        nums[i] = nums[break_point];
        nums[break_point] = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int break_point = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i]<nums[i+1]){
                break_point=i;
                break;
            }
        }
        // cout<<break_point<<endl;
        if(break_point==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int max_than_break_point = break_point;
            for(int i = n-1; i > break_point; i--){
                if(nums[i]>nums[break_point]){
                    swap(i,break_point,nums);
                    break;
                }
            }
            reverse(nums.begin()+break_point+1,nums.end());
        }
    }
};