class Solution {
public:
    int getCommon(const vector<int>& nums1, const vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while(i1 < n1 && i2 < n2)
        {
            if(nums1[i1] < nums2[i2]) ++i1;
            else if(nums1[i1] > nums2[i2]) ++i2;
            else break;
        }

        return (i1 == n1 || i2 == n2)? -1 : nums1[i1];
    }
};
