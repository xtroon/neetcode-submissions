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
    bool check(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr){
            return p == q;
        }
        
        bool lh = check(p->left, q->left);
        bool rh = check(p->right, q->right);

        return lh && rh && p->val == q->val;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};