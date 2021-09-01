/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 * 
 
 */

// @lc code=start
/**
 * 
 * 第一种方法，获取链表长度
 * 为什么单独写一个函数？否则会改变head指向，导致后续出错
 * 
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
    int getLen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getLen(head);
       
        ListNode* dummy=new ListNode(0,head);
        ListNode* p=dummy;
        for(int i=1;i<len-n+1;i++){
            p=p->next;
        }
        p->next=p->next->next;
        //delete p;
        return dummy->next;
    }
};
// @lc code=end

