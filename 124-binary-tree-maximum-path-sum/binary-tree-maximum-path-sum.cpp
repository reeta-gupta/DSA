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
    int nodeSum(TreeNode* root, int &sum){
        if(root == NULL) return 0;
        int leftS = max(0, nodeSum(root->left , sum));
        int rightS = max(0, nodeSum(root->right, sum));
        sum = max(sum, leftS + rightS + root->val);
        return root->val + max(leftS, rightS);

    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        nodeSum(root, sum);
        return sum;
    }
};