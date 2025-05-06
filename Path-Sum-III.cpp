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
    int Paths(TreeNode*root,long long target)
    {
        if(root == nullptr) return 0;
        int count = (root->val == target) ? 1 : 0; 
        return count + Paths(root->left , target-root->val) + Paths(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;

        return Paths(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};