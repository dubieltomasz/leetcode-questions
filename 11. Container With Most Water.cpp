class Solution {
public:
    int maxArea(const vector<int>& height) {
        int l = 0, r = height.size()-1, answer = 0;

        while(l <= r)
        {
            answer = max(answer, (min(height[l], height[r])*(r-l)));

            if(height[l] < height[r]) ++l;
            else --r;
        }

        return answer;
    }
};
