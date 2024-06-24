class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string s = "11";
        n-=2;
        while(n--){
            int count = 1;
            string temp = "";
            int i = 0;
            for(i = 0; i < s.size()-1; i++){
                if(s[i]!=s[i+1]){
                    temp+=to_string(count);
                    temp+=s[i];
                    count=1;
                }else{
                    count+=1;
                }
            }
            temp+=to_string(count);
            temp+=s[i];
            cout<<temp<<endl;
            s=temp;
        }
        return s;
    }
};