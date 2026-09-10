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
node* fun(TreeNode* root)
{
    struct node* anss = new node(0,0,0);
    if(!root)return anss;
    struct node* le = fun(root->left);
    struct node* ri = fun(root->right);

    anss->sm = le->sm + ri->sm + root->val;
    anss->cnt = le->cnt + ri->cnt + 1;
    anss->ans = le->ans+ri->ans;
    if(anss->sm/anss->cnt == root->val)anss->ans++;
    return anss;
}
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        struct node* anss = fun(root);
        return anss->ans;
    }
};