/* ************************************************************************
> File Name:		19删除链表的倒数第N个结点.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 11:18:40
> Link:		https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
> Description:		给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1,head);
        ListNode* fast=dummy;
        while(n-- && fast){
            fast=fast->next;
        }
        ListNode* slow=dummy;

        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        
        if(slow->next)slow->next=slow->next->next;
        return dummy->next;
    }
};