class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool flag = false;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i]!=' '){
                flag=true;
                cnt++;
            }
            else if(flag){
                break;
            }
        }
        return cnt;
    }
};