class Solution {
public:
    string makeFancyString(string s) {
        int ch = s[0], c = 1;
        string ans = "";
        ans+=s[0];
        for(int i = 1; i < s.size(); i++){//lee c=3
            if(ch==s[i]){
                c+=1;
                if(c<=2){
                    ans+=s[i];
                }
            }else{
                ans += s[i];
                ch=s[i];
                c=1;
            }
        }
        return ans;
    }
};