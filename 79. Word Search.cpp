static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
private:
    size_t N, n, wn;
    bool found = false;

    void findWord(vector<vector<char>>& board, const int x, const int y, const string& word, int i)
    {
        if(x > -1 && x < N && y > -1 && y < n && board[x][y] != '0' && board[x][y] == word[i])
        {
            if(++i == wn) {found = true; return;}

            char tmp = board[x][y];
            board[x][y] = '0';

            if(!found) findWord(board, x, y+1, word, i);
            if(!found) findWord(board, x+1, y, word, i);
            if(!found) findWord(board, x, y-1, word, i);
            if(!found) findWord(board, x-1, y, word, i);

            board[x][y] = tmp;
        }
    }

public:
    bool exist(vector<vector<char>>& board, const string& word) {
        N = board.size();
        n = board[0].size();
        wn = word.size();

        if(N * n < wn) return false;

        int x = 0, y = 0, i = 0;

        while(x < N)
        {
            while(y < n)
            {
                findWord(board, x, y, word, i);

                if(found) return true;
                else i = 0;

                ++y;
            }

            y = 0;
            ++x;
        }

        return false;
    }
};
