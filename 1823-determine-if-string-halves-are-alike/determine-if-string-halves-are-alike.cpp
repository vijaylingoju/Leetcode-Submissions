class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), c = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i = 0 ; i < n; i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cout<<c<<" ";
                if(i<n/2)c+=1;
                else c-=1;
            }
        }
        
        return c==0;
    }
};