class RandomizedSet {
private:
    unordered_set<int> us;

public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    bool insert(int val) {
        if(us.find(val) != us.end()) return false;
        else
        {
            us.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(us.find(val) == us.end()) return false;
        else
        {
            us.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        random_device rd;
        uniform_int_distribution<int> uid(0, us.size()-1);

        auto element = begin(us);
        
        advance(element, uid(rd));

        return *element;
    }
};
