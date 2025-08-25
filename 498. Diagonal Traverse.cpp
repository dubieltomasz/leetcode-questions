class Solution {
public:
    std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0, x = 1, y = -1;
        std::vector<int> diagonal;

        diagonal.reserve(m * n);

        while(row < m && col < n){
            diagonal.push_back(mat[row][col]);

            row += y;
            col += x;

            if(row == m){
                row = m-1;
                col += 2;
                x = 1;
                y = -1;
            } else if(col == n){
                row += 2;
                col = n-1;
                x = -1;
                y = 1;
            } else if(row < 0){
                row = 0;
                x = -1;
                y = 1;
            } else if(col < 0){
                col = 0;
                x = 1;
                y = -1;
            }
        }

        return diagonal;
    }
};
