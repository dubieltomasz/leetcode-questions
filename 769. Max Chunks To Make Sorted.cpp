class Solution {
public:
    int maxChunksToSorted(const std::vector<int>& arr) {
        int count = 0, accumulator = 0;

        for(int i = 0; i < arr.size(); ++i)
            if(!(accumulator += arr[i] - i))
                ++count;

        return count;
    }
};
