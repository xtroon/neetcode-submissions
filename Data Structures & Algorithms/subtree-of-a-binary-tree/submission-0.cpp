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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot == nullptr)
            return root == subRoot;
    
        return root->val==subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr)
            return root == subRoot;
        
        if(isSame(root, subRoot)){
            return true;
        }

        bool lh = isSubtree(root->left, subRoot);
        bool rh = isSubtree(root->right, subRoot);

        return lh || rh;
    }
};