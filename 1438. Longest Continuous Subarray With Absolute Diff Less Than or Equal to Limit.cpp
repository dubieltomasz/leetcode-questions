class Solution {
public:
    int longestSubarray(const vector<int>& nums, const int& limit) {
        int answer = 0;
        deque<int> minQ, maxQ;

        for(int i = 0, j = 0; j < nums.size(); ++j)
        {
            while(!maxQ.empty() && maxQ.back() < nums[j])
                maxQ.pop_back();
            
            while(!minQ.empty() && minQ.back() > nums[j])
                minQ.pop_back();

            maxQ.push_back(nums[j]);
            minQ.push_back(nums[j]);

            while(maxQ.front()-minQ.front() > limit && i < j)
            {
                if(nums[i] == maxQ.front())
                    maxQ.pop_front();

                if(nums[i] == minQ.front())
                    minQ.pop_front();

                ++i;
            }

            answer = max(answer, j-i+1);
        }

        return answer;
    }
};
