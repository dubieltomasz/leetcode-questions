class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        else return func(root);
    }

private:
    int func(TreeNode* node)
    {
        if(!node) return 100000;
        else if(!node->left && !node->right) return 1;
        else return 1 + min(func(node->left), func(node->right));
    }
};
