class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> q;
        int sum = 0;

        q.push({root, 0});

        while(!q.empty()) {
            q.front().second = (q.front().second << 1) + q.front().first->val;

            if(q.front().first->left == nullptr && q.front().first->right == nullptr) {
                sum += q.front().second;
            }

            if(q.front().first->left != nullptr) {
                q.push({q.front().first->left, q.front().second});
            }

            if(q.front().first->right != nullptr) {
                q.push({q.front().first->right, q.front().second});
            }

            q.pop();
        }

        return sum;
    }
};
