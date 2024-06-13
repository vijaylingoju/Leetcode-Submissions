class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0,ele;
        for(int i = 0; i < n; i++){
            if(count==0){
                count=1;
                ele = nums[i];
            }
            else if(nums[i]==ele){
                count+=1;
            }
            else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ele==nums[i]){
                cnt++;
            }
        }
        if(cnt>=(n/2))return ele;
        else return -1;//if majority element doesn't exist
    }
};