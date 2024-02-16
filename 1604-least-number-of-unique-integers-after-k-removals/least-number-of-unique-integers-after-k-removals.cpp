class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second<b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = arr.size();
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < n ;i++)mpp[arr[i]]+=1;
        vector<pair<int,int>>temp(mpp.begin(),mpp.end());
        sort(temp.begin(),temp.end(),cmp);
        int f=0;
        for(auto &it:temp){
            while(it.second){
                if(k==0){
                    f=1;
                    break;
                }
                it.second-=1;
                k-=1;
            }
            if(f==1)break;
        }
        int c = 0;
        for(auto &it:temp){
            if(it.second==0)c+=1;
        }
        return temp.size()-c;
        
    }
};