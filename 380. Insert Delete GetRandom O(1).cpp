class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(const int& val) {
        if(um.find(val) != um.end()) return false;

        v.push_back(val);
        um[val] = v.size()-1;

        return true;
    }
    
    bool remove(const int& val) {
        if(um.find(val) == um.end()) return false;

        int index = um[val];
        v[index] = v.back();
        v.pop_back();

        um[v[index]] = index;
        um.erase(val);

        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }

private:
    std::unordered_map<int, int> um;
    std::vector<int> v;
};
