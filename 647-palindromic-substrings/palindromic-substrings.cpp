class Solution {
public:
    bool ispalin(string k){
        int i=0,j=k.size()-1;
        while(i<j){
            if(k[i]!=k[j])return false;
            i+=1;
            j-=1;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size(),c=0;
        for(int i = 0; i < n; i++){
            string k="";
            for(int j=i;j<n;j++){
                k+=s[j];
                if(ispalin(k))c+=1;
            }
        }
        return c;
    }
};