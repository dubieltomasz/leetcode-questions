class Solution {
public:
    std::vector<std::vector<int>> reverseSubmatrix(std::vector<std::vector<int>>& grid, int x, const int y, int k) {
        for(int row1 = x, row2 = k + x - 1; row1 < row2; ++row1, --row2) {
            for(int col = y; col < y + k; ++col) {
                std::swap(
                    grid[row1][col],
                    grid[row2][col]
                );
            }
        }

        return std::move(grid);
    }
};
