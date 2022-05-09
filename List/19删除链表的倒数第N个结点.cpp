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
        // //两个指针，fast比slow提前n个结点，
        // //则fast到达倒数第2个结点时slow即为要删除的结点的前一个结点
        // ListNode* dummy=new ListNode(-1,head);//设置dummy结点
        // ListNode* fast=dummy;
        // while(n-- && fast){
        //     fast=fast->next;
        // }
        // ListNode* slow=dummy;

        // while(fast->next){
        //     fast=fast->next;
        //     slow=slow->next;
        // }
        
        // if(slow->next)slow->next=slow->next->next;
        // return dummy->next;

        //栈
        ListNode * dummy=new ListNode(-1,head);
        ListNode* curr=dummy;
        stack<ListNode*> st;
        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        while(n--){
            st.pop();
        }
        st.top()->next=st.top()->next->next;
        return dummy->next;
    }
};