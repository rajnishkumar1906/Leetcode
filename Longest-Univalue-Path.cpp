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
    int maxLen = 0;
    int unPathLen(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int left = unPathLen(root->left);
        int right = unPathLen(root->right);
        if(root->left!= nullptr && root->val == root->left->val)
        {
            left+= 1 ;
        }
        else
        {
            left = 0;
        }

        if(root->right != nullptr && root->val == root->right->val)
        {
            right += 1;
        }
        else 
        {
            right = 0;
        }
        maxLen = max(left + right , maxLen);
        return max(left , right);
    }
    int longestUnivaluePath(TreeNode* root) {
        unPathLen(root);
        return maxLen;
    }
};