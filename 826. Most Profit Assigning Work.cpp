class Solution {
public:
    int maxProfitAssignment(const vector<int>& difficulty, const vector<int>& profit, const vector<int>& worker)
    {
        int answer = 0, left, right, middle, prof;
        vector<pair<int, int>> job(profit.size());

        for(int i = 0; i < profit.size(); ++i)
            job[i] = {profit[i], difficulty[i]};

        sort(job.rbegin(), job.rend());

        for(int i = 1; i < profit.size(); ++i)
            job[i].second = min(job[i-1].second, job[i].second);

        for(const int& w : worker)
        {
            left = 0; right = job.size()-1; prof = 0;

            while(left <= right)
            {
                middle = (left+right)/2;

                if(job[middle].second <= w)
                {
                    prof = max(prof, job[middle].first);
                    right = middle-1;
                }
                else left = middle+1;
            }

            answer += prof;
        }

        return answer;
    }
};
