class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int oc = 0;
        int c = 0, n = flowerbed.size();
        for(int i = 0 ; i < n; i++){
            if(flowerbed[i]==0){
                oc+=1;
            }else{

                if(oc==i or i==n){
                    c+=(int)oc/2;
                }else{
                    c+=(int)(oc-1)/2;
                }
                oc=0;
            }

        }
        if(n==oc){
            c+=ceil(oc/2.0);
        }
        else{
            c+=(int)oc/2;
        }
        return c>=k;
    }
};