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
    int maxSumPath = INT_MIN;
    int pathSum(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int leftGain = max(pathSum(root->left),0);
        int rightGain = max(pathSum(root->right),0);
        int gain  = root->val + leftGain + rightGain;
        maxSumPath = max(maxSumPath , gain);
        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxSumPath;
    }
};