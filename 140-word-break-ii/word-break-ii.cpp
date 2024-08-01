class Solution {
public:
    bool isPresent(int i, int ind, unordered_map<string,int>&mpp, string s){
        if(mpp.find(s.substr(i,ind-i+1))!=mpp.end())return true;
        return false;
    }
    void fun(int i, string s, unordered_map<string,int>&mpp, vector<vector<string>>&ans, vector<string>&curr){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int ind = i; ind < s.size(); ind++){
            if(isPresent(i,ind,mpp,s)){
                curr.push_back(s.substr(i,ind-i+1));
                fun(ind+1,s,mpp,ans,curr);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mpp;
        for(auto it:wordDict){
            mpp[it]=1;
        }
        vector<vector<string>>ans;
        vector<string>curr;
        fun(0,s,mpp,ans,curr);
        vector<string>v;
        for(auto it:ans){
            string p="";
            for(auto jt:it){
                p+=jt + " ";
            }
            p.pop_back();
            v.push_back(p);
        }
        return v;
    }
};