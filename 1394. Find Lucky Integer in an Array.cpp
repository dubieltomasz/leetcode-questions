class Solution {
public:
    int findLucky(const std::vector<int>& arr) {
        int map[500] = {};

        for(const int& val : arr)
            ++map[val-1];

        for(int i = 500; i > 0; --i)
            if(map[i-1] == i)
                return i;

        return -1;
    }
};
