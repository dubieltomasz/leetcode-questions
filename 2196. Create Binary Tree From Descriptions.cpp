class Solution {
public:
    TreeNode* createBinaryTree(const std::vector<std::vector<int>>& descriptions) {
        std::unordered_map<int , TreeNode*> nodeMap;
        std::set<int> children;

        for(const std::vector<int>& description : descriptions)
        {
            if(nodeMap.find(description[0]) == nodeMap.end())
                nodeMap[description[0]] = new TreeNode(description[0]);

            if(nodeMap.find(description[1]) == nodeMap.end())
                nodeMap[description[1]] = new TreeNode(description[1]);

            description[2]? nodeMap[description[0]]->left = nodeMap[description[1]] : nodeMap[description[0]]->right = nodeMap[description[1]];

            children.insert(description[1]);
        }

        for(const std::pair<int , TreeNode*>& element : nodeMap)
            if(children.find(element.first) == children.end()) return element.second;

        return nullptr;
    }
};
