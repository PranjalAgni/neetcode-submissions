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
            cout << "CurrentSum " << currentSum + root->val << endl;
            return true;
        }

        // cout << root->val;

        bool result1 = calculatePathSum(root->left, currentSum + root->val, targetSum);
        bool result2 = calculatePathSum(root->right, currentSum + root->val, targetSum);
        
        
        /**
        {(1, 0)L, 1, 2} A1
        {(1, 1)R, 1, 2} B1

        A1 is going on
        {(2, 0)L, 2, 2}
        {(2, 1)R, 2, 2} => false as branch does not exists {1}

        {(3, 0)L, 3, 2} => false
        {(3, 1)L, 3, 2} => false

        B1 now
        {(1, 1)R, 1, 2}
        {(2, 0)R, 1, 2} = false
        {(2, 1)R, 1, 2} = false
        **/


        return result1 || result2;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return calculatePathSum(root, 0, targetSum);
    }
};