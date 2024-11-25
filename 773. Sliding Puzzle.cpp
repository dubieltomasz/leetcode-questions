class Solution {
public:
    int slidingPuzzle(const std::vector<std::vector<int>>& board) {
        std::unordered_set<std::string> checkedCombinations;
        std::queue<std::string> q;
        std::string boardState = "xxxxxx", currComb;
        int n, moves = 0, posOf0;

        boardState[0] = board[0][0]+'0';
        boardState[1] = board[0][1]+'0';
        boardState[2] = board[0][2]+'0';
        boardState[3] = board[1][0]+'0';
        boardState[4] = board[1][1]+'0';
        boardState[5] = board[1][2]+'0';
        q.push("123450");

        while(!q.empty())
        {
            n = q.size();

            while(n--)
            {
                currComb = q.front();
                q.pop();

                if(currComb == boardState)
                    return moves;
                
                posOf0 = 0;
                while(currComb[posOf0] != '0')
                    ++posOf0;
                
                switch(posOf0)
                {
                    case 0:
                        std::swap(currComb[0], currComb[1]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[0], currComb[1]);

                        std::swap(currComb[0], currComb[3]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[0], currComb[3]);
                        break;

                    case 1:
                        std::swap(currComb[0], currComb[1]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[0], currComb[1]);

                        std::swap(currComb[1], currComb[2]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[1], currComb[2]);

                        std::swap(currComb[1], currComb[4]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[1], currComb[4]);
                        break;
                    
                    case 2:
                        std::swap(currComb[1], currComb[2]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[1], currComb[2]);

                        std::swap(currComb[2], currComb[5]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[2], currComb[5]);
                        break;
                    
                    case 3:
                        std::swap(currComb[0], currComb[3]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[0], currComb[3]);

                        std::swap(currComb[3], currComb[4]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[3], currComb[4]);
                        break;
                    
                    case 4:
                        std::swap(currComb[1], currComb[4]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[1], currComb[4]);

                        std::swap(currComb[3], currComb[4]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[3], currComb[4]);

                        std::swap(currComb[4], currComb[5]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[4], currComb[5]);
                        break;

                    case 5:
                        std::swap(currComb[2], currComb[5]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[2], currComb[5]);

                        std::swap(currComb[4], currComb[5]);
                        if(checkedCombinations.find(currComb) == checkedCombinations.end())
                        {
                            q.push(currComb);
                            checkedCombinations.insert(currComb);
                        }
                        std::swap(currComb[4], currComb[5]);
                        break;
                }
            }

            ++moves;
        }

        return -1;
    }
};
