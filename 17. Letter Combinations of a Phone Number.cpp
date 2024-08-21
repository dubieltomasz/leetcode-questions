class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        std::vector<std::string> answer;

        const std::string arr[10] =
        {
            "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        
        switch(digits.size())
        {
            case 1:
                for(int i = 0; i < arr[int(digits[0])-49].size(); ++i)
                    answer.push_back(string(1, (arr[int(digits[0])-49][i])));
                break;
            case 2:
                for(int i = 0; i < arr[int(digits[0])-49].size(); ++i)
                    for(int j = 0; j < arr[int(digits[1])-49].size(); ++j)
                        answer.push_back(string(1, (arr[int(digits[0])-49][i])) + string(1, (arr[int(digits[1])-49][j])));
                break;
            case 3:
                for(int i = 0; i < arr[int(digits[0])-49].size(); ++i)
                    for(int j = 0; j < arr[int(digits[1])-49].size(); ++j)
                        for(int k = 0; k < arr[int(digits[2])-49].size(); ++k)
                                answer.push_back(string(1, (arr[int(digits[0])-49][i])) + string(1, (arr[int(digits[1])-49][j])) + string(1, (arr[int(digits[2])-49][k])));
                break;
            case 4:
                for(int i = 0; i < arr[int(digits[0])-49].size(); ++i)
                    for(int j = 0; j < arr[int(digits[1])-49].size(); ++j)
                        for(int k = 0; k < arr[int(digits[2])-49].size(); ++k)
                            for(int l = 0; l < arr[int(digits[3])-49].size(); ++l)
                                answer.push_back(string(1, (arr[int(digits[0])-49][i])) + string(1, (arr[int(digits[1])-49][j])) + string(1, (arr[int(digits[2])-49][k])) + string(1, (arr[int(digits[3])-49][l])));
                break;
            default:
                break;
        }

        return answer;
    }
};
