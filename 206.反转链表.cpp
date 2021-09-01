/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode=nullptr;//前驱节点
        ListNode* curr=head;//当前节点
        while(curr!=nullptr){
            ListNode* temp=curr->next;//临时指针，存储下一个节点
            curr->next=preNode;
            preNode=curr;
            curr=temp;
        }
    return preNode;

    //新建链表，逆向赋值
    // ListNode* ans = nullptr;
    // for (ListNode* x = head; x != nullptr; x = x->next) {
    //     ans = new ListNode(x->val,ans);
    // }
    // return ans;

    //递归
    // if (!head || !head->next) {
    //     return head;
    // }
    // ListNode* newHead = reverseList(head->next);
    // head->next->next = head;
    // head->next = nullptr;
    // return newHead;

    }
};
// @lc code=end

