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
    bool isBalanced(TreeNode* root) {
        
        bool ans = true;
        function<int(TreeNode*)> go = [&](TreeNode* node) {
            if (!node) return 0;

            int left = go(node->left), right = go(node->right);
            ans &= abs(left - right) <= 1;
            return max(left, right) + 1;
        };

        go(root);
        return ans;
    }
};
