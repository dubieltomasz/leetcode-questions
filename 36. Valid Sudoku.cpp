class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        bool arr[2][9][9] = {};
        bool arr2[3][3][9] = {};

        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(arr[0][i][board[i][j]-'1']) return false;
                    if(arr[1][j][board[i][j]-'1']) return false;
                    if(arr2[i/3][j/3][board[i][j]-'1']) return false;

                    arr[0][i][board[i][j]-'1'] = true;
                    arr[1][j][board[i][j]-'1'] = true;
                    arr2[i/3][j/3][board[i][j]-'1'] = true;
                }
            }
        }

        return true;
    }
};
