class Solution {
public:
    int minDays(const vector<int>& bloomDay, const int& m, const int& k) {
        if(bloomDay.size()/k < m) return -1;

        int firstDay = 0, lastDay = *max_element(bloomDay.begin(), bloomDay.end()), middle, numOfBouquets, count, answer = 0;

        while(firstDay <= lastDay)
        {
            middle = (firstDay+lastDay)/2;

            numOfBouquets = 0, count = 0;

            for(const int& day : bloomDay)
            {
                if(day <= middle) ++count;
                else count = 0;

                if(count == k)
                {
                    ++numOfBouquets;
                    count = 0;
                }
            }

            if(numOfBouquets >= m)
            {
                answer = middle;
                lastDay = middle-1;
            }
            else firstDay = middle+1;
        }

        return answer;
    }
};
