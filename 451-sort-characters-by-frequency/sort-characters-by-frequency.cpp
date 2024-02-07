class Solution {
public:
    static bool cmp(pair<char,int>& a, pair<char,int>& b) {
        return a.second > b.second; 
    }
    string frequencySort(string s) {
        int n = s.size();
        map<char,int>mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto it:v){
            int k = it.second;
            while(k--){
                ans+=it.first;
            }
        }
        return ans;
    }
};