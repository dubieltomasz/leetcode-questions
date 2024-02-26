class Solution {
private:
    vector<int> v1{};
    vector<int> v2{};

    void func(TreeNode* node, vector<int>& v)
    {
        if(node == nullptr) v.push_back(INT_MAX);
        else
        {
            v.push_back(node->val);

            func(node->left, v);
            func(node->right, v);
        }
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        func(p, v1);
        func(q, v2);

        return v1 == v2;
    }
};
