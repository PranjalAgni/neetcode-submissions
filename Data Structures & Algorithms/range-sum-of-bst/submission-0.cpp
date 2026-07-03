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
    void traverse(TreeNode* root, int low, int high, int& answer) {
        if (!root) return;
        if (root->val >= low && root->val <= high) {
            answer += root->val;
        }

        traverse(root->left, low, high, answer);
        traverse(root->right, low, high, answer);
    } 
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int answer = 0;
        traverse(root, low, high, answer);
        return answer;
    }
};