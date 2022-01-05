/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //两个思路,一个是利用哈希表存储旧节点和新的节点,据此更新新节点的next和random指针
    //第二个是,复制时,将新的节点插入在所复制节点的后边;而后遍历更新指针,再遍历将两个链表拆分
    //两者的区别,在于后者不需要额外的空间
    Node* copyRandomList(Node* head) {
        // //方法一.
        // unordered_map<Node*,Node*> mp;
        // Node* curr=head;
        // //第一次遍历,创建新的节点
        // while(curr){
        //     mp[curr]=new Node(curr->val);
        //     curr=curr->next;
        // }
        // //第二次遍历,更新指针
        // curr=head;
        // while(curr){
        //     mp[curr]->next=mp[curr->next];
        //     mp[curr]->random=mp[curr->random];
        //     curr=curr->next;
        // }
        // return mp[head];

        //方法二
        if(!head) return head;
        Node* curr=head;
        //第一次遍历,复制节点
        while(curr){
            Node* newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        //第二次遍历,复制random节点
        curr=head;
        while(curr){
            if(curr->random!=nullptr)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        //第三次遍历,拆分链表
        Node *ans=head->next, *preHead=head;//返回值
        curr=head->next;
        while(curr->next){
            preHead->next=preHead->next->next;
            curr->next=curr->next->next;
            preHead=preHead->next;
            curr=curr->next;
        }
        preHead->next=nullptr;
        return ans;
    }
};
// @lc code=end

