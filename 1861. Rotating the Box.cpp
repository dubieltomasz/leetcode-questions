class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(const std::vector<std::vector<char>>& boxGrid) {
        std::vector<std::vector<char>> result(boxGrid[0].size(), std::vector<char>(boxGrid.size(), '.'));
        int stones = 0;
        
        for(size_t i = 0; i < boxGrid.size(); ++i) {
            for(size_t j = 0; j < boxGrid[0].size(); ++j) {
                switch(boxGrid[i][j]) {
                    case '#':
                        ++stones;
                        break;
                    case '*':
                        int tmp = j;
                        result[tmp][boxGrid.size() - 1 - i] = '*';
                        while(stones) {
                            result[--tmp][boxGrid.size() - 1 - i] = '#';
                            --stones;
                        }
                        break;
                }
            }

            int tmp = boxGrid[0].size();
            while(stones) {
                result[--tmp][boxGrid.size() - 1 - i] = '#';
                --stones;
            }
        }

        return result;
    }
};
