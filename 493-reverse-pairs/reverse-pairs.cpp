class Solution {
public:
    void merge(int low, int mid, int high, vector<int>&nums){
        vector<int>temp;
        int i = low, j = mid+1;
        while(i<=mid and j<=high){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i+=1;
            }
            else{
                temp.push_back(nums[j]);
                j+=1;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i+=1;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j+=1;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    int countPairs(int low, int mid, int high, vector<int>&nums){
        int c = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            while(right<=high and (long long)nums[i]>2LL*nums[right]){
                right+=1;
            }
            c+=(right - (mid + 1));
        }
        return c;
    }
    int mergeSort(int low, int high, vector<int>&nums){
        if(low>=high)return 0;
        int c = 0;
        int mid = (low+high)/2;
        c+=mergeSort(low,mid,nums);
        c+=mergeSort(mid+1,high,nums);
        c+=countPairs(low,mid,high,nums);
        merge(low,mid,high,nums);
        return c;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};