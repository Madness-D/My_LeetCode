/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //回顾；层序遍历，队列
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.push(root);

        bool lr = true;//lr 为false，则从右向左
        while (!q.empty()) {
            int size = q.size();//该层的元素数
            vector<int> level(size, 0);//存储该层的元素
            while (size--) {
                //从队列中取出元素，存入数组
                root = q.front(); q.pop();
                level[lr ? level.size() - size - 1 : size] = root->val;

                //下一层，从左到右压入queue
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }

            //std::move并不能移动任何东西，它唯一的功能是将一个左值强制转化为右值引用，继而可以通过右值引用使用该值，以用于移动语义
            //C++ 标准库使用比如vector::push_back 等这类函数时,会对参数的对象进行复制,连数据也会复制.这就会造成对象内存的额外创建, 本来原意是想把参数push_back进去就行了,通过std::move，可以避免不必要的拷贝操作
            //std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能.

            //该层的数组level存入res
            //res.push_back(level);
            res.push_back(move(level));
            lr = !lr;//
        }

        return res;

    }
};
// @lc code=end

