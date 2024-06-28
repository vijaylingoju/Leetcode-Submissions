class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n);
        for(auto edge:roads){
            indegree[edge[0]]+=1;
            indegree[edge[1]]+=1;
        }
        vector<int>values(n);
        for(int i = 0; i < n ;i++){
            values[i]=i;
        }
        sort(values.begin(), values.end(), [&](int a, int b) {
            return indegree[a] > indegree[b];
        });

        long long ans = 0;
        for(int i = 0; i < n ; i++){
            ans+=(long long)(n-i)*indegree[values[i]];
        }
        return ans;
    }
};