class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int time{};

        for(int i = 1; i < colors.size(); ++i)
            if(colors[i-1] == colors[i])
            {
                if(neededTime[i-1] > neededTime[i])
                {
                    time += neededTime[i];

                    neededTime[i-1] ^= neededTime[i];
                    neededTime[i] ^= neededTime[i-1];
                }
                else
                    time += neededTime[i-1];
            }

        return time;
    }
};
