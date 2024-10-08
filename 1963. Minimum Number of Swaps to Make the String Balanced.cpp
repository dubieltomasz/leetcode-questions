class Solution {
public:
    int minSwaps(const std::string& s) {
        int stackSize = 0;

        for(const char& c : s)
        {
            if(c == '[')        ++stackSize;
            else if(stackSize)  --stackSize;
        }

        return (stackSize + 1) / 2;
    }
};
