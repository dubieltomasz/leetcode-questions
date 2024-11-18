class Solution {
public:
    std::vector<int> decrypt(const std::vector<int>& code, const int k) {
        std::vector<int> answer(code.size());

        if(k == 0) return answer;
        else if(k > 0)
        {
            int sum = 0;

            for(int i = 0; i < k; ++i)
                sum += code[i];

            for(int i = 0; i < code.size()-k; ++i)
                answer[i] = sum += code[i+k] - code[i];

            for(int i = code.size()-k; i < code.size(); ++i)
                answer[i] = sum += code[(i+k)%(code.size())] - code[i];

            return answer;
        }
        else
        {
            int sum = 0, n = code.size();

            for(int i = 0; i < -k; ++i)
                sum += code[i];

            answer[-k] = sum;

            for(int i = 1-k; i < code.size(); ++i)
                answer[i] = sum += code[i-1] - code[i+k-1];

            for(int i = 0; i < -k; ++i)
                answer[i] = sum += code[(n-1+i)%(n)] - code[(n+k+i-1)%(n)];

            return answer;
        }
    }
};
