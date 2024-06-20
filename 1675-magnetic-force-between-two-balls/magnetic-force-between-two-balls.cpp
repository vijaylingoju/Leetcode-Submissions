class Solution {
public:
    long long fun(vector<int>&position,int n, int m){
        long long i = 1, j = position.back() - position[0];
        long long ans = LLONG_MIN;
        while(i<=j){
            long long mid = (i+j)/2;
            long long prev = 0, count = 1, p = 1;
            while(p<n){
                if((position[p] - position[prev])>=mid){
                    count+=1;
                    prev=p;
                }
                p+=1;
            }
            if(count>=m){
                ans=max(ans,mid);
                i=mid+1;
            }
            else{
                j=mid-1;
            }

        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        return (int)fun(position,n,m);
    }
};