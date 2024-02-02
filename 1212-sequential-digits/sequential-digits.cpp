class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        for(int i = 0; i < s.size(); i++){
            string x="";
            for(int j = i; j < s.size(); j++){
                x+=s[j];
                int n = stoi(x);
                if(n>=low and n<=high){
                    ans.push_back(n);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};