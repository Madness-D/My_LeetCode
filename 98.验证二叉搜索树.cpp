/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//递归，左子结点<根<右子结点，不行，反例见示例2
//中序遍历之后，是递增序列
//设计一个辅助函数，fun(root,lower,upper),分别为子树的上界、下界
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &num){
        if(!root) return;
        inOrder(root->left,num);
        num.push_back(root->val);
        inOrder(root->right,num);
    }
    bool func(TreeNode* root,long lower,long upper){//如果用int，会有边界测试无法通过
        if(!root) return true;
        //注意是开区间，==也是false
        else if(root->val<=lower || root->val>=upper) return false;
        else return func(root->left,lower,root->val)&&func(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inOrder(root,nums);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) continue;
            else return false;
        }
        return true;

        //return func(root,LONG_MIN,LONG_MAX);

    }
};
// @lc code=end

