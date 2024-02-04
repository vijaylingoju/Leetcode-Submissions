class Solution {
public:
    bool fun(vector<int>&vis1,vector<int>&vis2){
        for(int i = 0 ; i < 58; i++){
            if(vis1[i] and vis2[i]<vis1[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.size(),m=t.size();
        string ans="";
        vector<int>vis1(58,0);
        vector<int>vis2(58,0);
        for(int i=0; i<m;i++){
            vis1[t[i]-'A']+=1;
        }
        int start,len=INT_MAX;
        while(j<n){
             vis2[s[j]-'A']+=1;
             while(fun(vis1,vis2)){
                if(j-i+1<len){
                    start=i;
                    len=j-i+1;
                }
                vis2[s[i++]-'A']-=1;
             }
             j+=1;
        }
        // cout<<start<<" "<<len<<endl;
        if(len==INT_MAX)return "";
        return s.substr(start,len);
        
    }
};