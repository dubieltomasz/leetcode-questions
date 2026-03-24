class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        const size_t n = grid.size(), m = grid[0].size();
        std::vector<long> pre(n * m + 1, 1), post(n * m + 1, 1);
        size_t indx = 1;

        for(size_t row = 0; row < n; ++row) {
            for(size_t col = 0; col < m; ++col, ++indx) {
                pre[indx] = (pre[indx - 1] * grid[row][col]) % 12345;
            }
        }

        indx = n * m - 1;

        for(size_t row = n; row > 0; --row) {
            for(size_t col = m; col > 0; --col, --indx) {
                post[indx] = (post[indx + 1] * grid[row - 1][col - 1]) % 12345;
            }
        }

        indx = 0;

        for(size_t row = 0; row < n; ++row) {
            for(size_t col = 0; col < m; ++col, ++indx) {
                grid[row][col] = pre[indx] * post[indx + 1] % 12345;
            }
        }

        return std::move(grid);
    }
};
