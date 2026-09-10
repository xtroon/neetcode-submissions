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
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int below_best = l + r + root->val;
        int below_one_best = max(l,r) + root->val;
        int both_waste = root->val;

        maxSum = max({maxSum, below_best, below_one_best, both_waste});

        return max(below_one_best, both_waste);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};