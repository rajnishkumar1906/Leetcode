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
    TreeNode* binaryTree(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>&inMap)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inorderRoot = inMap[root->val];
        int numsLeft = inorderRoot - inStart;
        root->left = binaryTree(preorder , inorder , preStart + 1 , preStart + numsLeft , inStart,inorderRoot - 1 , inMap);
        root->right =  binaryTree(preorder , inorder , preStart + numsLeft + 1 , preEnd , inorderRoot + 1 , inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // create an inorder map whih staores index of each inorder root 
        map<int,int>inMap;
        for(int i =0;i<n;i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = binaryTree(preorder,inorder,0,n-1,0,n-1,inMap);
        return root;
    }
};