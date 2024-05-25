class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        vector<int>ans;
        for(auto it:queries){
            if(mpp1.find(it[0])!=mpp1.end()){
                mpp2[mpp1[it[0]]]-=1;
                if(mpp2[mpp1[it[0]]]==0){
                    mpp2.erase(mpp1[it[0]]);
                }
            }
            mpp1[it[0]]=it[1];
            
            mpp2[it[1]]+=1;
            ans.push_back(mpp2.size());
        }
        return ans;
    }
};