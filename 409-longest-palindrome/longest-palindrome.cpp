class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(),check_odd=false;
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }
        int ans = 0,max_odd=0;
        for(auto it:mpp){
            if(it.second%2==0){
                ans+=it.second;
            }
            else{
                check_odd=true;
                if(it.second>1)ans+=it.second-1;
            }
        }
        return check_odd? ans+1:ans;
        
    }
};