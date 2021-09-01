/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //如果p、q分别在root两侧，则root是最近公共祖先
        while((root->val-p->val)*(root->val-q->val)>0)
            root=p->val<root->val?root->left:root->right;
        return root;
        
        ////递归
        // if((root->val-p->val)*(root->val-q->val)<=0)
        //     return root;
        // return lowestCommonAncestor(p->val<root->val?root->left:root->right,p,q);

        ////上面两个都利用BST的性质了，进行左右子树的选择
        // if (root == nullptr || root == p || root == q)
        //     return root;
        // TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // //如果left为空，说明这两个节点在root结点的右子树上，我们只需要返回右子树查找的结果即可
        // if (left == nullptr)
        //     return right;
        // //同上
        // if (right == nullptr)
        //     return left;
        // //如果left和right都不为空，说明这两个节点一个在root的左子树上一个在root的右子树上，
        // //我们只需要返回root结点即可。
        // return root;

    }
};
// @lc code=end

