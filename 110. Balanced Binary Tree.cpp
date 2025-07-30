class Solution {
private:
    bool balanced = true;
    
    uint height(TreeNode* node)
    {
        if(node == nullptr) return 0;

        int left = height(node->left);
        int right = height(node->right);
        
        if(!balanced) return 0;

        if(std::abs(left - right) > 1)
            balanced = false;
        
        return std::max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        height(root);

        return balanced;
    }
};
