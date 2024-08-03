class Solution {
public:
    bool canBeEqual(const std::vector<int>& target, const std::vector<int>& arr) {
        int ar[1001];

        for(int i = 0; i < 1001; ++i)
            ar[i] = 0;

        for(const int& element : target)
            ++ar[element];
        
        for(const int& element : arr)
            --ar[element];

        for(int i = 0; i < 1001; ++i)
            if(ar[i]) return false;

        return true;
    }
};
