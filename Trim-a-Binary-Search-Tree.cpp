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

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;

        if(root->val < low) return trimBST(root->right,low,high);
        else if(root->val > high) return trimBST(root->left,low,high);
        else
        {
            TreeNode*leftChild = trimBST(root->left,low,high);
            TreeNode*rightChild = trimBST(root->right,low,high);

            root->left = leftChild;
            root->right = rightChild;
        }
        return root;
    }
};