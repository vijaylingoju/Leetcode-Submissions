class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans = {{},{}};
        map<int,pair<int,int>>mpp;
        for(auto x:matches){
            mpp[x[0]].first+=1;
            mpp[x[1]].second+=1;
        }
        for(auto i:mpp){
            if(i.second.second==0)ans[0].push_back(i.first);
            if(i.second.second==1)ans[1].push_back(i.first);
        }
        
        return ans;

    }
};