class Solution {
public:
    int maxCount(const std::vector<int>& banned, const int& n, int maxSum) {
        bool arr[10001] = {};
        int answer = 0, value = 0;

        for(const int& number : banned)
            arr[number] = true;

        while(++value <= n)
        {
            if(!arr[value])
            {
                maxSum -= value;

                if(maxSum < 0) break;
                else ++answer;
            }
        }

        return answer;
    }
};
