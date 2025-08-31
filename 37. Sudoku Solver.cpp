class Solution {
private:
    int rows[9] = {}, cols[9] = {}, subBoxes[3][3] = {};
    std::vector<std::pair<int, int>> emptyCells;
    std::vector<int> solution;

    bool findSolution(const int i)
    {
        if(i == solution.size())
            return true;

        for(int j = 0; j < 9; ++j) {
            if(rows[emptyCells[i].first] & 1 << j ||
               cols[emptyCells[i].second] & 1 << j ||
               subBoxes[emptyCells[i].first/3][emptyCells[i].second/3] & 1 << j) {
                continue;
            }
        
            rows[emptyCells[i].first] |= 1 << j;
            cols[emptyCells[i].second] |= 1 << j;
            subBoxes[emptyCells[i].first/3][emptyCells[i].second/3] |= 1 << j;

            if(findSolution(i+1)) {
                solution[i] = j;
                return true;
            }

            rows[emptyCells[i].first] ^= 1 << j;
            cols[emptyCells[i].second] ^= 1 << j;
            subBoxes[emptyCells[i].first/3][emptyCells[i].second/3] ^= 1 << j;
        }

        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        for(int row = 0; row < 9; ++row) {
            for(int col = 0; col < 9; ++col) {
                if(board[row][col] == '.') {
                    emptyCells.push_back({row, col});
                    continue;
                }

                rows[row] |= 1 << board[row][col] - '1';
                cols[col] |= 1 << board[row][col] - '1';
                subBoxes[row/3][col/3] |= 1 << board[row][col] - '1';
            }
        }

        solution = std::vector<int>(emptyCells.size());
        findSolution(0);

        for(int i = 0; i < solution.size(); ++i) {
            board[emptyCells[i].first][emptyCells[i].second] = solution[i] + '1';
        }
    }
};
