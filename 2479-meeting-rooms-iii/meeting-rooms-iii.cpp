class Solution {
public:
    typedef long long ll; 
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        ll m = meetings.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>vis(n,0),ans(n,0);
        for(ll i = 0; i < m; i++){
            ll st = meetings[i][0];
            while(!pq.empty() and pq.top().first<=st){
                vis[pq.top().second]=0;
                pq.pop();
            }
            ll flag = 1;
            for(ll j = 0; j < n; j++){
                if(vis[j]==0){
                    flag=0;
                    pq.push({meetings[i][1],j});
                    vis[j]=1;
                    ans[j]+=1;
                    break;
                }
            }
            if(flag){
                ll mi_end = pq.top().first;
                ll mi_i= pq.top().second;
                pq.pop();
                pq.push({(meetings[i][1]-meetings[i][0]) + mi_end,mi_i});
                ans[mi_i]+=1;
            }
            
        }
        for(auto it:ans){
                cout<<it<<" ";
            }
        ll maxx = 0, maxx_i = 0;
        for(ll i = 0; i < n; i++){
            if(maxx<ans[i]){
                maxx=ans[i];
                maxx_i=i;
            }
        }
        return maxx_i;
    }
};