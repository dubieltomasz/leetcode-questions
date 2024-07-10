class Solution {
public:
    int minOperations(const std::vector<std::string>& logs) {
        int answer = 0;

        for(int i = 0; i < logs.size(); ++i)
        {
            if(logs[i] == "../") answer = max(0, answer-1);
            else if(logs[i] == "./") continue;
            else ++answer;
        }

        return answer;
    }
};
