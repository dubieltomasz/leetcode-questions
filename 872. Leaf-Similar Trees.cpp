static const bool& __attribute__((constructor)) fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
} 

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<short> v1{}, v2{};

        leafs(root1, v1);
        leafs(root2, v2);

        return v1 == v2;
    }

private:
    void leafs(TreeNode* root, vector<short>& v)
    {
        if(root->left || root->right)
        {
            if(root->left) leafs(root->left, v);
            if(root->right) leafs(root->right, v);
        }
        else
            v.push_back(root->val);
    }
};
