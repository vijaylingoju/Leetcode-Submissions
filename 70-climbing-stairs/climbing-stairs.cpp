class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==2 or n==3)return n;
        int p=2,q=3,r=0;
        for(int i = 4; i <=n; i++){
            r=p+q;
            p=q;
            q=r;
        }
        return r;
    }
};