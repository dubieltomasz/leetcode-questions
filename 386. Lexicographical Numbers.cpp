class Solution {
public:
    std::vector<int> lexicalOrder(const int& n) {
        int number = 1;
        std::vector<int> answer;
        answer.reserve(n);

        while(answer.size() < n)
        {
            answer.push_back(number);

            if(number*10 <= n) number *= 10;
            else
            {
                while(number % 10 == 9 || number >= n)
                    number /= 10;
                
                ++number;
            }
        }

        return answer;
    }
};
