class Solution {
public:
    int maxFrequencyElements(const vector<int>& nums) {
        unordered_map<int, int> um;
        int frequencies = 0;
        int occurrences = 0;

        for(const int& num : nums)
        {
            ++um[num];

            if(um[num] == occurrences)
                frequencies += um[num];
            else if(um[num] > occurrences)
            {
                frequencies = um[num];
                occurrences = um[num];
            }
        }

        return frequencies;
    }
};
