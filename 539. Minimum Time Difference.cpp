class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());

        int answer = INT_MAX, a, b;

        for(int i = 1; i < timePoints.size(); ++i)
        {
            a = func(timePoints[i-1]);
            b = func(timePoints[i]);

            answer = std::min(answer, std::min(std::abs(a-b), std::abs(a-b+1440)));
        }
        
        a = func(timePoints.front());
        b = func(timePoints.back());

        answer = std::min(answer, std::min(std::abs(a-b), std::abs(a-b+1440)));

        return answer;
    }

private:
    int func(std::string s)
    {
        return ( (s[0]-48)*10 + s[1]-48 )*60 + (s[3]-48)*10 + s[4]-48;
    }
};
