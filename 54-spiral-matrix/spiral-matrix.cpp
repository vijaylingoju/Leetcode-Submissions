class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int top=0,bottom=r-1,left=0,right=c-1;
        int dir = 0,i;
        vector<int>v;
        while(top<=bottom && left<=right)
        {
            if(dir==0)
            {
                for(i = left; i <=right; i++)
                {
                v.push_back(matrix[top][i]);
                }
                top+=1;
            }
            else if(dir==1)
            {
                for(i=top;i<=bottom;i++)
                {
                    v.push_back(matrix[i][right]);
                }
                right-=1;
            }
            else if(dir==2)
            {
                for(i=right;i>=left;i--)
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom-=1;
            }
            else if(dir==3)
            {
                for(i=bottom;i>=top;i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left+=1;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};