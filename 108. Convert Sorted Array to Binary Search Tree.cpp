class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        v = &nums;

        return func(0, nums.size()-1);
    }

private:
    const std::vector<int>* v;

    TreeNode* func(int l, int r)
    {
        if(l > r) return nullptr;
        else
        {
            int m = l + (r - l >> 1);

            TreeNode* result = new TreeNode((*v)[m]);

            result->left = func(l, m-1);
            result->right = func(m+1, r);

            return result;
        }
    }
};
