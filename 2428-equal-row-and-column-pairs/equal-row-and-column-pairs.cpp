class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mpp;
        for(auto it:grid){
            mpp[it]+=1;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>temp(m,vector<int>(n,-1));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                temp[j][i] = grid[i][j];
            }
        }
        int count = 0;
        for(auto it:temp){
            if(mpp.find(it)!=mpp.end()){
                count+=mpp[it];
            }
        }
        return count;
    }
};