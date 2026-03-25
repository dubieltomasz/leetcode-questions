class Solution {
public:
    bool canPartitionGrid(const std::vector<std::vector<int>>& grid) {
        std::vector<long> sumInRows = std::vector<long>(grid.size(), 0), sumInColumns = std::vector<long>(grid[0].size(), 0);
        long sum = 0, accumulator = 0;
        
        for(size_t row = 0; row < grid.size(); ++row) {
            for(size_t col = 0; col < grid[0].size(); ++col) {
                sumInRows[row] += grid[row][col];
                sumInColumns[col] += grid[row][col];
                sum += grid[row][col];
            }
        }

        if(sum & 1) {
            return false;
        }

        sum >>= 1;

        for(size_t index = 0; accumulator < sum; ++index) {
            accumulator += sumInRows[index];
        }

        if(accumulator == sum) {
            return true;
        }

        accumulator = 0;

        for(size_t index = 0; accumulator < sum; ++index) {
            accumulator += sumInColumns[index];
        }

        return accumulator == sum;
    }
};
