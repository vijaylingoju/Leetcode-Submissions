class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), m = t.size(), c = 0;
        unordered_map<char,int>mp;
        for(int i = 0 ; i < n; i++)mp[s[i]]+=1;
        for(int i = 0 ; i < m; i++){
            if(mp.find(t[i])!=mp.end()){
                mp[t[i]]-=1;
                if(mp[t[i]]<=0)mp.erase(t[i]);
            }
            else c+=1;
        }
        int ms = 0;
        for(auto i:mp)ms+=i.second;
        return max(c,ms);

    }
};