class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mpp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){
            mpp[val]+=1;
            v.push_back(val);
            return 1;
        }
        return 0;

    }
    
    bool remove(int val) {
       if(mpp.find(val)!=mpp.end()){
           mpp.erase(val);
           auto it = find(v.begin(),v.end(),val);
        //    vector<int>::tp = v.begin();
           if(it!=v.end())v.erase(it);
           return 1;
       }
       return 0;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */