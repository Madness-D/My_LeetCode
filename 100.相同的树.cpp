/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
   // int flag;
public:
    // void  comp(TreeNode* root1,TreeNode* root2){
    // if (root1 != NULL && root2 != NULL)
    // {
    //     if (root1->val != root2->val)
    //     {
    //         flag = 0;
    //         return;
    //     }
    //     else
    //     {
    //         comp(root1->left, root2->left);
    //         comp(root1->right, root2->right);
    //     }
    // }
    // else if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    // {
    //     flag = 0;
    //     return;
    // }
    // }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // flag=1;
        // comp(p,q);
        // if(flag) return true;
        // else return false;

        //DFS
        if(!p && !q){//到达边界，都是null
            return true;
        }else if(!p || !q){//一个null，另一个不是
            return false;
        }else if(p->val!=q->val){
            return false;
        }else{
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }


    }
};
// @lc code=end

