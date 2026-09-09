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
    unordered_map<int, int> hash;
    int idx = 0;

    TreeNode *solve(vector<int> preorder, int i, int j){
        if(i>j) return nullptr;
        if(idx >= preorder.size()) return nullptr;
        int root_val = preorder[idx++];

        TreeNode* root = new TreeNode(root_val);
        root->left = solve(preorder, i, hash[root_val]-1);
        root->right = solve(preorder, hash[root_val]+1, j);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for(int i=0; i<inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size()-1);
    }
};