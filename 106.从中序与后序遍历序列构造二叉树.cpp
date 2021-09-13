/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    int posR;
    unordered_map<int, int> index;
public:
    TreeNode* creat(const vector<int>& pos, const vector<int>& in,int inL,int inR){
    if(inL>inR){
        return nullptr;
    }
    //if(posR<0) return nullptr;

    TreeNode* root=new TreeNode(pos[posR]);//pos序列,最后一个是根
    //root->val=pre[preL];

    //此处是遍历，可以优化
    int k=index[pos[posR]];

    // int k;
    // for(k=inL;k<=inR;k++){
    //     if(in[k]==pos[posR]){//在中序序列中找到根节点
    //         break;
    //     }
    // }

    //int numLeft=k-inL;//左子树节点数

    posR--;
    //
    root->right=creat(pos,in,k+1,inR);
    //左树，先序区间[preL+1,preL+numLeft];中序区间[inL,k-1]
    root->left=creat(pos,in,inL,k-1);

    return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=postorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < len; ++i) {
            index[inorder[i]] = i;
        }
        posR=len-1;

        return creat(postorder,inorder,0,posR);

    }
};
// @lc code=end

