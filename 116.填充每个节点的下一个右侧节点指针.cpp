/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//思路，层序遍历，queue，BFS
//如何判断是否到达每层边界？设置一个layer记录层数，每层结点数为2^i个？
//不太行，用queue的size
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){return root;}

         //层序遍历
        queue<Node*> qu;
        qu.push(root);
       // int layer=0;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
            Node* curr=qu.front();
            qu.pop();
            if(i<size-1){
            //Node* nex=qu.front();
            curr->next=qu.front();
            }
            
            //if(i==pow(2,i)-1){curr->next=nullptr;}

            if(curr->left!=nullptr){
            qu.push(curr->left);
            qu.push(curr->right);
            }
            //layer++;
            }
            
        }
        return root;


    // //利用已经建立的next指针
    //  // 从根节点开始
    //     Node* leftmost = root;
        
    //     while (leftmost->left != nullptr) {
            
    //         // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
    //         Node* head = leftmost;
            
    //         while (head != nullptr) {
    //             //第一种情况，两个结点具有公共父节点
    //             // CONNECTION 1
    //             head->left->next = head->right;
    //             //第二种情况，两个结点的父节点是兄弟节点
    //             // CONNECTION 2
    //             if (head->next != nullptr) {
    //                 head->right->next = head->next->left;
    //             }
                
    //             // 指针向后移动
    //             head = head->next;
    //         }
            
    //         // 去下一层的最左的节点
    //         leftmost = leftmost->left;
    //     }

    //     return root;
        
    }
};
// @lc code=end

