class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>check;
        for(int i = 0; i < arr.size(); i++)mpp[arr[i]]+=1;
        for(auto i:mpp)check[i.second]=1;
        return check.size()==mpp.size();
    }
};