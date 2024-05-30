#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    bool leftToRight = true;

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        vector<int> level(levelSize);
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            int index = leftToRight ? i : levelSize - 1 - i;
            level[index] = node->val;

            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
        }
        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

// Helper function to create a binary tree for testing
TreeNode* createTree(const vector<int>& values, int index = 0) {
    if (index >= values.size() || values[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Helper function to delete a binary tree to prevent memory leaks
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example 1
    vector<int> values1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root1 = createTree(values1);
    vector<vector<int>> result1 = zigzagLevelOrder(root1);
    for (const auto& level : result1) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    deleteTree(root1);
    
    // Example 2
    vector<int> values2 = {1};
    TreeNode* root2 = createTree(values2);
    vector<vector<int>> result2 = zigzagLevelOrder(root2);
    for (const auto& level : result2) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    deleteTree(root2);
    
    // Example 3
    vector<int> values3 = {};
    TreeNode* root3 = createTree(values3);
    vector<vector<int>> result3 = zigzagLevelOrder(root3);
    for (const auto& level : result3) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    deleteTree(root3);

    return 0;
}
