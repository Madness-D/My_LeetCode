/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL||k==0) return head;

        //最简单的想法, 存到数组里处理后再组成链表
        //或者,遍历一遍,知道元素个数为n,之后将第n-k个节点的next置为null,将第n个节点的next置为头节点

        ListNode* curr=head;
        int len=1;
        while(curr->next){
            len++;
            curr=curr->next;
        }//这时,curr为最后一个节点

        curr->next=head;//原来的最后一位,next指向头部

        k=k%len;//给出的k可能>len
        int pos=len-k;
        while(pos--){
            curr=curr->next;
        }
        ListNode* newHead=curr->next;
        curr->next=nullptr;
        return newHead;
    }
};
// @lc code=end

