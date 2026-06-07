class Solution {
public:
    TreeNode* createBinaryTree(const std::vector<std::vector<int>>& descriptions) {
        std::array<TreeNode*, 100001> um{};
        int nodeSum{};

        for(const auto& description : descriptions) {
            if(um[description[0]] == nullptr) {
                um[description[0]] = new TreeNode(description[0]);
                nodeSum += description[0];
            }

            if(um[description[1]] == nullptr) {
                um[description[1]] = new TreeNode(description[1]);
                nodeSum += description[1];
            }

            nodeSum -= description[1];

            if(description[2]) {
                um[description[0]]->left = um[description[1]];
            } else {
                um[description[0]]->right = um[description[1]];
            }
        }

        return um[nodeSum];
    }
};
