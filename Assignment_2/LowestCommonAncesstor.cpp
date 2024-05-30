#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;
    }
};

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
    vector<int> values1 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root1 = createTree(values1);
    TreeNode* p1 = root1->left; // Node with value 5
    TreeNode* q1 = root1->right; // Node with value 1
    Solution sol;
    TreeNode* lca1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "LCA of nodes 5 and 1: " << (lca1 ? lca1->val : -1) << endl; // Output: 3
    deleteTree(root1);

    // Example 2
    vector<int> values2 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root2 = createTree(values2);
    TreeNode* p2 = root2->left; // Node with value 5
    TreeNode* q2 = root2->left->right->right; // Node with value 4
    TreeNode* lca2 = sol.lowestCommonAncestor(root2, p2, q2);
    cout << "LCA of nodes 5 and 4: " << (lca2 ? lca2->val : -1) << endl; // Output: 5
    deleteTree(root2);

    // Example 3
    vector<int> values3 = {1, 2};
    TreeNode* root3 = createTree(values3);
    TreeNode* p3 = root3; // Node with value 1
    TreeNode* q3 = root3->left; // Node with value 2
    TreeNode* lca3 = sol.lowestCommonAncestor(root3, p3, q3);
    cout << "LCA of nodes 1 and 2: " << (lca3 ? lca3->val : -1) << endl; // Output: 1
    deleteTree(root3);

    return 0;
}
