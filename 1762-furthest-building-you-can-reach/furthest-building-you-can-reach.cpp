class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = heights.size(),i,j,b=bricks,l=ladders;
        priority_queue<int>pq;
        for(i = 0; i < n-1; i++)
        {
            
               int x = heights[i+1]-heights[i];
                if(x<0)continue;
                bricks-=x;
                pq.push(x);
                if(bricks<0)
                {
                    int k = pq.top();
                    pq.pop();
                    bricks+=k;
                    ladders-=1;
                }
                
                if(ladders<0)
                {
                    break;
                }
        }
       return i;
    }
};