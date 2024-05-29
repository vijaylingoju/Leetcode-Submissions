class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
                int k = s.size()-1;
                while(k>=0 and s[k]!='0'){
                    s[k]='0';
                    k--;
                }
                if(k<0){
                    s = '1' + s;
                }
                else{
                    s[k]='1';
                }
            }
            ans+=1;
        }
        return ans;
    }
};