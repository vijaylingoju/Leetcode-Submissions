int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
class Solution {
public:
    bool canJump(vector<int>& A) {
        int n=A.size(),k = n-1;
        for(int i = n-1; i >= 0; i--){
            if(A[i]+i>=k){
                k = i;
            }
            // co0ut<<k<<" ";
        }
        return k==0;
    }
};