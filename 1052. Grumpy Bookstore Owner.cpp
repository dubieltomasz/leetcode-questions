class Solution {
public:
    int maxSatisfied(const vector<int>& customers, const vector<int>& grumpy, const int& minutes) {
        int answer = accumulate(customers.begin(), customers.begin()+minutes, 0);

        for(int i = minutes; i < customers.size(); ++i)
            answer += customers[i] * (grumpy[i]^1);

        int tmp = answer;

        for(int i = 1; i < customers.size()-minutes+1; ++i)
        {
            tmp -= customers[i-1] * grumpy[i-1];
            tmp += customers[i+minutes-1] * grumpy[i+minutes-1];

            answer = max(answer, tmp);
        }
        
        return answer;
    }
};
