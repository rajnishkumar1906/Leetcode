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
    vector<int>ans;
    int level = -1;
    void solve(TreeNode*root,int lvl)
    {
        if(!root) return;

        if(level < lvl)
        {
            ans.push_back(root->val);
            level++;
        }

        solve(root->right,lvl+1);
        solve(root->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};