/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        // //👴的递归超时了
        // //然后发现是三元运算符的问题,
        // //如果直接在三元运算符里面用maxDepth(),相当于又嵌套了函数        
        // if(!root) return 0;
        // int temp=0;
        // for(auto node:root->children){
        //     int tt=maxDepth(node);
        //     temp=temp>tt?temp:tt;
        // //    temp=max(temp,maxDepth(node));
        // }
        // return temp+1;
        
        //bfs,用队列来搞层序遍历
        if(!root) return 0;

        queue<Node *> qu;//队列
        qu.push(root);
        int ans = 0;
        while (!qu.empty()) {
            int size = qu.size();
            while (size > 0) {
                Node * node = qu.front();
                qu.pop();
                vector<Node *> children = node->children;
                for (auto child : children) {
                    qu.push(child);
                }
                size--;
            }
            ans++;
        }
        return ans;

    }
};
// @lc code=end

