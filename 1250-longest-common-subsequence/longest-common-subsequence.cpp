class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size(),n=t2.size();
        int dp[m+1][n+1],i,j;
        for(i=0;i<m+1;i++)
        {
            dp[i][0]=0;
        }
        for(i=1;i<n+1;i++)
        {
            dp[0][i]=0;
        }
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                
                if(t1[i-1]==t2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};