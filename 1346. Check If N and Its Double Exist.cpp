class Solution {
public:
    bool checkIfExist(const std::vector<int>& arr) {
        bool map[20000] = {};

        for(const int& value : arr)
        {
            if(map[10000 + (value << 1)] || (value & 1) == 0 && map[10000 + (value >> 1)])
                return true;
            else map[10000 + value] = true;
        }

        return false;
    }
};
