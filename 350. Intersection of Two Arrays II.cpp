class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> answer;

        for(const int& num : nums1)
            ++um[num];

        for(const int& num : nums2)
        {
            if(um[num])
            {
                --um[num];
                answer.push_back(num);
            }
        }

        return answer;
    }
};
