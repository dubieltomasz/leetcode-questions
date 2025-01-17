class Solution {
public:
    bool doesValidArrayExist(const std::vector<int>& derived) {
        bool check = true;
        
        for(const int& value : derived)
            check ^= value;
        
        return check;
    }
};
