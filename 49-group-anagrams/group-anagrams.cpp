class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mpp;
        for(int i = 0; i < strs.size(); i++){
            map<char,int>temp_map;
            for(int j = 0; j  <strs[i].size(); j++){
                temp_map[strs[i][j]]+=1;
            }
                mpp[temp_map].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};