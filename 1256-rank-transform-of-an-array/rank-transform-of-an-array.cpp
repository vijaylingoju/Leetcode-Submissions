class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int>s;
        for(int i = 0; i < n; i++){
            s.insert(arr[i]);
        }
        map<int,int>mpp;
        for(auto ele : s){
            mpp[ele] = mpp.size() + 1;
        }

        vector<int>rank;
        for(int i = 0 ; i < n ; i++){
            rank.push_back(mpp[arr[i]]);
        }
        return rank;
    }
};