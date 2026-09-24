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

 TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int preStart,int preEnd,int inStart,int inEnd){

    if(preStart > preEnd || inStart >inEnd) return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int index = inStart;

    while(inorder[index] != preorder[preStart])
    index++;

    int leftSize = index - inStart;

    root->left = solve(preorder , inorder,preStart + 1,preStart + leftSize,inStart,index- 1);

    root->right =  solve(preorder ,inorder , preStart + leftSize +1,preEnd ,index +1 ,inEnd);

    return root;
 }
 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        

        return solve(preorder , inorder , 0, preorder.size()-1, 0,inorder.size()-1);

    }
};