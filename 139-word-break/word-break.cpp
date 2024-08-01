    class Solution {
    public:
        bool isPresent(int i, int ind, unordered_map<string,int>&mpp, string s){
            if(mpp.find(s.substr(i,ind-i+1))!=mpp.end())return true;
            return false;
        }
        bool fun(int i, string s, unordered_map<string,int>mpp, unordered_map<int,bool>&dp){
            if(i==s.size()){
                return true;
            }
            if(dp.find(i)!=dp.end())return dp[i];
            for(int ind = i; ind < s.size(); ind++){
                if(isPresent(i,ind,mpp,s)){
                    if(fun(ind+1,s,mpp,dp)){
                        return dp[i] = true;
                    } 

                }
            }
            return dp[i] = false;
        }
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_map<string,int>mpp;
            for(auto it:wordDict){
                mpp[it]=1;
            }
            unordered_map<int,bool>dp;
            return fun(0,s,mpp,dp);
        }
    };