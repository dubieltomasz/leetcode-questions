class Solution {
public:
    int distributeCandies(const std::vector<int>& candyType) {
        bool arr[200001] = {};
        int countTypes = candyType.size();

        for(const int& candy : candyType)
        {
            countTypes -= arr[100000 + candy];
            arr[100000 + candy] = true;
        }
        
        return std::min(countTypes, (int)candyType.size() >> 1);
    }
};
