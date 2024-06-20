class Solution {
public:
    int maxDistance(vector<int>& position, const int& m) {
        sort(position.begin(), position.end());
        int answer = 0, n = position.size(), start = 1, middle, end = ceil((float)position[n-1]/(m-1)), lastPosition, balls;

        while(start <= end)
        {
            middle = start+(end-start)/2;
            lastPosition = position[0];
            balls = 1;
            
            for(int i = 1; i < position.size() && balls < m; ++i)
                if(position[i] - lastPosition >= middle)
                {
                    ++balls;
                    lastPosition = position[i];
                }

            if(balls == m)
            {
                answer = middle;
                start = middle+1;
            }
            else end = middle-1;
        }

        return answer;
    }
};
