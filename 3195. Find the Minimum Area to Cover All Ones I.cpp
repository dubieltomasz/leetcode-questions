class Solution {
public:
    int minimumArea(const std::vector<std::vector<int>>& grid) {
        int n = grid.size(), nn = grid[0].size();
        int top = INT_MAX, left = INT_MAX, right = -1, bottom = -1;

        for(int row = 0; row < n && row < top; ++row){
            for(int col = 0; col < nn && col < left; ++col){
                if(grid[row][col]){
                    top = row;
                    left = col;
                    right = col;
                    bottom = row;
                }
            }
        }

        for(int row = n-1; row > -1 && row >= bottom; --row){
            for(int col = nn-1; col > -1  && row >= bottom; --col){
                if(grid[row][col]){
                    left = std::min(left, col);
                    right = std::max(right, col);
                    bottom = row;
                }
            }
        }

        for(int col = 0; col < right && left > col; ++col){    
            for(int row = top+1; row <= bottom && left > col; ++row){
                if(grid[row][col]){
                    left = col;
                }
            }
        }

        for(int col = nn-1; col > left && right < col; --col){    
            for(int row = top; row < bottom && right < col; ++row){
                if(grid[row][col]){
                    right = col;
                }
            }
        }

        return (bottom - top + 1) * (right - left + 1);
    }
};
