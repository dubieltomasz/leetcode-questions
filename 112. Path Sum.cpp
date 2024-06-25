class Solution {
public:
    bool hasPathSum(TreeNode* root, const int& targetSum) {
        ts = targetSum;

        return func(root, 0);
    }

private:
    int ts;

    bool func(TreeNode* node, int sum)
    {
        if(!node) return false;
        else if(!node->left && !node->right && sum + node->val == ts) return true;
        else return func(node->left, sum + node->val) || func(node->right, sum + node->val);
    }
};
