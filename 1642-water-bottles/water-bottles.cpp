class Solution {
public:
    int numWaterBottles(int n, int x) {
        int ans = n;
        int emp = n;
        while(emp>=x){
            ans+=emp/x;//15+3 = 18//18+1 = 19
            emp=emp%x + emp/x;//3+3 = 6// 2+1=3
        }
        return ans;
    }
};