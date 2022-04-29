/* ************************************************************************
> File Name:		203移除链表元素.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-04-29 22:52:21
> Link:		https://leetcode-cn.com/problems/remove-linked-list-elements/
> Description:	给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。	
/*************************************************************************

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1,head);//哨兵节点
        ListNode* curr=dummy;
        while(curr && curr->next){//因为后面是curr->next->val判断是否要删除
            if(curr->next->val==val) curr->next=curr->next->next;
            else curr=curr->next;
        }
        return dummy->next;
    }
};