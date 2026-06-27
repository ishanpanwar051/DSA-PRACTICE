class Solution {
public:
    // Ek node se shuru karke kitne paths hain
    void helper(TreeNode* root, long long sum, int& count){
        if(root == NULL) return;

        if(root->val == sum)
            count++;

        helper(root->left,  sum - root->val, count);
        helper(root->right, sum - root->val, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        int count = 0;

        // Is node se shuru hone wale paths
        helper(root, targetSum, count);

        // Left aur right subtree mein bhi dhundo
        count += pathSum(root->left,  targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};