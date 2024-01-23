class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        int mx = 0;
        for(int i = 0; i < (1<<n); i++){
            vector<int>vis(26,0);
            for(int j = 0; j < n; j++){
                if((i>>j)&1){
                    int f=0;
                    // cout<<arr[j]<<" ";
                    for(auto it:arr[j]){
                        vis[it - 'a']+=1;
                        if(vis[it - 'a']>1)f=1;  
                    }
                    if(f==0){
                        int c =0;
                        for(int i = 0; i < 26; i++){
                            if(vis[i])c+=1;
                        }
                        mx=max(mx,c);
                    }
                    else{
                        for(auto it:arr[j]){
                            vis[it - 'a']-=1;
                        }
                    }
                }
            }
            
            // cout<<endl;
        }
        return mx;
    }
};