/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* reverseList(ListNode* head) {// 题206的题解，讲链表反转后返回链表
        ListNode* preNode=nullptr;//前驱节点
        ListNode* curr=head;//当前节点
        while(curr!=nullptr){
            ListNode* temp=curr->next;//临时指针，存储下一个节点
            curr->next=preNode;
            preNode=curr;
            curr=temp;
        }
    return preNode;
    }
    void reorderList(ListNode* head) {
        //一个想法，遍历后从中间分开，后半段反转，交错组成新的链
        //如何反转？ 题206
        //如何找到中点？ 快慢指针，快指针走得比满指针快一倍
        if(head==nullptr || head->next==nullptr){
            return ;
        }

        ListNode *fast=head, *slow=head;//快慢指针，slow指向重点
        while(fast->next && fast->next->next){   
            slow = slow->next;
            fast = fast->next->next;
        }

        //只写下面一行的话，会出现栈溢出的问题
        //ListNode *lowpart=reverseList(slow);
        ListNode *lowpart=slow->next;
        slow->next=nullptr;//讲前半段的最后一个的next置为nullptr，否则下一部分的循环可能无法跳出？
        lowpart=reverseList(lowpart);

        //交错插入
        ListNode *curr=head;
        while(curr && lowpart){
            ListNode *curSecond = lowpart;
            lowpart = lowpart->next;
            ListNode *nextCur = curr->next;
            curSecond->next = curr->next;
            curr->next = curSecond;
            curr = nextCur;
        }
        

    }
};
// @lc code=end

