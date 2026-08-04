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
    bool calculatePathSum(TreeNode* root, int currentSum, int targetSum) {
        if (!root) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr && currentSum + root->val == targetSum) {
            return true;
        }

        bool result1 = calculatePathSum(root->left, currentSum + root->val, targetSum);
        bool result2 = calculatePathSum(root->right, currentSum + root->val, targetSum);

        return result1 || result2;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return calculatePathSum(root, 0, targetSum);
    }
};