class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, const vector<int>& nums2) {
        for(const int& i : nums2)
            nums1.push_back(i);

        int m = nums1.size();
        sort(nums1.begin(), nums1.end());

        return (m % 2)? nums1[m/2] : (float)(nums1[m/2-1] + nums1[m/2])/2;
    }
};
