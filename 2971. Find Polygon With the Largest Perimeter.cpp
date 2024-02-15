class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long answer = accumulate(nums.begin(), nums.end(), 0ll);

        priority_queue<int> pq(nums.begin(), nums.end());

        while(pq.size() > 2)
        {
            int tmp = pq.top();
            if(answer - tmp > tmp) return answer;
            
            answer -= tmp;
            pq.pop();
        }

        return -1;
    }
};
