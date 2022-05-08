/* ************************************************************************
> File Name:		24两两交换链表.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-08 23:49:42
> Link:		https://leetcode-cn.com/problems/swap-nodes-in-pairs/
> Description:		给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*************************************************************************/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //迭代
        ListNode* dummy=new ListNode(-1,head);
        ListNode* curr=dummy;
        while(curr->next && curr->next->next ){
            ListNode* t1=curr->next;
            ListNode* t2=curr->next->next->next;

            curr->next=curr->next->next;
            curr->next->next=t1;
            curr->next->next->next=t2;

            curr=curr->next->next;
        }
        return dummy->next;

    }
};