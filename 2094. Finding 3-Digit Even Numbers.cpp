class Solution {
public:
    std::vector<int> findEvenNumbers(const std::vector<int>& digits) {
        std::vector<int> answer;
        int arr[10] = {};

        for(const int& digit : digits)
            ++arr[digit];
        
        for(int i = 1; i < 10; ++i)
        {
            if(!arr[i]) continue;

            --arr[i];

            for(int j = 0; j < 10; ++j)
            {
                if(!arr[j]) continue;

                --arr[j];

                for(int k = 0; k < 9; k += 2)
                {
                    if(!arr[k]) continue;
                    else answer.push_back(i * 100 + j * 10 + k);
                }
                
                ++arr[j];
            }

            ++arr[i];
        }

        return answer;
    }
};
