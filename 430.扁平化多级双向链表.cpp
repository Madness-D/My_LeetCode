/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node *now){
        if(now == NULL) return NULL;
        Node* ans = NULL;
        if(now->child){
            Node *t1 = now->child;
            Node *t2 = dfs(now->child);
            Node *t3 = now->next;
            now->child = NULL;
            now->next = t1;
            t1->prev = now;
            t2->next = t3;
            if(t3 == NULL) return t2;
            t3->prev = t2;
            ans = dfs(t3);
        }
        else{
            if(now->next == NULL) return now;
            ans = dfs(now->next);
        }
        return ans;
    }
  
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    // Node* fun(Node* curr){
    //     if(curr==nullptr) return nullptr;
    //     Node* ans=nullptr;
    //     if(curr->child){//如果有子节点
    //         Node* t1=curr->child;
    //         Node* t2=fun(curr->next);
    //         Node *t3=curr->next;
    //         curr->child=nullptr;
    //         curr->next=t1;
    //         t1->prev=curr;
    //         t2->next=t3;
    //         if(t3==nullptr) return t2;
    //         t3->prev=t2;
    //         ans=fun(t3);
    //     }else{
    //         if(curr->next==nullptr) return curr;
    //         ans=fun(curr->next);
    //     }
    //     return ans;
    // }

    // Node* flatten(Node* head) {
    //     //如果有子节点，则将next置为child
    //     fun(head);
    //     return head;
        
    // }
};
// @lc code=end

