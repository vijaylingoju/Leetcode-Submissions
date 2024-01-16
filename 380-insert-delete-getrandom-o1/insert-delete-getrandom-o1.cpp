class RandomizedSet {
public:

    unordered_set<int>mpp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){
            mpp.insert(val);

            return 1;
        }
        return 0;

    }
    
    bool remove(int val) {
       if(mpp.find(val)!=mpp.end()){
           mpp.erase(val);
           return 1;
       }
       return 0;
    }
    
    int getRandom() {
        return *next(mpp.begin(),rand()%mpp.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */