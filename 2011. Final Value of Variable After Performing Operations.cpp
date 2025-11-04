class Solution {
public:
    int finalValueAfterOperations(const std::vector<std::string>& operations) {
        int result = 0;

        for(const std::string& operation : operations) {
            switch(operation[1]) {
                case '+':
                    ++result;
                    break;
                case '-':
                    --result;
                    break;
            }
        }

        return result;
    }
};
