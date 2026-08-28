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
    int solve(TreeNode* root, int& sum){
        if(root == nullptr) return 0;

        int lh = solve(root->left, sum);
        int rh = solve(root->right, sum);
        sum = max(sum, lh + rh);

        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;        
    }
};