class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto op:logs){
            if(op[0]=='.' and op[1]=='.'){
                if(op[2]=='/' and ans!=0)ans-=1;
            }else if(op[0]=='.' and op[1]=='/'){
                continue;
            }else{
                ans+=1;
            }
            cout<<ans<<" "<<op<<endl;
        }
        return ans;
    }
};