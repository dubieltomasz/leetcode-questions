class Solution {
private:
    array<int, 2> func(const TreeNode* node)
    {
        if(!node) return {0,0};
        else if(node->left == node->right) return {node->val,1};
        else
        {
            array<int, 2> left = func(node->left);
            array<int, 2> right = func(node->right);

            if(right[1] > left[1])
                return {right[0], right[1]+1};
            else
                return {left[0], left[1]+1};
        }
    }

public:
    int findBottomLeftValue(const TreeNode* root) {
        return func(root)[0];
    }
};
