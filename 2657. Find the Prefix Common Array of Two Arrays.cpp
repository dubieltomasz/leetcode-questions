class Solution {
public:
    std::vector<int> findThePrefixCommonArray(const std::vector<int>& A, const std::vector<int>& B) {
        std::vector<int> answer(A.size());
        bool arr[50] = {};

        answer.back() = A.size();

        for(int i = A.size()-2; i >= 0; --i)
        {
            answer[i] = answer[i+1];
            
            answer[i] -= arr[A[i+1]-1] ^= 1;
            answer[i] -= arr[B[i+1]-1] ^= 1;
        }

        return answer;
    }
};
