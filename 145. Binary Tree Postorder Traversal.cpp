class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        func(root);

        return answer;
    }

private:
    std::vector<int> answer;
    
    void func(TreeNode* node)
    {
        if(node)
        {
            func(node->left);
            func(node->right);

            answer.push_back(node->val);
        }
    }
};
