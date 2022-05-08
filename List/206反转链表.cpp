/* ************************************************************************
> File Name:		206反转链表.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-03 23:19:48
> Link:		https://leetcode-cn.com/problems/reverse-linked-list/
> Description:		给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
/*************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // //递归
        // if(!head || !head->next) return head;
        // ListNode* newHead=reverseList(head->next);
        // head->next->next=head;
        // head->next=nullptr;//避免成环
        // return newHead;

        //迭代，事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;//此时cur为null，pre为末尾节点//头节点
        
    }
};

