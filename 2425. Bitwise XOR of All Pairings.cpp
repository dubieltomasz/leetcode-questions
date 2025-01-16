class Solution {
public:
    int xorAllNums(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        int answer = 0;
        
        if(nums1.size() & 1)
        {
            for(const int& num : nums2)
                answer ^= num;
        }

        if(nums2.size() & 1)
        {
            for(const int& num : nums1)
                answer ^= num;
        }

        return answer;
    }
};
