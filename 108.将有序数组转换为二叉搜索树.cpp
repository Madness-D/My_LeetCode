/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
public:
    TreeNode*  helpfun(vector<int>& nums,int l,int r){
       if(l>r) return nullptr;

        int mid=(r+l)/2;//不是r-l
        //int mid=(r+l+1)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helpfun(nums,l,mid-1);
        root->right=helpfun(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //二叉搜索树，左子树<根<右子树
        //平衡二叉树：左右子树高度差不超过1
        //二叉搜索树的中序遍历是升序排列的

        

        ////naive
        // int len=nums.size();
        // int mid=len/2;
        // TreeNode* root=new TreeNode(nums[mid]);
        // TreeNode* curr=root;
        // while(mid--){
        //     curr->left= new TreeNode(nums[mid]);
        //     curr=curr->left;
        // }
        // curr=root;
        // for(int i=len/2+1;i<len;i++){
        //     curr->right=new TreeNode(nums[i]);
        //     curr=curr->right;
        // }
        // return root;

        return helpfun(nums,0,nums.size()-1);

    }
};
// @lc code=end

