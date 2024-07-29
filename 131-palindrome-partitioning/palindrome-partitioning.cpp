class Solution {
public:
    bool isPal(string s){
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            if(s[i]!=s[j])return false;
        }
        return true;
    }
    void fun(int i,int n, string &s,vector<string>&ds, vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        if(i>n)return;
        for(int ind = i; ind < n; ind++){
            string prefix = s.substr(i,ind - i + 1);
            // cout<<ind<<" "<<i<<endl;
            
            if(isPal(prefix)){
                ds.push_back(prefix);
                fun(ind+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>ds;
        fun(0,n,s,ds,ans);
        return ans;    
    }
};