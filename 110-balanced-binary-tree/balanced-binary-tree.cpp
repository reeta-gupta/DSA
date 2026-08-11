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
    int findHeight(TreeNode* root){
        if(root == NULL) return 0;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lh = findHeight(root -> left);
        int rh = findHeight(root -> right);

        if(abs(rh - lh) > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;
        return true; 
        
    }
};