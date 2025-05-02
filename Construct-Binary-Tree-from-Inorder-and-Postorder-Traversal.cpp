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
    TreeNode* BinaryTree(int inStart, int inEnd, vector<int>& inorder, int postStart, int postEnd, vector<int>& postorder, unordered_map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd) 
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inorderRootIdx = inMap[root->val];
        int leftTreeSize = inorderRootIdx - inStart;

        root->left = BinaryTree(inStart, inorderRootIdx - 1, inorder, postStart, postStart + leftTreeSize - 1, postorder, inMap);
        root->right = BinaryTree(inorderRootIdx + 1, inEnd, inorder, postStart + leftTreeSize, postEnd - 1, postorder, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; ++i) {
            inMap[inorder[i]] = i;
        }
        return BinaryTree(0, n-1, inorder, 0, n-1, postorder, inMap);
    }
};