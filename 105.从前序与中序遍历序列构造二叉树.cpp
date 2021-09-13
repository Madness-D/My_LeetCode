/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
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
private:
    unordered_map<int, int> index;
public:
    TreeNode* creat(const vector<int>& pre, const vector<int>& in,int preL,int preR,int inL,int inR){
    if(preL>preR){
        return nullptr;
    }

    TreeNode* root=new TreeNode(pre[preL]);//pre序列,根
    //root->val=pre[preL];

    //此处是遍历，可以优化
    int k=index[pre[preL]];
    // for(k=inL;k<=inR;k++){
    //     if(in[k]==pre[preL]){//在中序序列中找到根节点
    //         break;
    //     }
    // }

    int numLeft=k-inL;//左子树节点数

    //左树，先序区间[preL+1,preL+numLeft];中序区间[inL,k-1]
    root->left=creat(pre,in,preL+1,preL+numLeft,inL,k-1);
    //
    root->right=creat(pre,in,preL+numLeft+1,preR,k+1,inR);

    return root;

}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //主要思想，前序或后序提供根节点信息，中序据此划分左右子树
        //递归，如示例中的例子，根节点为9，则[3]和[3]构造左子树,[20,15,7]和[15,20,7]构造右子树
        int len=preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < len; ++i) {
            index[inorder[i]] = i;
        }
        return creat(preorder,inorder,0,len-1,0,len-1);


    }
};
// @lc code=end

