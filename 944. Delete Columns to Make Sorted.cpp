class Solution {
public:
    int minDeletionSize(const std::vector<std::string>& strs) {
        int columnsToDelete = 0;
        
        for(size_t col = 0; col < strs[0].size(); ++col) {
            for(size_t row = 1; row < strs.size(); ++row) {
                if(strs[row - 1][col] > strs[row][col]) {
                    ++columnsToDelete;
                    break;
                }
            }
        }

        return columnsToDelete;
    }
};
