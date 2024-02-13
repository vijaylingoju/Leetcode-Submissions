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
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i = 0; i < n; i++){
            string s = words[i];
            if(ispalin(s))return s;
        }
        return "";
    }
};