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
struct node{
    int sm,cnt,ans;
};

node fun(TreeNode* root)
{
    int smm = 0;
    int cntt = 0;
    int anss = 0;
    if(!root)return {smm,cntt,anss};

    node le = fun(root->left);
    node ri = fun(root->right);

    smm = le.sm + ri.sm + root->val;
    cntt = le.cnt + ri.cnt + 1;
    anss = le.ans + ri.ans;
    if(smm /cntt == root->val)anss++;

    return {smm,cntt,anss};
}
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        node res = fun(root);
        return res.ans;
    }
};