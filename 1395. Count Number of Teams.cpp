class Solution {
public:
    int numTeams(const std::vector<int>& rating) {
        int teams = 0, maxRating = 0;

        for(const int& r : rating)
            maxRating = std::max(maxRating, r);
        
        std::vector<int> leftBIT(maxRating+1), rightBIT(maxRating+1);

        for(const int& r : rating)
            updateBIT(rightBIT, r, 1);
        
        for(const int& currentRating : rating)
        {
            updateBIT(rightBIT, currentRating, -1);

            int smallerRatingsLeft = getPrefixSum(leftBIT, currentRating-1);
            int smallerRatingsRight = getPrefixSum(rightBIT, currentRating-1);

            int largerRatingsLeft = getPrefixSum(leftBIT, maxRating) - getPrefixSum(leftBIT, currentRating);
            int largerRatingsRight = getPrefixSum(rightBIT, maxRating) - getPrefixSum(rightBIT, currentRating);

            teams += (smallerRatingsLeft * largerRatingsRight);
            teams += (largerRatingsLeft * smallerRatingsRight);

            updateBIT(leftBIT, currentRating, 1);
        }

        return teams;
    }

private:
    void updateBIT(std::vector<int>& BIT, int index, const int value)
    {
        while(index < BIT.size())
        {
            BIT[index] += value;
            index += index & (-index);
        }
    }

    int getPrefixSum(std::vector<int>& BIT, int index)
    {
        int sum = 0;

        while(index > 0)
        {
            sum += BIT[index];
            index -= index & (-index);
        }

        return sum;
    }
};
