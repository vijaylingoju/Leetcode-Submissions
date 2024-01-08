class Solution {
public:
    int fun(int n){
        if((n&(n-1))==0)return 1;
        int k = floor(log2(n));
        int a = n-(1<<k), b = (1<<(k+1))-n;
        int p = 1+fun(a);
        int q = 1+fun(b);
        return min(p,q);

        return k;
    }
    int minOperations(int n) {
        
        return fun(n);
    }
};