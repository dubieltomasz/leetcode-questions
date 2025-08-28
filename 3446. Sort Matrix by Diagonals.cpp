class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> tmp(n * 2 - 1);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                tmp[n + i - j - 1].push_back(grid[i][j]);
            }
        }

        for(int i = 0; i < n - 1; ++i) {
            std::sort(tmp[i].begin(), tmp[i].end(), std::greater<int>());
        }

        for(int i = n - 1; i < n * 2 - 1; ++i) {
            std::sort(tmp[i].begin(), tmp[i].end());
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                grid[i][j] = tmp[n + i - j - 1].back();
                tmp[n + i - j - 1].pop_back();
            }
        }

        return grid;
    }
};
