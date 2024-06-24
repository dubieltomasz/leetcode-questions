class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        func(root, answer);

        return answer;
    }

private:
    void func(TreeNode* node, vector<int>& v)
    {
        if(!node) return;

        func(node->left, v);
        v.push_back(node->val);
        func(node->right, v);
    }
};
