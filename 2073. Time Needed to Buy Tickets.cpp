static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    int timeRequiredToBuy(const vector<int>& tickets, const int& k) {
        if(tickets[k] == 0) return 0;
        
        int answer = 0, n = tickets.size()-1;

        while(n > k)
            answer += min(tickets[n--], tickets[k]-1);

        while(n >= 0)
            answer += min(tickets[n--], tickets[k]);

        return answer;
    }
};
