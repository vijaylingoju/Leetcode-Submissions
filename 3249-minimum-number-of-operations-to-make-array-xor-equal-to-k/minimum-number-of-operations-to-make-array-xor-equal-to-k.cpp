class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0, c = 0;
        for(int i = 0; i < nums.size(); i++)x^=nums[i];
        for(int i = 0; i < 32; i++){
            if((k&(1<<i))!=(x&(1<<i)))c+=1;
        }
        return c;
    
    }
};