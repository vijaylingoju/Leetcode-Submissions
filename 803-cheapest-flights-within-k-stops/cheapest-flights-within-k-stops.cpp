class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int i = it.second.first;
            int cost = it.second.second;
            if(x>k)continue;
            for(auto it:adj[i]){
                int j = it.first;
                int z = it.second;
                if(cost + z < dist[j] and x<=k){
                    dist[j] = cost + z;
                    q.push({x+1,{j,cost+z}});
                }
            }
        }
        
        if(dist[dst]==1e9)return -1;
        
        return dist[dst];
    }
};