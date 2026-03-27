class Solution {
public:
    bool areSimilar(const std::vector<std::vector<int>>& mat, int k) {
        const int m = mat.size(), n = mat[0].size();
        std::vector<int> tmp(n);

        k %= n;
        if(k == 0) {
            return true;
        }

        for(int i = 0; i < m - 1; i += 2) {

            for(int j = 0; j < n; ++j) {
                tmp[(j - k + n) % n] = mat[i][j];
            }

            if(tmp != mat[i]) {
                return false;
            }

            for(int j = 0; j < n; ++j) {
                tmp[(j + k) % n] = mat[i + 1][j];
            }

            if(tmp != mat[i + 1]) {
                return false;
            }
        }

        for(int j = 0; j < n; ++j) {
            tmp[(j - k + n) % n] = mat.back()[j];
        }

        if(tmp != mat.back()) {
            return false;
        }

        return true;
    }
};
