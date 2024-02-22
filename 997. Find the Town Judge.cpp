class Solution {
public:
    int findJudge(const int& n, const vector<vector<int>>& trust) {
        if(trust.size() == 0) return (n == 1)? 1 : -1;

        unordered_map<int, int> trusted;

        for(const vector<int>& element : trust)
        {
            ++trusted[element[1]];
            --trusted[element[0]];
        }

        for(const pair<int, int>& element : trusted)
            if(element.second == n-1) return element.first;

        return -1;
    }
};
