class Solution {
private:
    int answer = 0;

    int func(const TreeNode* root)
    {
        if(!root) return 0;
        else
        {
            int g = root->val - 1 + func(root->left) + func(root->right);
            answer += abs(g);
            return g;
        }
    }

public:
    int distributeCoins(const TreeNode* root) {
        func(root);
        
        return answer;
    }
};
