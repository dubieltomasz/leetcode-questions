class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size()-1, answer = nums[n]-nums[3];
        answer = min(answer, nums[n-1]-nums[2]);
        answer = min(answer, nums[n-2]-nums[1]);
        answer = min(answer, nums[n-3]-nums[0]);
        
        return answer;
    }
};
