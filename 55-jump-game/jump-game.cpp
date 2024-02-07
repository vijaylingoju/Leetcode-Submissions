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