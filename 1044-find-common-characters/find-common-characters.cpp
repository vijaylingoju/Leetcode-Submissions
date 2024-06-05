class Solution {
public:
    void fun(string word, vector<int>&ref){
        vector<int>temp(26,0);
        for(int i = 0; i < word.size(); i++){
            temp[word[i]-'a']+=1;
        }
        for(int i = 0; i < 26; i++){
            ref[i]=min(ref[i],temp[i]);
        }
        
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int>ref(26,0);
        for(int i = 0; i < words[0].size(); i++){
            ref[words[0][i]-'a']+=1;
        }
        int n = words.size();
        
        for(int i = 1; i < n; i++){
            fun(words[i],ref);
        }
        vector<string>ans;
        for(int i = 0; i < 26; i++){
            if(ref[i]!=0){
                char ch = (i+'a');
                for(int j = 1; j <= ref[i]; j++){
                    ans.push_back(string(1, ch));
                }
            }
        }
        return ans;
    }
};