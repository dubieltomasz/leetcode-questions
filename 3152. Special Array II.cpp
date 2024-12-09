class Solution {
public:
    std::vector<bool> isArraySpecial(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
        int n1 = nums.size(), n2 = queries.size();
        std::vector<bool> answer(n2);
        std::vector<int> arr(n1);

        arr.back() = --n1;

        while(n1--)
            arr[n1] = (nums[n1] & 1) != (nums[n1+1] & 1) ? arr[n1+1] : n1;

        while(n2--)
            answer[n2] = arr[queries[n2][0]] >= queries[n2][1];
    
        return answer;
    }
};
