class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex+=1;//convert 0-indexed to 1-indexed
        if(rowIndex==1)return {1};
        if(rowIndex==2)return {1,1};
        vector<int>temp = {1,1};
        rowIndex-=2;
        
        while(rowIndex--){
            vector<int>add;
            add.push_back(temp[0]);
            for(int i = 0; i < temp.size()-1;i++){
                add.push_back(temp[i]+temp[i+1]);
            }
            add.push_back(temp[temp.size()-1]);
            temp=add;
            add.clear();
        }
        return temp;
    }
};