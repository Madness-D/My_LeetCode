/* ************************************************************************
> File Name:		141环形链表.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 15:05:52
> Link:		https://leetcode.cn/problems/linked-list-cycle/
> Description:		给你一个链表的头节点 head ，判断链表中是否有环。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //快慢指针
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;

        // //set
        // unordered_set<ListNode* > st;
        // ListNode* curr=head;
        // while(curr){
        //     if(st.count(curr)) return true;
        //     else{
        //         st.insert(curr);
        //         curr=curr->next;
        //     }
        // }
        // return false;
    }
};