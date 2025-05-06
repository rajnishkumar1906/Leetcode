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
    unordered_map<int,int>preMap , postMap;
    TreeNode* BinaryTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd)
    {
        if(preStart > preEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        if(preStart == preEnd) return root;

        if(preorder[preStart+1] != postorder[postEnd-1])
        {
            int leftChild = preorder[preStart+1];
            int rightChild = postorder[postEnd-1];

            //Index of left child in postorder
            int x = postMap[leftChild];
            // Index of right child in preorder
            int y = preMap[rightChild];

            root->left = BinaryTree(preorder,postorder,preStart+1,y-1,postStart,x);
            root->right = BinaryTree(preorder,postorder,y,preEnd,x+1,postEnd-1);
        }
        else
        {
            // Only one subtree exists, it must be the left
            root->left = BinaryTree(preorder, postorder, preStart + 1, preEnd, postStart, postEnd - 1);
            }

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0;i<n;i++)
        {
            preMap[preorder[i]] = i;
            postMap[postorder[i]] = i;
        }
        return BinaryTree(preorder,postorder,0,n-1,0,n-1);
    }
};