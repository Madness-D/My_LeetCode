/* ************************************************************************
> File Name:		142环形链表II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 15:59:09
> Link:		https://leetcode.cn/problems/linked-list-cycle-ii/
> Description:		给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
*************************************************************************/
/*
与1相比，要求成环则返回环入口结点
    类似的，有哈希集合、快慢指针两种方法
哈希集合很容易理解，不赘述
快慢指针：
    1、首先利用快慢指针，能否相遇，判断是否有环
    2、再设置两个指针，一个从head开始，一个从快慢指针相遇点开始，往前推进（一次一步），则会在环的入口处相遇
证明见：https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
 ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        bool isCycle=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {isCycle=true;break;}
        }
        if(!isCycle) return nullptr;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;

    }
};