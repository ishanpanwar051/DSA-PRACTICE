

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, long>> q;  // {node, index}
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long leftIdx  = q.front().second;  // Level ka pehla index
            long rightIdx = leftIdx;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                // Overflow rokne ke liye normalize karo
                idx -= leftIdx;
                rightIdx = idx;

                if (node->left)  q.push({node->left,  2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }

            maxWidth = max(maxWidth, (int)(rightIdx - 0 + 1));
        }
        return maxWidth;
    }
};