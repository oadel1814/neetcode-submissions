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
    int maxDepth(TreeNode* root) {
        

        function<int(TreeNode*)> go = [&](TreeNode* root) {
            if (root == nullptr) return 0;
            return 1 + max(root->left ? go(root->left) : 0, root->right ? go(root->right) : 0);
        };

        return go(root);
    }
};
