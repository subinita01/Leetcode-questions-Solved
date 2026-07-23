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
private:
    // Helper function that traverses the tree carrying the path's maximum value
    int dfs(TreeNode* node, int max_so_far) {
        // Base Case: An empty node contributes 0 good nodes
        if (node == nullptr) {
            return 0;
        }

        int good_count = 0;

        // Check if current node satisfies the "good node" condition
        if (node->val >= max_so_far) {
            good_count = 1;
            max_so_far = node->val; // Update the maximum for deeper nodes
        }

        // Recursively count good nodes in left and right subtrees
        good_count += dfs(node->left, max_so_far);
        good_count += dfs(node->right, max_so_far);

        return good_count;
    }

public:
    int goodNodes(TreeNode* root) {
        // Start DFS from the root; initial max value is the root's own value
        return dfs(root, root->val);
    }
};