/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode*& ptr) {
        if (root == nullptr) return;

        ptr->right = root;
        ptr = ptr->right;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        ptr->left = nullptr;

        solve(left, ptr);
        solve(right, ptr);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* ptr = dummy;

        solve(root, ptr);

        // Copy flattened tree back to original root
        root->left = nullptr;
        root->right = dummy->right->right;

        delete dummy;
    }
};
