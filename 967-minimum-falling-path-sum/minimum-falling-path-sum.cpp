class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m= matrix[0].size();
        if(n==1)return matrix[0][0];
        vector<int>prev;
        vector<int>curr(m,1e9);
        for(int i = 0 ; i < m; i++)prev.push_back(matrix[n-1][i]);
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(j==0){
                    curr[j]=matrix[i][j]+min(prev[j],prev[j+1]);
                }
                else if(j==m-1){
                    curr[j]=matrix[i][j]+min(prev[j],prev[j-1]);
                }
                else{
                    curr[j]=matrix[i][j]+min(prev[j],min(prev[j-1],prev[j+1]));
                }
            }
            prev=curr;
        }
        int mi = INT_MAX;
        for(auto i :curr){
            mi=min(mi,i);
        }
        return mi;
    }
};