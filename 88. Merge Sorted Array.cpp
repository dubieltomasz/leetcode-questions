class Solution {
public:
    void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
        int i = m-- + n-- - 1;

        while(m >= 0 && n >= 0)
            nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];

        while(n >= 0)
            nums1[i--] = nums2[n--];
    }
};
