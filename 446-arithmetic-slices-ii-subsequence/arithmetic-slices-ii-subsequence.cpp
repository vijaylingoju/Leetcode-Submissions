class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
           map<long long,map<long long, long long>>mp;
           long long ans = 0, n = nums.size();
           for(int i = 1; i < n; i++){
               for(int j = 0; j < i; j++){
                   long long diff = 1ll*nums[i]-1ll*nums[j];
                   if(mp[j].find(diff)!=mp[j].end()){
                       int p =mp[j][diff]+1;
                       ans+=mp[j][diff];
                       mp[i][diff]+=p;
                    
                   }
                   else{
                       mp[i][diff]+=1;
                   }
               }
           }
           return (int)ans;
    }
}; 