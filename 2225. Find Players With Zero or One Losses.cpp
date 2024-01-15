static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;

        for(vector<int>& match : matches)
        {
            losses[match[0]] += 0;
            ++losses[match[1]];
        }

        vector<vector<int>> answer{{},{}};

        for(auto& element : losses)
        {
            if(element.second == 0)
                answer[0].push_back(element.first);
            else if(element.second == 1)
                answer[1].push_back(element.first);
        }

        return answer;
    }
};
