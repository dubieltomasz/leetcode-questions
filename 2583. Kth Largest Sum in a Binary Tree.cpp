class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long long> sums;
        std::queue<TreeNode*> q;
        TreeNode* tmp;
        long long sum;
        int size;

        q.push(root);

        while(!q.empty())
        {
            sum = 0;
            size = q.size();
            
            while(size--)
            {
                tmp = q.front();
                q.pop();

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);

                sum += tmp->val;
            }

            sums.push_back(sum);
        }

        if(sums.size() < k) return -1;

        std::make_heap(sums.begin(), sums.end());

        while(--k)
        {
            std::pop_heap(sums.begin(), sums.end());
            sums.pop_back();
        }

        return sums.front();
    }
};
