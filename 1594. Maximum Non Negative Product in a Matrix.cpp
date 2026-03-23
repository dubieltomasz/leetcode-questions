class Solution {
public:
    int maxProductPath(const std::vector<std::vector<int>>& grid) {
        const size_t m = grid.size(), n = grid[0].size();
        const long long mod = 1e9+7;
        std::vector<std::vector<std::pair<long long, long long>>> values(m, std::vector<std::pair<long long, long long>>(n));

        values[0][0].first = grid[0][0];
        values[0][0].second = grid[0][0];

        for(size_t row = 1; row < m; ++row) {
            values[row][0].first = std::max(
                values[row - 1][0].first * grid[row][0],
                values[row - 1][0].second * grid[row][0]
            );

            values[row][0].second = std::min(
                values[row - 1][0].first * grid[row][0],
                values[row - 1][0].second * grid[row][0]
            );
        }

        for(size_t col = 1; col < n; ++col) {
            values[0][col].first = std::max(
                values[0][col - 1].first * grid[0][col],
                values[0][col - 1].second * grid[0][col]
            );

            values[0][col].second = std::min(
                values[0][col - 1].first * grid[0][col],
                values[0][col - 1].second * grid[0][col]
            );
        }

        for(size_t row = 1; row < m; ++row) {
            for(size_t col = 1; col < n; ++col) {
                values[row][col].first = std::max({
                    values[row - 1][col].first * grid[row][col],
                    values[row - 1][col].second * grid[row][col],
                    values[row][col - 1].first * grid[row][col],
                    values[row][col - 1].second * grid[row][col]
                });

                values[row][col].second = std::min({
                    values[row - 1][col].first * grid[row][col],
                    values[row - 1][col].second * grid[row][col],
                    values[row][col - 1].first * grid[row][col],
                    values[row][col - 1].second * grid[row][col]
                });
            }
        }

        return values[m - 1][n - 1].first >= 0 ? values[m - 1][n - 1].first % mod : -1;
    }
};
