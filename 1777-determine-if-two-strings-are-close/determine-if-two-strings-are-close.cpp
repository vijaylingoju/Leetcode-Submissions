class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1!=n2)return 0;
        vector<int>x(26,0);
        vector<int>y(26,0);
        for(int i = 0; i < n1; i++)x[word1[i]-'a']+=1;
        for(int i = 0; i < n2; i++){
            if(x[word2[i]-'a']==0)return 0;
            
            y[word2[i]-'a']+=1;
        }
            
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        for(int i = 0; i < 26; i++){
            if(x[i]!=y[i] or (x[i]==0 and y[i]) or (x[i] and y[i]==0))return 0;
        }
        return 1;

    }
};