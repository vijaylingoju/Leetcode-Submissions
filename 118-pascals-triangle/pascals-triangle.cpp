
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        vector<vector<int>>ans={{1},{1,1}};
        if(numRows==2)return ans;
        vector<int>temp = {1,1};
        numRows-=2;
        while(numRows--){
            vector<int>add;
            add.push_back(temp[0]);
            for(int i = 0; i < temp.size()-1;i++){
                add.push_back(temp[i]+temp[i+1]);
            }
            add.push_back(temp[temp.size()-1]);
            ans.push_back(add);
            temp=add;
            add.clear();
        }
        return ans;
    }
};