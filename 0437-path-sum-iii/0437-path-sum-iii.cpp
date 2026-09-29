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

int dfs(TreeNode* root , long currSum ,long target, unordered_map<long, int>& mp){
    if(!root) return 0;

    currSum += root->val;

    int count = mp[currSum - target];

    mp[currSum]++;

    count += dfs(root->left, currSum ,target , mp);
    count +=dfs(root->right , currSum,target , mp);

    mp[currSum]--;

    return count;
}

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long ,int>mp;
        mp[0] =1;
        return dfs(root , 0,targetSum , mp);
    }
};