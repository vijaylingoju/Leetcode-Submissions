class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        q.push(start);
        vector<int>vis(n,0);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            vis[top]=1;
            if(arr[top]==0)return true;
            if((top+arr[top])<n  and vis[top+arr[top]]==0){
                q.push(top+arr[top]);
            }
            if((top-arr[top])>=0 and vis[top-arr[top]]==0){ 
                q.push(top-arr[top]);   
            }
        }
        return false;
    }
};