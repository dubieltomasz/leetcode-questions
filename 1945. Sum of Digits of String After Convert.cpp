class Solution {
public:
    int getLucky(const std::string& s, int k) {
        int answer = 0, tmp;

        for(const char& c : s)
            answer += (c-96) / 10 + (c-96) % 10;

        while(--k)
        {
            tmp = 0;

            while(answer)
            {
                tmp += answer % 10;
                answer /= 10;
            }

            answer = tmp;
        }

        return answer;
    }
};
