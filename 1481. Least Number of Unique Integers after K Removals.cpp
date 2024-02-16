class Solution {
public:
    int findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
        unordered_map<int, int> um;

        for(const int& element : arr)
            ++um[element];

        for(int i = 1; i <= k; ++i)
            for(auto& element : um)
                if(element.second == i && k != 0)
                {
                    element.second -= k;
                    k -= i;
                }

        int answer = 0;

        for(pair<int, int> element : um)
            if(element.second > 0) ++answer;

        return answer;
    }
};
